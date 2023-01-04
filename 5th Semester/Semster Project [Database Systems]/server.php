<?php
session_start();

// initializing variables

$roll_no = "";
$cnic = "";
$first_name = "";
$last_name = "";

$hostel_id = "";
$student_rep = "";
$phone_no = "";
$guardian_name = "";
$address = "";
$password_1 = "";
$password_2 = "";
$room_no="";

$errors = array();

// connect to the database
$db = mysqli_connect('localhost', 'root', '', 'project');

// REGISTER USER
if (isset($_POST['reg_user'])) {
  // receive all input values from the form
  $roll_no = mysqli_real_escape_string($db, $_POST['roll_no']);
  $cnic = mysqli_real_escape_string($db, $_POST['cnic']);
  $first_name = mysqli_real_escape_string($db, $_POST['first_name']);
  $last_name = mysqli_real_escape_string($db, $_POST['last_name']);
  $student_rep = mysqli_real_escape_string($db, $_POST['student_rep']);
  $phone_no = mysqli_real_escape_string($db, $_POST['phone_no']);
  $room_no = mysqli_real_escape_string($db, $_POST['room_no']);
  $guardian_name = mysqli_real_escape_string($db, $_POST['guardian_name']);
  $address = mysqli_real_escape_string($db, $_POST['address']);
  $password_1 = mysqli_real_escape_string($db, $_POST['password_1']);
  $password_2 = mysqli_real_escape_string($db, $_POST['password_2']);

  // form validation: ensure that the form is correctly filled ...
  // by adding (array_push()) corresponding error unto $errors array
  if (empty($roll_no)) { array_push($errors, "Roll No is required"); }
  if (empty($password_1)) { array_push($errors, "Password is required"); }
  if ($password_1 != $password_2) {
	array_push($errors, "The two passwords do not match");
  }

  // first check the database to make sure
  // a user does not already exist with the same username and/or email
  $user_check_query = "SELECT * FROM student_details WHERE roll_no='$roll_no' OR cnic='$cnic' LIMIT 1";
  $result = mysqli_query($db, $user_check_query);
  $user = mysqli_fetch_assoc($result);

  if ($user) { // if user exists
    if ($user['roll_no'] === $roll_no) {
      array_push($errors, "Roll No already exists");
    }

    if ($user['cnic'] === $cnic) {
      array_push($errors, "CNIC already exists");
    }
  }

  // Finally, register user if there are no errors in the form
  if (count($errors) == 0) {
  	$password = md5($password_1);//encrypt the password before saving in the database
    $hostel_id = $_SESSION['hostel_id'];
    $max_room="SELECT total_rooms from hostel_details where hostel_id='$hostel_id';";
    $max_room = mysqli_query($db,$max_room);
    $max_room= $max_room->fetch_object()->total_rooms;
    //CALL `check_room_no`(@p0, @p1, @p2, @p3);
    $procode_query="CALL `check_room_no`('$max_room','$roll_no','$cnic','$first_name', '$last_name', '$hostel_id', '$room_no', '$student_rep', '$phone_no', '$guardian_name', '$address', '$password');";
    mysqli_query($db,$procode_query);
    if(mysqli_affected_rows($db) > 1) {
      echo "SUCCESS!";
    }
    else {
      echo "Error!";
    }

  }
}

// LOGIN USER
if (isset($_POST['login_user'])) {
  echo "Testing1";
  $username = mysqli_real_escape_string($db, $_POST['username']);
  $password = mysqli_real_escape_string($db, $_POST['password']);

  if (empty($username)) {
  	array_push($errors, "Username is required");
  }
  if (empty($password)) {
  	array_push($errors, "Password is required");
  }

  if (count($errors) == 0) {
  	$password = md5($password);
  	$query = "SELECT * FROM student_details WHERE roll_no='$username' AND password='$password'";
  	$results = mysqli_query($db, $query);
  	if (mysqli_num_rows($results) == 1) {
  	  $_SESSION['roll_no'] = $username;
  	  $_SESSION['success'] = "You are now logged in";
  	  header('location: student_portal.php');
  	}else {
      array_push($errors, "Wrong username/password combination");
  	}
  }
}

// LOGIN ADMIN
if (isset($_POST['login_admin'])) {
  $username = mysqli_real_escape_string($db, $_POST['username']);
  $password = mysqli_real_escape_string($db, $_POST['password']);

  if (empty($username)) {
  	array_push($errors, "Username is required");
  }
  if (empty($password)) {
  	array_push($errors, "Password is required");
  }

  if (count($errors) == 0) {
  	$password = md5($password);

  	$query = "SELECT * FROM hostel_details WHERE hostel_id='$username' AND password='$password'";
  	$results = mysqli_query($db, $query);
  	if (mysqli_num_rows($results) == 1) {
  	  $_SESSION['hostel_id'] = $username;
      $_SESSION['success'] = "You are now logged in";
  	  header('location: admin_portal.php');
  	}else {
  		array_push($errors, "Wrong username/password combination");
  	}
  }
}
?>
