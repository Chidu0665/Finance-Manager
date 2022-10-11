<?php
include('connect.php');	

$username = $_POST['uname'];
$password = $_POST['pword'];

// query
$sql = "INSERT INTO user (username,password) VALUES (:sas,:asas)";
$q = $db->prepare($sql);
$q->execute(array(':sas'=>$username,':asas'=>$password));
header("location: index.php");


?>