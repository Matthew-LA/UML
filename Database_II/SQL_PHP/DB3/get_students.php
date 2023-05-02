<?php
include 'db_connect.php';

$meetingId = $_POST["meetingId"];

$result = $conn->query("SELECT enroll.student_id, users.id, users.name, users.email FROM enroll JOIN users ON enroll.student_id = users.id WHERE enroll.meeting_id = $meetingId");

$response = array();
$response["success"] = false;

if ($result->num_rows > 0) {
    $response["success"] = true;
    $response["students"] = array();

    while ($row = $result->fetch_assoc()) {
        $student = array();
        $student["user_id"] = $row["id"];
        $student["name"] = $row["name"];
        $student["email"] = $row["email"];
        array_push($response["students"], $student);
    }
}

echo json_encode($response);
$conn->close();
?>
