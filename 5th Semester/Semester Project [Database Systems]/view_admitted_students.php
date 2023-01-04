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
  if(isset($_GET['submit']))
  {
    $id = $_SESSION['hostel_id'];
    $flag =0;
    $roll_no = $_GET['roll_no'];
    $sql = "SELECT roll_no FROM student_details WHERE hostel_id = '$id';";
    $results = $db->query($sql);
    if($results->num_rows > 0)
    {
      while($row = $results->fetch_assoc())
      {
        if($row['roll_no'] == $roll_no)
        {
          $flag=1;
          break;
        }
      }
    }
    if($flag)
    {
      try{
      $db->begin_transaction();
      $db->query("DELETE FROM student_details WHERE roll_no = '$roll_no';");
      $db->query("UPDATE accounts A SET A.status='PAID' WHERE roll_no='$roll_no';");
      $db->commit();
      }
      catch (\Throwable $e)
      {
          $db->rollback();
          throw $e;
      }
      echo $roll_no. "Deleted successfully!";
    }
    else
    {
      echo $roll_no. "does not exist in this hostel!";
    }
}
?>
<!DOCTYPE html>
<html>
<head>
  <title>VIEW STUDENTS | HOSTEL MANAGMENT SYSTEM</title>
  <link rel="shortcut icon" href="favicon.ico" type="image/x-icon">
	<script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js" integrity="sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM" crossorigin="anonymous"></script>
	<link rel="stylesheet" type="text/css" href="style.css">
</head>
<body  style="background-color: #c7d3d4ff">
<div class="header" style="background-color: #a445b2;">
	<h2>Admitted Students</h2>
</div>
<div class="content">
<table>
    <tr>
      <th>Roll No</th>
      <th>First Name</th>
      <th>Last Name</th>
    </tr>
    <?php
        $id=$_SESSION['hostel_id'];
        $query = "SELECT * FROM student_details inner join hostel_details on  student_details.hostel_id=hostel_details.hostel_id WHERE student_details.hostel_id='$id'";
        $results = $db->query($query);
        if($results->num_rows > 0)
        {
          while($row = $results->fetch_assoc())
          {
            echo "<tr>";
            echo "<td>".$row['roll_no']."</td>";
            echo "<td>".$row['first_name']."</td>";
            echo "<td>".$row['last_name']."</td>";
            echo "</tr>";
          }
        }

    ?>
</table>
<form action="view_admitted_students.php" method="get">
        <label>Enter the Student Roll NO. you want to Remove  </label><br>
        <input type="text" name="roll_no">
        <input type="submit" value="submit" name = "submit">
    </form>
</div>
</body>
</html>
