<?php
include('functions.php');
session_start();
welcome();
?>
<html>
<body>
<form action='update.php' method='GET'>
<?php
display_contents();
?>
</form>
</body>
</html>
