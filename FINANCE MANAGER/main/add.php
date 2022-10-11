
<form action="reg.php" method="POST">
Date of Transaction<br>
<input type="text" name="date" /><br><br>
Time<br>
<input type="text" name="dateo" /><br><br>
Paid To/Recieved From<br>
<input type="text" name="rb" /><br><br>
Mode of Transaction<br>
<select name="mode" class="ed">
	<?php
	include('connect.php');		
		$result = $db->prepare("SELECT * FROM mode ORDER BY id DESC");
		$result->execute();
		for($i=0; $row = $result->fetch(); $i++){
		echo '<option value="'.$row[name].'">'.$row[name].'</option>';
		}
	?>
</select><br /><br>
Comments<br>
<textarea name="desc"></textarea><br><br>
Type of Transaction<br>
<select name="type" class="ed">
	<?php
	include('connect.php');		
		$result = $db->prepare("SELECT * FROM categories ORDER BY id DESC");
		$result->execute();
		for($i=0; $row = $result->fetch(); $i++){
		echo '<option value="'.$row[name].'">'.$row[name].'</option>';
		}
	?>
</select><br /><br>
Transaction Status<br>
<input type="text" name="status" /><br><br>
Amount<br>
<input type="text" name="ft" /><br><br>
<input type="submit" value="Save" />
</form>