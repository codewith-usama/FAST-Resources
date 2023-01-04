<?php include('complaint_html.php') ?>
<?php 
  #session_start(); 

  if (!isset($_SESSION['roll_no'])) {
  	$_SESSION['msg'] = "You must log in first";
  	header('location: student_login.php');
  }
  $db = new mysqli('localhost', 'root', '', 'project');
  $id=$_SESSION['roll_no'];
  $hostel_id_query="SELECT hostel_id from student_details where roll_no='$id'";
  $hostel_id=$db->query($hostel_id_query);
  $hostel_id=$hostel_id->fetch_assoc()['hostel_id'];
  $facility_id=$_POST['facility_id'];
  $complaint=$_POST['complaint'];
  $do_it=0;
  if ($_POST['submit'])
  {
    $facility_set_query="SELECT facility_id from facilities_availed where roll_no='$id';";
    $output=$db->query($facility_set_query);
    if($output->num_rows>0)
    {
      while($row=$output->fetch_assoc())
      {
        if($row['facility_id']==$facility_id)
        {
          $do_it=1;
          break;
        }
      }
    }
    if($do_it)
    {
        $insert_query="INSERT INTO complaints(roll_no, hostel_id, facility_id, comments, complaint_status) VALUES ('$id','$hostel_id','$facility_id','$complaint',0);";
        $db->query($insert_query);
    }
    else
    {
      echo "You have not availed the facility you are complaining about.";
    }
  }
  else
  {
    echo "Error Occured";
  }
?>