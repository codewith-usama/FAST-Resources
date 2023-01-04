<?php include('server.php') ?>

<!DOCTYPE html>
<html>
<head>
	<title>ADD NEW FACILITES | HOSTEL MANAGMENT SYSTEM</title>
	<link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body  style="background-color: #c7d3d4ff">
<div class="header" style="background-color: #a445b2;">
	<h2>Add a New Facility in hostel</h2>
</div>


<div class="content">
<table>
    <h4>All Available Facilities</h4><br><br>
    <tr>
      <th>Facility ID</th>
      <th>Facility Name</th>
      <th>Facility Cost</th>
    </tr>
    <?php
        //$id=$_SESSION['hostel_id'];
        $all_facility="SELECT * FROM facilities ;";
        $results=$db->query($all_facility);
        if($results->num_rows > 0)
        {
            while($row = $results->fetch_assoc())
            {
                echo "<tr>";
                echo "<td>".$row['facility_id']."</td>";
                echo "<td>".$row['facility_name']."</td>";
                echo "<td>".$row['facility_cost']."</td>";
                echo "</tr>";
            }
        }

    ?>
    </table>
    <table>
        <br>
        <br>
    <h4>Facilities Provided by Hostel</h4><br>
    <tr>
      <th>Facility ID</th>
      <th>Facility Name</th>
      <th>Facility Cost</th>
    </tr>
    <?php
        $id=$_SESSION['hostel_id'];
        $all_facility="SELECT * FROM facilities_available JOIN facilities ON facilities_available.facility_id=facilities.facility_id WHERE hostel_id ='$id';";
        $results=$db->query($all_facility);
        if($results->num_rows > 0)
        {
            while($row = $results->fetch_assoc())
            {
                echo "<tr>";
                echo "<td>".$row['facility_id']."</td>";
                echo "<td>".$row['facility_name']."</td>";
                echo "<td>".$row['facility_cost']."</td>";
                echo "</tr>";
            }
        }

    ?>
    </table>
    <form method="post" action="warden_facility_add_back.php">
    <label>Facility ID</label><br>
    <input type="number" name="facility_id">
    <input type="submit" name="submit">
</form>

</div>
</body>
</html>
