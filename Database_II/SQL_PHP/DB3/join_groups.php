<?php
    include 'db_connect.php';

    // Get the student_id and group_id from the POST request
    $student_id = $_POST["userId"];
    $group_id = $_POST["groupId"];


    $sql = "INSERT INTO member_of (group_id, student_id) VALUES (?, ?)";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ii", $group_id, $student_id);

    if ($stmt->execute()) {
        echo json_encode(array("success" => true));
    } else {
        echo json_encode(array("success" => false, "error" => $conn->error));
    }

    $stmt->close();
    $conn->close();
?>
