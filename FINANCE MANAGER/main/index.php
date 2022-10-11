<style>
body {
	background: #00cc66;
}
table { border-collapse: separate; background-color: #FFFFFF; border-spacing: 0; width: 85%; color: #666666; text-shadow: 0 1px 0 #FFFFFF; border: 1px solid #CCCCCC; box-shadow: 0; margin: 0 auto;font-family: arial; }
table thead tr th { background: none repeat scroll 0 0 #EEEEEE; color: #222222; padding: 10px 14px; text-align: left; border-top: 0 none; font-size: 12px; }
table tbody tr td{
    background-color: #FFFFFF;
	font-size: 12px;
    text-align: left;
	padding: 10px 14px;
	border-top: 1px solid #DDDDDD;
}
#log {
	width: 85%;
	text-align: right;
	margin: 20px auto;
	font-family: arial;
}
#log a {
	color: #FFFFFF;
	text-decoration: none;
	font-family: arial;
}
#formdesign {
	background: linear-gradient(to bottom, #FFFFFF 0%, #F6F6F6 100%) repeat scroll 0 0 rgba(0, 0, 0, 0);
    border: 1px solid #D5D5D5;
    padding: 12px;
    position: relative;
	margin: 20px auto;
	width: 83%;
	clear: both;
	height: 34px;
}
#filter {
	-moz-box-sizing: border-box;
    background: url("img/big_search.png") no-repeat scroll 10px 10px #FFFFFF;
    box-shadow: none;
    display: block;
    font-size: 12px;
    height: 34px;
    padding: 9px 140px 9px 28px;display: block;
    font-size: 12px;
    height: 34px;
    padding: 9px 140px 9px 28px;
    width: 85%;
	border: 1px solid #DADADA;
    transition: border 0.2s linear 0s, box-shadow 0.2s linear 0s;
	padding-top: 6px;
	float: left;
}
#add {
	float: right;
	width: 8.5%;
	display: block;
    font-size: 12px;
    height: 14px;
    padding: 9px 28px 9px 28px;
	border: 1px solid #DADADA;
}
a#add {
	text-decoration: none;
	color: #666666;
	font-family: arial;
	font-size: 12px;
}

</style>
<script src="argiepolicarpio.js" type="text/javascript" charset="utf-8"></script>
<script src="js/application.js" type="text/javascript" charset="utf-8"></script>
<!--sa poip up-->
<link href="src/facebox.css" media="screen" rel="stylesheet" type="text/css" />
   <script src="lib/jquery.js" type="text/javascript"></script>
  <script src="src/facebox.js" type="text/javascript"></script>
  <script type="text/javascript">
    jQuery(document).ready(function($) {
      $('a[rel*=facebox]').facebox({
        loadingImage : 'src/loading.gif',
        closeImage   : 'src/closelabel.png'
      })
    })
  </script>
<div id="log">
Home | <a href="categories.php">Type of Transaction</a> | <a href="doctype.php">Mode of Transaction</a> | <a href="../index.php">Logout</a>
</div>
<div id="formdesign">
<input type="text" name="filter" value="" id="filter" placeholder="Search Transaction..." autocomplete="off" />
<a rel="facebox" href="add.php" id="add">Add Transaction</a>
</div>

<hr>
<form action="datesearch.php" method="POST" style="margin-left: 30%">
From Date
<input type="text" name="from" />
To Date
<input type="text" name="to" />
<input type="submit" value="Search" />
</form>

<form action="monthlytransaction.php" style="margin-left: 45%">
	<input type="submit" value="Monthly Transaction" >
</form>

<table cellspacing="0" cellpadding="2" id="resultTable">
<thead>
	<tr>
		<th width="5%"> Date of Transaction</th>
		<th width="7%"> Time</th>
		<th width="10%"> Paid To/Recieved From</th>
		<th width="10%"> Mode of Transaction </th>
		<th width="23%"> Comments </th>
		<th width="10%"> Type of Transaction </th>
		<th width="5%"> Transaction Status </th>
		<th width="10%"> Amount </th>
		<th width="10%"> Action </th>
	</tr>
</thead>
<tbody>
	<?php
		include('connect.php');		
		$result = $db->prepare("SELECT * FROM transaction ORDER BY id DESC");
		$result->execute();
		for($i=0; $row = $result->fetch(); $i++){
	?>
	<tr class="record">
		<td><?php echo $row['date']; ?></td>
		<td><?php echo $row['time']; ?></td>
		<td><?php echo $row['receive_by']; ?></td>
		<td><?php echo $row['mode']; ?></td>
		<td><?php echo $row['description']; ?></td>
		<td><?php echo $row['type']; ?></td>
		<td><?php echo $row['status']; ?></td>
		<td><?php echo $row['ft']; ?></td>
		<td><a rel="facebox" href="editform.php?id=<?php echo $row['id']; ?>"> Edit </a> | <a href="#" id="<?php echo $row['id']; ?>" class="delbutton" title="Click To Delete">Delete</a></td>
	</tr>
	<?php
		}
	?>

	<tr class="record">
		<td><?php echo $row['date']; ?></td>
		<td><?php echo $row['time']; ?></td>
		<td><?php echo $row['receive_by']; ?></td>
		<td><?php echo $row['mode']; ?></td>
		<td><?php echo $row['description']; ?></td>
		<td><?php echo $row['type']; ?></td>
		<td>...TOTAL..:</td>
		<?php
		include('connect.php');		
		$result = $db->prepare("SELECT SUM(ft) as total FROM transaction");
		// $result = $db->prepare("SELECT * FROM mode ORDER BY id DESC");
		$result->execute();
		for($i=0; $row = $result->fetch(); $i++){
		//echo '<p class="record">'.$row['total'].'</p>';
		echo '<td>'.$row['total'].'</td>';
		}
		?>
</tbody>
</table>
<h2><marquee>Spend Your Money Wisely!!</marquee></h2>
<script src="js/jquery.js"></script>
  <script type="text/javascript">
$(function() {


$(".delbutton").click(function(){

//Save the link in a variable called element
var element = $(this);

//Find the id of the link that was clicked
var del_id = element.attr("id");

//Built a url to send
var info = 'id=' + del_id;
 if(confirm("Sure you want to delete this update? There is NO undo!"))
		  {

 $.ajax({
   type: "GET",
   url: "delete.php",
   data: info,
   success: function(){
   
   }
 });
         $(this).parents(".record").animate({ backgroundColor: "#fbc7c7" }, "fast")
		.animate({ opacity: "hide" }, "slow");

 }

return false;

});

});
</script>