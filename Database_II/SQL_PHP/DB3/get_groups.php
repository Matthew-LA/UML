<?php
    include 'db_connect.php';

    // Get the student_id from the POST request
    $student_id = $_POST["userId"];
    $grade = $_POST["grade"];

    $sql = "SELECT group_id, group_name, description, grade_req FROM groups WHERE grade_req =? AND group_id NOT IN (SELECT group_id FROM member_of WHERE student_id =?)";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ii", $grade, $student_id);
    $stmt->execute();
    $result = $stmt->get_result();

    if ($result->num_rows > 0) {
        $response = array();
        $response["success"] = true;
        $response["groups"] = array();

        // Output data of each row
        while($row = $result->fetch_assoc()) {
            $group = array();
            $group["group_id"] = $row["group_id"];
            $group["name"] = $row["group_name"];
            $group["description"] = $row["description"];

            array_push($response["groups"], $group);
        }

        echo json_encode($response);
    } else {
        echo json_encode(array("success" => false));
    }

    $stmt->close();
    $conn->close();
?>
