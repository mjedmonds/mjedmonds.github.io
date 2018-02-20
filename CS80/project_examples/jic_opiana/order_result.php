<!DOCTYPE html>
<html>

    <head>
        <meta charset="utf-8" />
        <title>Macaron Time: Your Order</title>
        <link rel="stylesheet" href="order_form.css" type="text/css" />
        
        <!-- FAVICON -->
        <link rel="shortcut icon" type="image/x-icon" href="images/mt.ico" />
        
    </head>

    <body>
        
        <a href="http://simplyjic.com/CS80">
            <img src="images/header/macaronlogo.png" alt="Macaron Time Logo" />
        </a>
        
        <div id="result">
        
            <?php
            require('includes/order.inc.php');

            echo handleOrderInfo();
            ?>

            <p>Click <a href="http://simlyjic.com/CS80">here</a> to return back to Macaron Time's Website.</p>
            
        </div>

    </body>

</html>