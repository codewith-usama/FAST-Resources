<?php
  session_start();

  if (!isset($_SESSION['roll_no'])) {
  	$_SESSION['msg'] = "You must log in first";
  	header('location: student_login.php');
  }
  if (isset($_GET['logout'])) {
  	session_destroy();
  	unset($_SESSION['roll_no']);
  	header("location: student_warden_login.php");
  }
?>
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">

    <title>STUDENT PORTAL | HOSTEL MANAGMENT SYSTEM</title>
    <link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
    <link rel="stylesheet" href="student-login.css">
    <link rel="stylesheet" href="css-for-student.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
    <img src="student-bg.jpg" class="bg" alt="HOSTEL Image">
    <?php  if (isset($_SESSION['roll_no'])) : ?>
      <h1>Welcome <strong><?php echo $_SESSION['roll_no']; ?></strong></h1>
      <a class="fcc-btn" href="rent_status.php">Check Rent Status</a>
      <a class="fcc-btn" href="availed_fac.php">Check Facilities Availed</a>
      <a class="fcc-btn" href="complaint_html.php">Register Complaint</a>
      <a class="fcc-btn" href="add_rem_facilities.php">Add/Remove Facilites</a>
      <a class="fcc-btn log" href="student_portal.php?logout='1'">logout</a>
      <?php endif ?>
  </body>
</html>
