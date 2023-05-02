<?php
include 'db_connect.php';

$userId = $_POST["userId"];

// Get the current date
$current_date = date('Y-m-d');

$sql = "SELECT m.*, t.*, IF(e.student_id IS NULL, 0, 1) as enrolled
        FROM meetings m
        INNER JOIN time_slot t ON m.time_slot_id = t.time_slot_id
        LEFT JOIN enroll e ON m.meeting_id = e.meeting_id AND e.student_id = ?
        WHERE m.group_id IN (SELECT group_id FROM member_of WHERE student_id = ?)";

$stmt = $conn->prepare($sql);
$stmt->bind_param("ii", $userId, $userId);
$stmt->execute();
$result = $stmt->get_result();

$response = array();
$response["success"] = false;

if ($result->num_rows > 0) {
    $response["success"] = true;
    $response["meetings"] = array();

    while ($row = $result->fetch_assoc()) {
        $meeting = array();
        if (date('w') <= 4 && $row["date"] > $current_date){
            $meeting["meetingId"] = $row["meeting_id"];
            $meeting["name"] = $row["meeting_name"];
            $meeting["date"] = $row["date"];
            $meeting["start_time"] = $row["start_time"];
            $meeting["end_time"] = $row["end_time"];
            $meeting["enrolled"] = $row["enrolled"];
            array_push($response["meetings"], $meeting);
        }

    }
}

echo json_encode($response);
$conn->close();
?>
