 <!-- START OF CONTACT SECTION -->
        
        <a id="contact" class="smooth">
            <div id="SectionContact" class="divider"></div>
        </a>

        <div id="Contact">
            <div id="ContactContainer">

                <img class="ContactUs" src="images/contact/contactus.png" alt="Contact Us" />
                <!-- Chalkboard Typography Text Effects by www.graphicburger.com -->
                <!-- Font: Playball by TypeSETit, Open Font License -->
                
                <div style="width: 400px;"> 
                    If you would like to place a request for customized orders or have any questions, comments, please contact us by filling out the form below. We will get back to you as soon as possible. Have an awesome day!
                </div>
                
                <div id="form-messages"></div>
               
                <form id="ajax-contact" method="post" action="mailer.php">
                    <table>
                        <tr>
                            <td class="label"><label for="name">Name:</label></td> 
                            <td class="boxes"><input type="text" id="name" name="name" class="contact" value="" required></td>
                        </tr>
                        <tr>
                            <td class="label"><label for="email">E-mail:</label></td> 
                            <td class="boxes"><input type="text" id="email" name="email" class="contact" value="" required></td>
                        </tr>
                        <tr>
                            <td class="labeltext"><label for="message">Message:</label></td>
                            <td class="textbox" >
                                <textarea id="message" class="dotted" name="message"></textarea>
                            </td>
                        </tr>
                        <tr>
                            <td colspan="2" class="submit"><input type = "submit" name = "submit" value = "Submit"></td>
                        </tr>
                    </table>
                    
                </form>
            </div> <!-- End #ContactContainer-->
            
            <div id="ContactBottom">
            
                <div id="SeeUs">
                    <div id="SeeTitle" class="bottomtitle">Come See Us</div>
                    
                    <div id="SeeContent" class="bottomcontent">
                        <p>123 Sugar Drive</p>
                        <p>Santa Monica, CA 90405</p>
                        <p></p>
                        <h3>Hours of Operation</h3>
                        <p>Mon - Sun: 8AM to 6PM</p>
                    </div><!-- END #SeeContent -->
                    
                </div> <!-- END #SeeUs -->
                
                <div id="TalkToUs">
                    <div id="TalkTitle" class="bottomtitle">Talk To Us</div>
                    <div id="TalkContent" class="bottomcontent">
                    
                        <p>Tel: 123.456.7890</p>
                        <p>Fax: 123.456.7891</p>
                        <p><a href="mailto:jo@simplyjic.com">jo@simplyjic.com</a></p>
                    
                    </div> <!-- END #TalkContent -->
                </div> <!-- END #TalkToUs -->
                
                <div id="ConnectUs">
                    <div id="ConnectTitle" class="bottomtitle">Connect With Us</div>
                    <div id="ConnectContent" class="bottomcontent">
                    
                        <a href="http://facebook.com" target="_blank">
                            <img src="images/contact/fb.png" alt="Facebook Icon"/>
                        </a>
                        
                        <a href="http://twitter.com" target="_blank">
                            <img src="images/contact/twitter.png" alt="Twitter Icon"/>
                        </a>
                        
                        <a href="http://instagram.com" target="_blank">
                            <img src="images/contact/ig.png" alt="Instagram Icon"/>
                        </a>
                        
                        <a href="http://yelp.com" target="_blank">
                            <img src="images/contact/yelp.png" alt="Yelp Icon"/>
                        </a>
                    
                    </div> <!-- END #ConnectContent -->
                </div> <!-- END #ConnectUs -->
                
                <div id="Disclaimer">
                    <div id="DisclaimerTitle" class="bottomtitle">Disclaimer</div>
                    <div id="DisclaimerContent" class="bottomcontent">
                    
                        <p>This website is intended for school purposes only.</p>
                    </div> <!-- END #DisclaimerContent -->
            
                </div> <!-- END #Disclaimer -->

            </div> <!-- End #ContactBottom -->
            
        </div><!-- END #Contact -->
        
<!-- END CONTACT SECTION -->

<!-- END OF CONTENT-->

    </body>
</html>