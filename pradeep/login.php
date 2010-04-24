<?include('functions.php');
session_start();
?>
<html>
<body>
<form action='login.php' method='POST'>
  Username :
  <input type='text' name='username' /><br />
  Password :
  <input type='password' name='password' /><br />
  <input type='submit' />
  </form>

  <?php

  $username = $_POST['username'];
$password = $_POST['password'];
$action = $_POST['logout'];


if(islogin()) {
  header('Location:register.php');
 }
checkpassword($username, $password, 'test');

?>
</body>
</html>
