<?php
  session_start();

  if (!isset($_SESSION['roll_no'])) {
  	$_SESSION['msg'] = "You must log in first";
  	header('location: student_login.php');
  }
  $db = new mysqli('localhost', 'root', '', 'project');
?>
<!DOCTYPE html>
<html>
<head>
  <title>Rent Status | HOSTEL MANAGMENT SYSTEM</title>
  <link rel="sicon" href="favicon.ico" type="image/x-icon">
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
	<link rel="stylesheet" type="text/css" href="style.css">

</head>
<body style="background-color: #c7d3d4ff">
<div class="header" style="background-color: #a445b2;">
	<h2>Rent Status</h2>
</div>
<div class="content">
  <table>
    <tr>
      <th>Roll Number</th>
      <th>Hostel ID</th>
      <th>Amount</th>
      <th>Due Date</th>
      <th>Status</th>
    </tr>
    <?php
        $id=$_SESSION['roll_no'];
        $query = "SELECT * FROM accounts WHERE roll_no='$id'";
        $results = $db->query($query);
        $rent_status ="";
        if($results->num_rows > 0)
        {
          while($row = $results->fetch_assoc())
          {
            echo "<tr>";
            //echo "Roll No: " . $row['roll_no']. " - hostel ID:".$row['hostel_id']."- Due Date: ". $row['due_date']." Status: ".$row['status'];
            echo "<td>".$row['roll_no']."</td>";
            echo "<td>".$row['hostel_id']."</td>";
            echo "<td>".$row['rent_amount']."</td>";
            echo "<td>".$row['due_date']."</td>";
            echo "<td>".$row['status']."</td>";
            echo "<td style = \"padding 15px\"><a class=\"pay_btn\" href=\"https://buy.stripe.com/test_cN20140Olc0b6C4aEE\">Pay Rent</a></td>";
            echo "</tr>";
          }
        }
    ?>
    </table>
    
</div>
</body>
</html>
