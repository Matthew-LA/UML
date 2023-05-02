<?php
    include 'db_connect.php';

    $email = $_POST["email"];
    $name = $_POST["name"];
    $password = $_POST["password"];
    $phone = $_POST["phone"];
    $userId = $_POST["userId"];

    $statement = mysqli_prepare($conn, "UPDATE users SET email=?, name=?, password=?, phone=? WHERE id=?");
    mysqli_stmt_bind_param($statement, "ssssi", $email, $name, $password, $phone, $userId);
    $result = mysqli_stmt_execute($statement);

    $response = array();
    $response["success"] = false;

    if ($result) {
        $response["success"] = true;
    }


    echo json_encode($response);
?>
