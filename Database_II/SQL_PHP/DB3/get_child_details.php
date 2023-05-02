<?php
    include 'db_connect.php';

    $parent_id = $_POST["id"];

    $child_q  = "SELECT student_id
                    FROM child_of
                    WHERE parent_id = '$parent_id'";

    $get_child = mysqli_query($conn, $child_q);
    if (mysqli_num_rows($get_child) == 1) {
        $child = mysqli_fetch_assoc($result);
        $response["childId"] = $child['student_id'];
    } else {
        $response["success"] = "false";
        echo json_encode($response);
    }
    mysqli_close($conn);
?>
