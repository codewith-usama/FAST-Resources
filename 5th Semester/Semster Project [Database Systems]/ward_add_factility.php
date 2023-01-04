<?php 
  session_start(); 

  if (!isset($_SESSION['hostel_id'])) {
  	$_SESSION['msg'] = "You must log in first";
  	header('location: warden_login.php');
  }
  if (isset($_GET['logout'])) {
  	session_destroy();
  	unset($_SESSION['hostel_id']);
  	header("location: login.php");
  }
  $db = new mysqli('localhost', 'root', '', 'project');
  if(isset($_GET['add_rem_facility']))
    {
        $Add=1;
        $id=$_SESSION['hostel_id'];
        $req_facility=$_GET['facility'];
        
        //yaha check krna hy ky kia facilites available mein ye hostel ye facility de rha hy ya nhi. Agr de rha hy tou remove krdo aur nhi de rha tou add krdo.
        }//add_rem_facilities
?>
<!DOCTYPE html>
<html>
<head>
	<title>Home</title>
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body>

<div class="header">
	<h2>Warden Home Page</h2>
</div>
<div class="content">
<table>
    <tr>
      <th>Facility ID</th>
      <th>Facility Name</th>
      <th>Facility Cost</th>
    </tr>
    <?php
        $id=$_SESSION['hostel_id'];
        $query = "SELECT * FROM facilities;";
        $results = $db->query($query);
        if($results->num_rows > 0)
        {
          while($row = $results->fetch_assoc())
          {
            echo "<tr>";
            //echo "Roll No: " . $row['roll_no']. " - hostel ID:".$row['hostel_id']."- Due Date: ". $row['due_date']." Status: ".$row['status'];
            echo "<td>".$row['facility_id']."</td>";
            echo "<td>".$row['facility_name']."</td>";
            echo "<td>".$row['facility_cost']."</td>";
            echo "</tr>";
          }
        }
    ?>
</table>
<form method="get" action="ward_add_facility.php">
  	<?php include('errors.php'); ?>

  	<div class="input-group">
  	  <label>Enter The facility you want to Add/Remove: </label>
  	  <input type="text" name="facility" >
  	</div>
      <div class="input-group">
  	  <button type="submit" class="btn" name="add_rem_facility">Add/Remove</button>
  	</div>
</div>

</body>
</html>