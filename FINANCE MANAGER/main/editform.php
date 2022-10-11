<?php
	include('connect.php');
	$id=$_GET['id'];
	$result = $db->prepare("SELECT * FROM transaction WHERE id= :userid");
	$result->bindParam(':userid', $id);
	$result->execute();
	for($i=0; $rows = $result->fetch(); $i++){
?>
<form action="edit.php" method="POST">
<input type="hidden" name="memids" value="<?php echo $id; ?>" />
Date of Transaction<br>
<input type="text" name="date" value="<?php echo $rows['date']; ?>" /><br><br>
Time<br>
<input type="text" name="dateo" value="<?php echo $rows['time']; ?>" /><br><br>
Paid To/Recieved From<br>
<input type="text" name="rb" value="<?php echo $rows['receive_by']; ?>" /><br><br>
Mode of Transaction<br>
<select name="mode" class="ed">
	<?php
	echo '<option value="'.$rows['mode'].'">'.$rows['mode'].'</option>';
	include('connect.php');		
		$result = $db->prepare("SELECT * FROM mode ORDER BY id DESC");
		$result->execute();
		for($i=0; $row = $result->fetch(); $i++){
		echo '<option value="'.$row[name].'">'.$row[name].'</option>';
		}
	?>
</select><br /><br>
Comments<br>
<textarea name="desc"><?php echo $rows['description']; ?></textarea><br><br>
Type of Transaction<br>
<select name="type" class="ed">
	<?php
	echo '<option value="'.$rows['type'].'">'.$rows['type'].'</option>';
	include('connect.php');		
		$result = $db->prepare("SELECT * FROM categories ORDER BY id DESC");
		$result->execute();
		for($i=0; $row = $result->fetch(); $i++){
		echo '<option value="'.$row[name].'">'.$row[name].'</option>';
		}
	?>
</select><br /><br>
Transaction Status<br>
<input type="text" name="status" value="<?php echo $rows['status']; ?>" /><br><br>
Amount<br>
<input type="text" name="ft" value="<?php echo $rows['ft']; ?>" /><br><br>
<input type="submit" value="Save" />
</form>
<?php
	}
?>