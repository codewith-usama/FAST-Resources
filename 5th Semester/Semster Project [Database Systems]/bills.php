<?php
  session_start();

  if (!isset($_SESSION['hostel_id'])) {
  	$_SESSION['msg'] = "You must log in first";
  	header('location: student_login.php');
  }
  $db = new mysqli('localhost', 'root', '', 'project');
  $hostel_id=$_SESSION['hostel_id'];
?>
<!DOCTYPE html>
<html>
<head>
  <title>ACCOUNTS | HOSTEL MANAGMENT SYSTEM</title>
  <link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body  style="background-color: #c7d3d4ff">
<div class="header" style="background-color: #a445b2;">
	<h2>Accounts</h2>
</div>
<div class="content">
<form method="get" action="bills.php">
  	<div class="input-group">
  	  <label>Enter Roll Number To View bills: </label>
  	  <input type="text" name="roll_no">
  	</div>
  	<div class="input-group">
  	  <button type="submit" class="btn" name="submit" value="1">submit</button>
  	</div>
</form>
<?php
if(isset($_GET['roll_no'])&&!isset($_GET['due_date']))
{
    $roll_no = mysqli_real_escape_string($db, $_GET['roll_no']);
    $query="SELECT * FROM accounts where roll_no='$roll_no' AND hostel_ID='$hostel_id';";
	$results = $db->query($query);
	echo "<table>
	<tr>
	  <th>Roll Number</th>
	  <th>Hostel ID</th>
	  <th>Amount</th>
	  <th>Due Date</th>
	  <th>Status</th>
	</tr>
  ";
	if($results->num_rows>0)
	{
		while($row=$results->fetch_assoc())
		{
			echo "<tr>";
            //echo "Roll No: " . $row['roll_no']. " - hostel ID:".$row['hostel_id']."- Due Date: ". $row['due_date']." Status: ".$row['status'];
            echo "<td>".$row['roll_no']."</td>";
            echo "<td>".$row['hostel_id']."</td>";
            echo "<td>".$row['rent_amount']."</td>";
            echo "<td>".$row['due_date']."</td>";
			echo "<td>".$row['status']."</td>";
			echo "</tr>";
		}
	}
}
?>
</table>
<form method="get" action="bills.php">
  	<div class="input-group">
  	  <label>Enter Roll Number To View bills: </label>
  	  <input type="text" name="roll_no">
  	</div>
	  <div class="input-group">
  	  <label>Enter Due Date: </label>
  	  <input type="text" name="due_date">
  	</div>
  	<div class="input-group">
  	  <button type="submit" class="btn" name="submit" value="1">submit</button>
  	</div>
</form>
<?php
if(isset($_GET['roll_no'])&&isset($_GET['due_date']))
{
    $roll_no = mysqli_real_escape_string($db, $_GET['roll_no']);
	$due_date = mysqli_real_escape_string($db, $_GET['due_date']);
	$query="UPDATE accounts A SET A.status = 'PAID' WHERE A.roll_no='$roll_no' AND A.due_date='$due_date';";
	$db->query($query);
	echo "Status Changed Kindly refresh";
}
?>
</div>
</body>
</html>
