<?php
function getconnection() {
  $username = 'root';
  $password = 'Newd@t@b@se';
  $host = 'localhost:3306';
  $conn = mysql_connect($host, $username, $password)
    or   die('Problem' . mysql_error());

  if($conn)
    return $conn;
  else
    return 0;
  }

function checkpassword($username, $password, $db) {

  if($username != NULL) {
    $query = "select password from users where name = '$username'";
    $conn_db = getconnection();
    mysql_select_db($db, $conn_db);

    $result = mysql_query($query, $conn_db);
    $row = mysql_fetch_assoc($result);
    $password_db = $row['password'];
    if($password == $password_db) {
      session_start();
      $_SESSION['userid'] = $username;
      $_SESSION['level'] = 1;
      header('Location:register.php');
    }
    else
      header('Location:login.php');
  }
  mysql_close($conn_db);
}

function islogin() {
  if(isset($_SESSION['userid'])) {
    header('Location:register.php');
    return true;
  }
}

function logout() {
  
  session_start();
  session_destroy();
  header('Location:login.php');
}

function complaint($username, $sno, $unit, $complaint) {
  $conn_db = getconnection();
  mysql_select_db('test', $conn_db);
  $userid = $_SESSION['userid'];
  $time = time();
  
  $query = "insert into complaint(userid, complaint, status, reg_time, username, style_no, unit) values('$userid', '$complaint', 1, $time, '$username', $sno, '$unit')";

  //  print $query;

  mysql_query($query, $conn_db);
  
  //  $result = mysql_query($query, $conn_db);
}

function validate($username, $sno, $unit) {
  if($username != NULL && $sno !=NULL && $unit != NULL) {
    return true;
  }
  return false;
}

function display_contents() {

  $conn_db = getconnection();
  
  mysql_select_db('test', $conn_db);
  $query = "select * from complaint";

  $result = mysql_query($query, $conn_db);
  while($row = mysql_fetch_assoc($result)) {
    print $row['complaint']."<br />";

  }
}

?>

