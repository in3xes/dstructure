<?php
include('functions.php');
session_start();
if(!islogin())
  header("Location:login.php");

welcome();
?>
<html>
<body>
Register a complaint:
<form action=register.php method='POST'>
    Custor Name:
    <input type='text' name='c_name' /><br />
    Style No:
    <input type='text' name='s_no' /><br />
    Unit conc:
    <input type='text' name='unit' /><br />
  Problem Area 1 : <input type='checkbox' name='pa1' /><br />
  Problem Area 2 : <input type='checkbox' name='pa2' /><br />
  Problem Area 3 : <input type='checkbox' name='pa3' /><br />
  Problem Area 4 : <input type='checkbox' name='pa4' /><br />
  Complaints:
    <textarea name='complaint' cols='40' rows='7'>
Enter your complaints here...</textarea><br />
  <input type='submit' value='submit'/><br />
</form>
<?php
$username = $_POST['c_name'];
$sno = $_POST['s_no'];
$unit = $_POST['unit'];
$complaint = $_POST['complaint'];
if(isset($_POST['pa1']))
  $pa1=1;
 else
   $pa1=0;
if(isset($_POST['pa2']))
  $pa2=1;
 else
   $pa2=0;
if(isset($_POST['pa3']))
  $pa3=1;
 else
   $pa3=0;
if(isset($_POST['pa4']))
  $pa4=1;
 else
   $pa4=0;



  if(validate($username, $sno, $unit)) {
    complaint($username, $sno, $unit, $complaint, $pa1, $pa2, $pa3, $pa4);
  }


?>
<body/>
<html/>
