<?php
include('connect.php');	

$typename = $_POST['typename'];

// query
$sql = "INSERT INTO categories (name) VALUES (:sas)";
$q = $db->prepare($sql);
$q->execute(array(':sas'=>$typename));
header("location: categories.php");


?>