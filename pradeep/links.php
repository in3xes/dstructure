<a href='display.php'>Dispaly</a><br >
<?
session_start();
if(islogin())
	echo "<a href='logout.php'>Logout</a><br >";
else	
	echo "<a href='login.php'>Login</a><br />";
?>	
<a href='register.php'>Complaint</a><br/>
<a href='search.php'>Search</a><br />
<?php
  if($_SESSION['level'] > 1 ) 
    echo "<a href='report.php'>Report</a><br />";
?>