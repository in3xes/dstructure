<?include('functions.php');
session_start();
welcome();
/*
if(islogin()) {
  if($_SESSION['level'] ==3) {
    $userid = $_SESSION['userid'];
    echo "Welcome ";
    echo $userid;
    echo "<br />";
  }
  else {
    header("Location:display.php");
  }
 }
else
  //    header("Location:login.php");
    echo "Wecome Guest";
*/
?>
<html>
<body>
Search:<br p/>
<form action='search.php' method='GET'>
  Username:
  <input type='text' name='username'><br />
  Style No:
  <input type='text' name='sno'><br />
  Unit No:
  <input type='text' name='unit'><br />
  <input type='submit'>
</form>
<?php
  $username = $_GET['username'];
$sno = $_GET['sno'];
$unit = $_GET['unit'];
search($username, $sno, $unit);
?>
</body>
</html>
