<?php
include 'db_connect.php';

$userId = $_POST["userId"];
$meetingId = $_POST["meetingId"];

$result = $conn->query("DELETE FROM enroll WHERE student_id = $userId AND meeting_id = $meetingId");

$response = array();
$response["success"] = false;

if ($result) {
    $response["success"] = true;
}

echo json_encode($response);
$conn->close();
?>
