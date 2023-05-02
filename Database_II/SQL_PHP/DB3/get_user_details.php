<?php
    include 'db_connect.php';

    $userId = $_POST["userId"];

    $response = array();

    $sql = "SELECT users.email, users.name, users.password, users.phone
            FROM users
            WHERE users.id = ?";

    if ($stmt = $conn->prepare($sql)) {
        $stmt->bind_param("i", $userId);
        $stmt->execute();
        $stmt->store_result();
        $stmt->bind_result($email, $name, $password, $phone);

        if ($stmt->fetch()) {
            $response["success"] = true;
            $response["email"] = $email;
            $response["name"] = $name;
            $response["password"] = $password;
            $response["phone"] = $phone;
        } else {
            $response["success"] = false;
        }
        $stmt->close();
    } else {
        $response["success"] = false;
    }

    echo json_encode($response);
    mysqli_close($conn);
?>
