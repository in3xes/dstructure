<?php
include('functions.php');
session_start();
$userid = $_SESSION['userid'];
print "Hello $userid<br />";
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

if($_SESSION['level'] == 1) {

  if(validate($username, $sno, $unit)) {
    complaint($username, $sno, $unit, $complaint);
  }
        else {
    print "All the fields should be filled<br />";
    }

      }
   else {
     print "your are not allowed to Enter a complaint<br />";
     print "<a href=\"update.php\">Click Here to add a resolution</a>";
   }
?>
<a href="logout.php">Logout</a>
<body/>
<html/>