<?php
include 'db_connect.php';

$student_id = $_POST['userId'];

    $sql = "SELECT g.group_name AS group_name, m.title, m.author, m.type, m.url, m.notes, m.assigned_date, mt.meeting_name
            FROM enroll e
            INNER JOIN meetings mt ON mt.meeting_id = e.meeting_id
            INNER JOIN groups g ON g.group_id = mt.group_id
            INNER JOIN material m ON m.meeting_id = mt.meeting_id
            WHERE e.student_id = $student_id";

    $result = mysqli_query($conn, $sql);

    if (mysqli_num_rows($result) > 0) {
        $meet_mats = array();
        while ($row = mysqli_fetch_assoc($result)) {
            $meet_mats[] = $row;
        }
        echo json_encode(array("success" => true, "meet_mats" => $meet_mats));
    } else {
        echo json_encode(array("success" => false));
    }

    mysqli_close($conn);
?>
