<?php
include 'db_connect.php';

$userId = $_POST["userId"];
$meetingId = $_POST["meetingId"];

$result = $conn->query("INSERT INTO enroll (meeting_id, student_id) VALUES ($meetingId, $userId)");

$response = array();
$response["success"] = false;

if ($result) {
    $response["success"] = true;
}

echo json_encode($response);
$conn->close();
?>
