<!DOCTYPE HTML> 
<html>
<head>
<meta charset="UTF-8">
<title>Build Adventure Table in CS80 Database</title>
</head>
<body>
<h1>Build Adventure Table in CS80 Database</h1>
<?php
/* 
 * File: buildAdventure.php
 * Description: This PHP script:
 *     - connects as the cs80 user
 *     - selects the cs80 database
 *     - creates the adventure table and populates it.
 * Author: Ken Geddes
 * Date: 05/27/2014
 */

$queries = array(
    "DROP TABLE IF EXISTS adventure;",

    "CREATE TABLE adventure (id int PRIMARY KEY, name varchar(25), description varchar(200),  north int, east int, south int, west int);",

    "INSERT INTO adventure values(0, '', 'You cannot go that way!', 1, 0, 0, 0);",

    "INSERT INTO adventure values(1, 'start', 'You are at a submarine yard, looking for the famous Enigma code machine.', 20, 3, 0, 2);",

    "INSERT INTO adventure values(2, 'sub deck', 'As you step on the submarine deck, a guard approaches you.  Your only choice is to jump off the sub before you are caught.', 15, 15, 15, 15);",

    "INSERT INTO adventure values(3, 'warehouse', 'You wait inside the warehouse.  You see a doorway to the east and a box to the south.', 0, 4, 5, 0);",

    "INSERT INTO adventure values(4, 'doorway', 'You walked right into a group of guards. It does not look good...', 0, 19, 0, 15);",

    "INSERT INTO adventure values(5, 'box', 'You crawl inside the box and wait. Suddenly, you feel the box being picked up and carried across the wharf!', 6, 0, 0, 7);",

    "INSERT INTO adventure values(6, 'wait', '..You wait until the box settles in a dark space. You can move forward or aft...', 8, 0, 9, 0);",

    "INSERT INTO adventure values(7, 'jump out', 'You decide to jump out of the box, but you are cornered at the end of the wharf.', 15 ,19, 15, 15);",

    "INSERT INTO adventure values(8, 'forward', 'As you move forward, two rough sailors grab you and hurl you out of the conning tower.', 15 ,15, 15, 15);",

    "INSERT INTO adventure values(9, 'aft', 'In a darkened room, you see the enigma device. How will you get it out of the sub?', 13 ,11, 10, 12);",

    "INSERT INTO adventure values(10, 'signal on enigma',  'You use the enigma device to send a signal. Allied forces recognize your signal and surround the ship when it surfaces.', 14 ,0, 0, 0);",

    "INSERT INTO adventure values(11, 'shoot your way out', 'A gunfight on a submerged sub is a bad idea...', 19 ,0, 0, 0);",

    "INSERT INTO adventure values(12, 'wait with enigma' ,'You wait, but the sailors discover that enigma is missing and scour the sub for it. You are discovered and cast out in the torpedo tube.', 15 ,0, 0, 0);",

    "INSERT INTO adventure values(13, 'replace enigma and wait','You put the enigma back in place and wait patiently, but you never get another chance. You are discovered when the sub pulls in to harbor.', 19 ,0, 0, 0);",

    "INSERT INTO adventure values(14, 'Win', 'Congratulations! You have captured the device and shortened the war!', 1, 0, 0, 0);",

    "INSERT INTO adventure values(15, 'Water', 'You are in the water. The sub moves away. It looks bad...', 19 ,0, 0, 0);",

    "INSERT INTO adventure values(16,'','', 0, 0, 0, 0);",

    "INSERT INTO adventure values(17,'','', 0, 0, 0, 0);",

    "INSERT INTO adventure values(18,'','', 0, 0, 0, 0);",

    "INSERT INTO adventure values(19, 'Game Over' ,'The game is over. You lose.', 1, 0, 0, 0);",

    ); // end $queries array

include('db_connection_info.inc');
// connect to the MySQL server as the cs80 user
$mysqli  = mysqli_connect('localhost', $cs80Username, $cs80Password, 'cs80') or die('Unable to connect to MySQL ' . mysqli_error());

foreach($queries as $query) {
    $result = mysqli_query($mysqli, $query);
    if (!$result) {
        die($query . ' failed: ' . mysqli_error());
    }
}

echo '<p>Everything good.</p>';
?>
