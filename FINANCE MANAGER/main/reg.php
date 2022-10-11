<?php
include('connect.php');	

$date = $_POST['date'];
$mode = $_POST['mode'];
$desc = $_POST['desc'];
$type = $_POST['type'];
$status = $_POST['status'];
$dateo = $_POST['dateo'];
$rb = $_POST['rb'];
$ft = $_POST['ft'];

// query
$sql = "INSERT INTO transaction (date,mode,description,type,status,time,receive_by,ft) VALUES (:sas,:asas,:asafs,:offff,:statttt,:dot,:rd,:ft)";
$q = $db->prepare($sql);
$q->execute(array(':sas'=>$date,':asas'=>$mode,':asafs'=>$desc,':offff'=>$type,':statttt'=>$status,':dot'=>$dateo,':rd'=>$rb,':ft'=>$ft));
header("location: index.php");


?>