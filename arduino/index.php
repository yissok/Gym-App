<?php

	include("connect.php"); 	
	
	$link=Connection();

	$result=mysql_query("SELECT * FROM `History`");
?>

<html>
   <head>
      <title>Sensor Data</title>
   </head>
<body>
   <h1>People in gym</h1>

   <table border="1" cellspacing="1" cellpadding="1">
		<tr>
			<td>&nbsp;Time&nbsp;</td>
			<td>&nbsp;People&nbsp;</td>
		</tr>

        <?php 
            $result = mysqli_query($link,"SELECT * FROM History");
            $rowcount=mysqli_num_rows($result)-1;
            //echo $rowcount;
            $query = "SELECT Time, People FROM History";
            $result = mysqli_query($link, $query);
            //$row = mysqli_fetch_assoc($result);
            while($row = $result->fetch_array())
            {
                echo "<tr><td>".$row["Time"]. "</td><td>".$row["People"]. "</td></tr>";
            }
            mysql_close();
        ?>

   </table>
</body>
</html>
