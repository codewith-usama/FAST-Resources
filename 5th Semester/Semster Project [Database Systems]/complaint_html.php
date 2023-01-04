<?php include('server.php') ?>
<!DOCTYPE html>
<html>
<head>
	<title>COMPLAINTS | HOSTEL MANAGMENT SYSTEM</title>
	<link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body  style="background-color: #c7d3d4ff">
<div class="header" style="background-color: #a445b2;">
<h2>Initiate A Complaint</h2>
</div>

<div class="content">
    <h3 style="text-align:center;">Facilities availed by you</h3><br>
<table>
    <tr>
      <th>Facility ID</th>
      <th>Facility Name</th>
      <th>Facility Cost</th>
    </tr>
    <?php
        $id=$_SESSION['roll_no'];
        $query = "SELECT * FROM facilities_availed inner join facilities on  facilities_availed.facility_id=facilities.facility_id WHERE facilities_availed.roll_no='$id'";
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
<br>
<form method="post" action="complaint_back.php">
    <label>Facility ID</label><br>
    <input type="number" name="facility_id">
    <label>Enter your Complaint</label><br>
    <textarea name="complaint" rows="6"></textarea>
    <input type="submit" name="submit">
</form>
</div>
</body>
</html>
