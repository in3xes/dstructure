<?php
include('functions.php');
session_start();
if(!islogin())
  header("Location:login.php");
welcome();
?>
<html>
<body>
<form action='update.php' method='GET'>
<?php
if($_SESSION['leve'] < 3) {
  display_contents_users($_SESSION['userid'], $_SESSION['level']);
}
else
  display_contents();
?>
</form>
</body>
</html>
