<!DOCTYPE html>

<html lang="en">

    <head>
        <meta charset="utf-8">
        <title>Macaron Time</title>
        <meta name="description" content="A Cupcake store website">
        
        <!-- CSS -->
        
        <link rel="stylesheet" href="main.css">
        
        <!-- FAVICON -->
        <link rel="shortcut icon" type="image/x-icon" href="images/mt.ico" />
        
        <!-- JS SCRIPTS -->
        
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
        <script src="js/modernizr.custom.86080.js"></script>
        <script src="http://code.jquery.com/jquery-latest.js"></script>
        <script src="js/jquery-2.1.0.min.js"></script>
        <script src="js/app.js"></script>
        <script>window.jQuery || document.write('<script src="../_nav/js/jquery.js"><\/script>')</script>
        
        
        <!-- JAVASCRIPT FOR SMOOTH SCROLLING FROM W3SCHOOLS -->
        
        <script>
            $(document).ready(function(){
                // Add smooth scrolling to all links
                $("a").on("click", function(event) {

                    // Make sure this.hash has a value before overriding default behavior
                    if (this.hash !== "") {
                        // Prevent default anchor click behavior
                        event.preventDefault();

                        // Store hash
                        var hash = this.hash;

                        // Using jQuery's animate() method to add smooth page scroll
                        // The optional number (800) specifies the number of milliseconds it takes to scroll to the specified area
                        $("html, body").animate({
                            scrollTop: $(hash).offset().top
                        }, 1500, function(){   
                            // Add hash (#) to URL when done scrolling (default click behavior)
                            window.location.hash = hash;
                        });
                    } // End if
                });
            });
        </script>
        
        <!-- JAVASCRIPT FOR STICKY MENU WHEN SCROLLING -->
        <!-- http://redvinestudio.com/ -->
        
        <script>
            (function($) {
                $(document).ready(function(){
                    $(window).scroll(function(){
                        if ($(this).scrollTop() > 500) {
                            $("#stickymenu").fadeIn(500);
                        } else {
                            $("#stickymenu").fadeOut(500);
                        }
                    });
                });
            })(jQuery);
        </script>
        
        <!-- JAVASCRIPT FOR FADING IMAGES -->
        <!-- http://www.simonbattersby.com/blog/simple-jquery-image-crossfade/ -->
        
        <script>
            function cycleImages(){
                  var $active = $("#cycler .active");
                  var $next = ($active.next().length > 0) ? $active.next() : $("#cycler img:first");
                  $next.css("z-index",2);//move the next image up the pile
                  $active.fadeOut(1500,function(){//fade out the top image
                      $active.css("z-index",1).show().removeClass("active");//reset the z-index and unhide the image
                      $next.css("z-index",3).addClass("active");//make the next image the top one
                  });
                }

            $(document).ready(function(){
            // run every 4s
            setInterval("cycleImages()", 4000);
            })
        </script>
        
        <!-- ORDER FORM INCLUDES AND JAVASCRIPT -->
        <?php
            require('includes/html_form.class.php');
            require('includes/html_table.class.php');
            require('includes/order.inc.php');
        ?>
        
        <script src="includes/order_form.js"></script>
        <script>
            var PRODUCT_ABBRS = <?php echo json_encode( getProductAbbrs() ) ?>;
        </script>
        
    </head>
    
<!-- END HEADER -->