<!DOCTYPE html>
<!-- Fig. 19.4: operators.php -->
<!-- Using arithmetic operators. -->
<html>
  <head>
    <meta charset = "utf-8">
    <style type = "text/css">
    p { margin: 0; }
    </style>
    <title>Using arithmetic operators</title>
  </head>
  <body>
    <?php
      $a = 5;
      print( "<p>The value of variable a is $a</p>" );
      
      // define constant VALUE
      define( "VALUE", 5 );
      
      // add constant VALUE to variable $a
      $a = $a + VALUE;
      print( "<p>Variable a after adding constant VALUE is $a</p>" );
      
      // multiply variable $a by 2
      $a *= 2;
      print( "<p>Multiplying variable a by 2 yields $a</p>" );
      
      // test if variable $a is less than 50
      if ( $a < 50 )
      {
        print( "<p>Variable a is less than 50</p>" );
      }

      // add 40 to variable $a
      $a += 40;
      print( "<p>Variable a after adding 40 is $a</p>" );
      
      // test if variable $a is 50 or less
      if ( $a < 51 )
      {
        print( "<p>Variable a is still 50 or less</p>" );
      } 
      elseif ( $a < 101 )
      {
        // $a >= 51 and <= 100
        print( "<p>Variable a is now between 50 and 100, inclusive</p>" );
      }
      else // $a > 100
      {
        print( "<p>Variable a is now greater than 100</p>" );
      }

      // print an uninitialized variable
      print( "<p>Using a variable before initializing: $nothing</p>" ); // nothing evaluates to ""
      
      // add constant VALUE to an uninitialized variable
      $test = $num + VALUE;
      
      // num evaluates to 0
      print( "<p>An uninitialized variable plus constant VALUE yields $test</p>" );
      
      // add a string to an integer
      $str = "3 dollars";
      $a += $str;
      print( "<p>Adding a string to variable a yields $a</p>" );
    ?><!-- end PHP script -->
  </body>
</html>
