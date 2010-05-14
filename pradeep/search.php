<?include('functions.php');
session_start();
welcome();
if(!islogin())
  header("Location:login.php");

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
