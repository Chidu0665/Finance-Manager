<?php
// configuration
include('connect.php');

// new data
$date = $_POST['date'];
$mode = $_POST['mode'];
$desc = $_POST['desc'];
$type = $_POST['type'];
$status = $_POST['status'];
$id = $_POST['memids'];
$dateo = $_POST['dateo'];
$rb = $_POST['rb'];
$ft = $_POST['ft'];
// query
$sql = "UPDATE transaction 
        SET date=?, mode=?, description=?, type=?, status=?, time=?, receive_by=?, ft=?
		WHERE id=?";
$q = $db->prepare($sql);
$q->execute(array($date,$mode,$desc,$type,$status,$dateo,$rb,$ft,$id));
header("location: index.php");

?>