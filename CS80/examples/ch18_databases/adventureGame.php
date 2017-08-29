<!DOCTYPE HTML> 

<!-- adventureGame.php
     Last modified: 12/08/2014
-->
<html>
<head>
<meta charset="utf-8">
<title>Adventure Game</title>
<style type = "text/css">
body {
  color:red
}
td {
  color: white;
  background-color: blue;
  width: 20%;
  height: 3em;
  font-size: 20pt
}
</style>
</head>
<body>
<?php
/* 
 * File: adventureGame.php
 * Description: The actual gameplay consists of repeated calls to this script.
 *              The one input to this script is the room field.
 * Author: Andy Harrris
 * Modified by: Ken Geddes on 12/08/2014 for cs80
 */

define('BR', "<br>\n"); // a constant used for formatting output

// For security reasons, we put the username and password values in a separate file.
// This file defines variables that will be used for connecting to the MySQL server.
include('db_connection_info.inc');
 
// Here we connect to the MySQL server on ciswebs as the cs80 user and select the cs80 database to use.
// Since the MySQL server is running on the same host machine as this script, we can use "localhost" for hostname.
// If the connection attempt fails, the script is terminated with the die function.
// mysqli_error() function gives error message from most recent mysqli_ function call.
$link  = mysqli_connect("localhost", $cs80Username, $cs80Password, 'cs80') 
    or die('Unable to connect to MySQL ' . mysqli_error());

// Get room number. This is the value of the form field named 'room'.
if (filter_has_var(INPUT_POST, 'room')) {
   $room = filter_input(INPUT_POST, 'room');
} else {
   $room = 1;
}

// Retrieve from the adventure table the record with id equal to the chosen room number.
$result = mysqli_query($link, "SELECT * FROM adventure WHERE id = $room") or die(mysqli_error());

// If room doesn't exist, go to start.
if (mysqli_num_rows($result) == 0) {
    echo "Room number $room does not exist.", BR;
    $result = mysqli_query($link, "SELECT * FROM adventure WHERE id = 1") or die(mysqli_error());
}

// Build the radio buttons for the form to be sent to the browser.
// The result of the query is actually a number identifying a resource. We need to fetch the record
// from the resource. This will be an array of fields.
$mainRow = mysqli_fetch_assoc($result);
// name, description, etc. are fields in the array.
$roomName = $mainRow["name"];
$theText = $mainRow["description"];

// We need to build four buttons - one for each direction. So, we have written a buildButton function
// which we call four times, each time passing a direction as the argument.
$northButton = buildButton("north");
$eastButton = buildButton("east");
$southButton = buildButton("south");
$westButton = buildButton("west");

// Here is where we insert the values of the PHP variables into the HTML.
print <<<HERE
<center><h1>$roomName</h1></center>
<form method = "post">
<table border = 1>
<tr>
  <td></td>
  <td>$northButton</td>
  <td></td>
</tr>

<tr>
  <td>$westButton</td>
  <td>$theText</td>
  <td>$eastButton</td>
</tr>

<tr>
  <td></td>
  <td>$southButton</td>
  <td></td>
</tr>

</table>
<center>
<input type = "submit"
       value = "Go">
</center>
</form>
HERE;

// Build a button for the specified direction. The single parameter receives the direction.
function buildButton($dir){
  global $mainRow, $link;
  $newID = $mainRow[$dir];
  
  $result = mysqli_query($link, "SELECT name FROM adventure WHERE id = $newID") or die(mysqli_error());

  $row = mysqli_fetch_assoc($result);
  $roomName = $row["name"];

  $buttonText = <<< HERE
  <input type = "radio"
         name = "room"
         value = "$newID">$roomName
HERE;
  return $buttonText;
} // end buildButton
?>
</body>
</html>
