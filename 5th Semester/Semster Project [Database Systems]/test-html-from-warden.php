<?php include('server.php') ?>
<?php

  if (!isset($_SESSION['hostel_id'])) {
  	$_SESSION['msg'] = "You must log in first";
  	header('location: warden_login.php');
  }
  if (isset($_GET['logout'])) {
  	session_destroy();
  	unset($_SESSION['hostel_id']);
  	header("location: login.php");
  }
?>
<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">

    <title>HOSTEL MANAGMENT SYSTEM</title>
    <link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
    <!-- <link rel="stylesheet" href="style.css"> -->
    <link rel="stylesheet" href="student-login.css">
    <link rel="stylesheet" href="test-css-for-warden.css">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
  </head>
  <body>
    <img src="student-bg.jpg" class="bg" alt="HOSTEL Image">
    <?php  if (isset($_SESSION['hostel_id'])) : ?>
      <h1>Welcome <strong><?php echo $_SESSION['hostel_id']; ?></strong></h1>
      <a class="fcc-btn" href="register.php">Register new Student</a>
      <a class="fcc-btn" href="view_complaint.php">View Complaints</a>
      <a class="fcc-btn" href="warden_facility_add.php">Add Facility</a>
      <a class="fcc-btn" href="bills.php">Billing</a>
      <a class="fcc-btn" href="view_admitted_students.php">View Admitted Student</a>
      <a class="fcc-btn log" href="admin_portal.php?logout='1'">logout</a>
      <?php endif ?>
  </body>
</html>
