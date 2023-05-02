<?php
error_reporting(E_ALL);

$host = 'localhost';
$username = 'root';
$password = '';
$database = 'DB3';

// Create connection and check connection
$conn = mysqli_connect($host, $username, $password, $database);
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}
// echo "Connected successfully<br>";
?>