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
    $query = "select password, level from users where name = '$username'";
    $conn_db = getconnection();
    mysql_select_db($db, $conn_db);

    $result = mysql_query($query, $conn_db);
    $row = mysql_fetch_assoc($result);
    $password_db = $row['password'];
    $level = $row['level'];
    if($password == $password_db) {
      session_start();
      $_SESSION['userid'] = $username;
      $_SESSION['level'] = $level;
      header('Location:register.php');
    }
    else
      header('Location:login.php');
  }
  mysql_close($conn_db);
}

function islogin() {
  if(isset($_SESSION['userid']) != NULL) {
    return true;
  }
  else
    return false;
}

function logout() {
  
  session_start();
  session_destroy();
  header('Location:login.php');
}

function welcome() {
	if(islogin())
		echo "Welcome ".$_SESSION['userid']."<br />";
	else
		echo "Welcome  Guest<br />";
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

function intime($prev, $curr) {
	$diff = $curr - $prev;
	if($diff < (1*24*60*60))
		return true;
	else
		return false;
}
function display_contents() {

  $conn_db = getconnection();
  
  mysql_select_db('test', $conn_db);
  $query = "select * from complaint";

  $result = mysql_query($query, $conn_db);
  while($row = mysql_fetch_assoc($result)) {
	echo "<input type='radio' name = 'complaint' value='";
	echo $row['complainid'];
	echo "' /> &nbsp ";
	echo $row['complaint']."<br />By :";
	echo $row['username']." &nbsp&nbsp&nbsp&nbsp&nbsp&nbsp ";
	if($row['status'] == 1 ) {
		if(intime($row['reg_time'], time()))
			echo "Status : Open<br />";
		else
			echo "Status : Deleyed <br />";
	}
	else
		echo "Status : Closed <br />";

	echo "<br /><hr>";

  }
	echo "<input type='submit' value='Resolve'>";

	mysql_close($conn_db);

}

function search($username, $sno, $unit, $word) {
  $query = "select * from complaint where username like '%$username%' or style_no = $sno or unit = $unit";
 	
  $conn_db = getconnection();
  mysql_select_db('test', $conn_db);
  $result = mysql_query($query, $conn_db);
  while($row = mysql_fetch_assoc($result)) {
    echo $row['complaint']."<br />";
  }

  mysql_close($conn_db);
}

function update($answer, $id) {
	
	$conn_db = getconnection();
	mysql_select_db('test', $conn_db);
	
	$query = "update complaint set resolution='$answer' where complainid=$id";
	$query2 = "update complaint set status=2 where complainid=$id";

//	echo $query;
//	echo $query2;
	mysql_query($query, $conn_db);
	mysql_query($query2, $conn_db);
	}

include('links.php');
?>

