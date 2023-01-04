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
  if (isset($_GET['complaint_id'])){
    $comp_id = $_GET['complaint_id'];
    $hostel_id = $_SESSION['hostel_id'];

      $sql ="UPDATE complaints SET complaint_status = 1 WHERE complain_ticket in (SELECT complain_ticket FROM complaints WHERE complain_ticket = '$comp_id' AND hostel_id = '$hostel_id');";
      $output = $db->query($sql);
      if(!($db->affected_rows)){
        echo 'Error! Invalid Complaint ticket for this hostel!';
      }
      else
      {
        echo 'Complaint status resolved successfully!';
      }
    }
?>
<!DOCTYPE html>
<html>
<head>
  <title>VIEW COMPLAINTS | HOSTEL MANAGMENT SYSTEM</title>
  <link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body  style="background-color: #c7d3d4ff">
<div class="header" style="background-color: #a445b2;">
	<h2>View Complaints</h2>
</div>
<div class="content">
<table>
    <tr>
      <th>Complaint ID</th>
      <th>Roll No</th>
      <th>Facility Name</th>
      <th>Comments</th>
      <th>Status</th>

    </tr>

    <?php
        $id=$_SESSION['hostel_id'];
        $query = "SELECT * FROM complaints inner join facilities on  complaints.facility_id=facilities.facility_id WHERE complaints.hostel_id='$id'";
        $results = $db->query($query);
        $status = "";
        if($results->num_rows > 0)
        {
          while($row = $results->fetch_assoc())
          {
            echo "<tr>";
            //echo "Roll No: " . $row['roll_no']. " - hostel ID:".$row['hostel_id']."- Due Date: ". $row['due_date']." Status: ".$row['status'];
            echo "<td>".$row['complain_ticket']."</td>";
            echo "<td>".$row['roll_no']."</td>";
            echo "<td>".$row['facility_name']."</td>";
            echo "<td>".$row['comments']."</td>";
            if($row['complaint_status'] == 0){$status="Unresolved";}
            else{$status="Resolved";}
            echo "<td>" .$status. "</td>";

            echo "</tr>";
          }
        }
    ?>
    <br>
      </table>
      <br>
<form action="view_complaint.php" method="get">
        <label>Enter the Complaint ID you want to Resolve</label><br>
        <input type="number" name="complaint_id">
        <input type="submit" value="submit">
    </form>
</div>
</body>
</html>
