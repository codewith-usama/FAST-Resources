<?php include('server.php') ?>
<?php 
  //session_start(); 

  if (!isset($_SESSION['hostel_id'])) {
  	$_SESSION['msg'] = "You must log in first";
  	header('location: warden_login.php');
  }
  $db = new mysqli('localhost', 'root', '', 'project');
  $id=$_SESSION['hostel_id'];

  $hostel_id=$id;
  $facility_id=$_POST['facility_id'];
  
  if ($_POST['submit'])
  {
    $insert_query="INSERT INTO facilities_available(facility_id, hostel_id) VALUES ('$facility_id','$hostel_id');";
    $db->query($insert_query);
  }
  header("location: warden_facility_add.php");

?>
