<html>
	<head>
	<title>Query string</title>
	</head>
	<body>

        
    <?php
        //echo "<h1>Hello " . $_GET["Time"] . " and " . $_GET["People"] . "</h1>";
        include("connect.php");

        $link=Connection();

        $query = "INSERT INTO `History` (`Time`, `People`) 
        VALUES ('".$_GET["Time"]."','".$_GET["People"]."')"; 

        mysqli_query($link,$query);
        mysqli_close($link);

        //header("Location: index.php");//https://localhost/work/arduino/add.php?Time=66&People=666
    ?>

	</body>
	</html>

