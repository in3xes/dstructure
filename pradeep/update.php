<?php
include('functions.php');
session_start();
welcome();
?>
<html>
<body>
<?php
	
	$id = $_GET['complaint'];
	$conn_db = getconnection();
	mysql_select_db('test', $conn_db);

	$query = "select * from complaint where complainid=".$_GET['complaint'];
	$result = mysql_query($query, $conn_db);
	$row = mysql_fetch_assoc($result);
	echo $row['complaint']."<br />By :";
	echo $row['username']."<br />";
	
	mysql_close($conn_db);

	$answer = $_POST['answer'];
	if($answer != NULL) {
		update($answer, $id);
		header("Location:display.php");
	}
?>
<form method='POST' actioin='update.php'>
<textarea cols='50' rows='8' name='answer'>Enter your answer</textarea>
<!-- <input type='hidden' name='complaint' value=<?echo $id?> /> -->
<br />
<input type='submit' value='submit' />
</form>
</body>
</html>
