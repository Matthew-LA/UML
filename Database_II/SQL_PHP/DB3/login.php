<?php
    include 'db_connect.php';

    $email = $_POST['email'];
    $password = $_POST['password'];

    $query = "SELECT *
              FROM users
              WHERE email = '$email' AND password = '$password'";

    $result = mysqli_query($conn, $query);

    if (mysqli_num_rows($result) == 1) {
        $row = mysqli_fetch_assoc($result);
        $response["id"] = $row['id'];
        $id = $row['id'];
        $response["role"] = $row['role'];

        if ($row['role'] == "parent") {
            $child_q  = "SELECT student_id
                        FROM child_of
                        WHERE parent_id = '$id'";
            $get_child = mysqli_query($conn, $child_q);
            if (mysqli_num_rows($get_child) == 1) {
                $child = mysqli_fetch_assoc($get_child);
                $response["childId"] = $child['student_id'];
            } else {
                $response["success"] = "false";
                echo json_encode($response);
            }
        }

        if ($row['role'] == "student") {
            $grade_q  = "SELECT grade
                         FROM students
                         WHERE student_id = '$id'";
            $get_grade = mysqli_query($conn, $grade_q);
            if (mysqli_num_rows($get_grade) == 1) {
                $grade = mysqli_fetch_assoc($get_grade);
                $response["grade"] = $grade['grade'];
            } else {
                $response["success"] = "false";
                echo json_encode($response);
            }
        }
        $response["success"] = "true";
        echo json_encode($response);
    } else {
        $response["success"] = "false";
        echo json_encode($response);
    }
?>
