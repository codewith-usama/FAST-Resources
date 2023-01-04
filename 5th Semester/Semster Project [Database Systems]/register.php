<?php include('server.php') ?>
<?php
  #session_start();

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
<html>
<head>
  <title>REGISTER STUDENT | HOSTEL MANAGMENT SYSTEM</title>
  <link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
  <link rel="stylesheet" type="text/css" href="style.css">
</head>
<body  style="background-color: #c7d3d4ff">
<div class="header" style="background-color: #a445b2;">
  	<h2>Student Register</h2>
  </div>

  <form method="post" action="register.php">
  	<?php include('errors.php'); ?>

  	<div class="input-group">
  	  <label>Roll No: </label>
  	  <input type="text" name="roll_no" value="<?php echo $roll_no; ?>">
  	</div>

	<div class="input-group">
  	  <label>CNIC: </label>
  	  <input type="text" name="cnic" value="<?php echo $cnic; ?>">
  	</div>

	  <div class="input-group">
  	  <label>First Name: </label>
  	  <input type="text" name="first_name" value="<?php echo $first_name; ?>">
  	</div>

	  <div class="input-group">
  	  <label>Last Name: </label>
  	  <input type="text" name="last_name" value="<?php echo $last_name; ?>">
  	</div>


	<div class="input-group">
		<label>Student Representative: </label>
		<input type="text" name="student_rep" value="<?php echo $student_rep; ?>">
  	</div>
  	<div class="input-group">
		<label>Room No: </label>
		<input type="text" name="room_no" value="<?php echo $room_no; ?>">
  	</div>
	  <div class="input-group">
  	  <label>Phone Number</label>
  	  <input type="text" name="phone_no" value="<?php echo $phone_no; ?>">
  	</div>

	<div class="input-group">
  	  <label>Guardian Name</label>
  	  <input type="text" name="guardian_name" value="<?php echo $guardian_name; ?>">
  	</div>

	<div class="input-group">
  	  <label>Address</label>
  	  <input type="text" name="address" value="<?php echo $address; ?>">
  	</div>




	<div class="input-group">
  	  <label>Password</label>
  	  <input type="password" name="password_1">
  	</div>
  	<div class="input-group">
  	  <label>Confirm password</label>
  	  <input type="password" name="password_2">
  	</div>
  	<div class="input-group">
  	  <button type="submit" class="btn" name="reg_user">Register</button>
  	</div>
  	<!--<p>
  		Already a member? <a href="login.php">Sign in</a>
  	</p> -->
  </form>
</body>
</html>
