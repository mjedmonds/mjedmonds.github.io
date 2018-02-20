<?php
/* 
    Example php order form created using form and table classes from dyn-web.com
    For demos, documentation and updates, visit http://www.dyn-web.com/code/order_form/
    
    Released under the MIT license
    http://www.dyn-web.com/business/license.txt
*/

$PRODUCTS = array(
    // product abbreviation, product name, unit price
    // follow valid name/ID rules for product abbreviation 
    array('choc_macaron', 'Chocolate', 2),
    array('cookiedough_macaron', 'Cookie Dough', 2),
    array('pistachio_macaron', 'Pistachio', 2),
    array('raspberry_macaron', 'Raspberry', 2),
    array('saltedcaramel_macaron', 'Salted Caramel', 2),
    array('strawberry_macaron', 'Strawberry', 2)
);

// functions for example 2 order form

function getOrderForm2() {
    global $PRODUCTS;
    $tbl = new HTML_Table('', 'demoTbl');
    $frm = new HTML_Form();
    
    // header row
    $tbl->addRow();
        $tbl->addCell('Product', 'first', 'header');
        $tbl->addCell('Price', '', 'header');
        $tbl->addCell('Quantity', '', 'header');
        $tbl->addCell('Totals', '', 'header');
    
    // display product info/form elements
    foreach($PRODUCTS as $product) {
        list($abbr, $name, $price) = $product;
        
        // quantity text input
        $qty_el = $frm->addInput('text', $abbr . '_qty', 0, 
            array('size'=>4, 'class'=>'cur', 'pattern'=>'[0-9]+', 'placeholder'=>0, 
                  'onchange'=>'getProductTotal(this)',
                  'onclick'=>'checkValue(this)', 'onblur'=>'reCheckValue(this)') );
        
        // total text input
        $tot_el = $frm->addInput('text', $abbr . '_tot', 0, array('readonly'=>true, 'size'=>8, 'class'=>'cur') );
        
        // price hidden input
        $price_el = $frm->addInput('hidden', $abbr . '_price', $price);
        
        $tbl->addRow();
            $tbl->addCell($name);
            $tbl->addCell('$' . number_format($price, 2) . $price_el, 'cur' );
            $tbl->addCell( $qty_el, 'qty');
            $tbl->addCell( $tot_el );
    }
    
    // total row
    $tbl->addRow();
        $tbl->addCell( 'Total: ', 'total', 'data', array('colspan'=>3) );
        $tbl->addCell( $frm->addInput('text', 'total', 0, array('readonly'=>true, 'size'=>8, 'class'=>'cur') ) );
        
        
    // additional fields for contact info
    $tbl->addRow();
        $tbl->addCell('First Name: ', 'label');
        $tbl->addCell(
            $frm->addInput('text', 'first_name', '', array(
                'size'=>36, 
                'required'=>true ) ), '', 'data', array('colspan'=>3)
        );
        
    $tbl->addRow();
        $tbl->addCell('Last Name: ', 'label');
        $tbl->addCell(
            $frm->addInput('text', 'last_name', '', array(
                'size'=>36, 
                'required'=>true) ),
                '', 'data', array('colspan'=>3)
        );
        
        
    $tbl->addRow();
        $tbl->addCell('Email: ', 'label');
        $tbl->addCell(
            $frm->addInput('email', 'email', '', array(
                'size'=>36,
                'pattern'=>'^[\w\+\'\.-]+@[\w\'\.-]+\.[a-zA-Z]{2,}$',
                'required'=>true
                ) ), '', 'data',
            array('colspan'=>3)
        );
    
    $tbl->addRow();
        $tbl->addCell('Phone: ', 'label');
        $tbl->addCell(
            $frm->addInput('tel', 'phone', '', array(
                'size'=>36, 
                'pattern'=>'[0-9]{3}-[0-9]{3}-[0-9]{4}',
                'placeholder'=>'xxx-xxx-xxxx',
                'required'=>true) ),
                'last', 'data', array('colspan'=>3)
        );

    // submit button
    $tbl->addRow();
        $tbl->addCell( $frm->addInput('submit', 'submit', 'Submit'),
                'submit', 'data', array('colspan'=>4) );
        
    $frmStr = $frm->startForm('order_result.php', 'post', '', array('onsubmit'=>'return checkSubmit(this);') ) .
        $tbl->display() . $frm->endForm();
    
    
    return $frmStr;
}


// for js
function getProductAbbrs() {
    global $PRODUCTS;
    foreach ( $PRODUCTS as $product ) {
        $ar[] = $product[0];
    }
    return $ar;
}


// functions for example 2 order form submission result page

function sendAdminEmail($total, $order) {
    $admin_email = 'jo@simplyjic.com';
    $subject = 'Order Information';
    $name = stripslashes( strip_tags( $_POST['first_name'] ) ) . ' ' . 
        stripslashes( strip_tags( $_POST['last_name'] ) );
    
    $email = stripslashes( strip_tags( $_POST['email'] ) );
    // check for valid email address
    $regex = '/^[\w\+\'\.-]+@[\w\'\.-]+\.[a-zA-Z]{2,}$/';
    if ( !preg_match($regex, $_POST['email']) ) {
        // don't send email
        echo '<p>Your email appears to be invalid. Please hit your browser back button to return to the previous page to enter a vaild email address.</p>';
        return;
    }
    $phone = stripslashes( strip_tags( $_POST['phone'] ) );
    $msg_body = 
    "Items ordered: 
    $order 
    Total: $$total
    
    Customer Information
    
    Name: $name
    Email: $email
    Phone: $phone";
    
    @mail($admin_email, $subject, $msg_body );
}


function handleOrderInfo() {
    global $PRODUCTS;;
    $str = ''; $total = 0; $order = '';
    while ( list($key, $val) = each($_POST) ) {
        // Check for valid quantity entries
        if ( ( strpos($key, '_qty') !== false ) && is_int((int)$val) && $val > 0  ) { 
            $pt = strrpos($key, '_qty'); // get product abbr
            $name_pt = substr( $key, 0, $pt);
            
            foreach($PRODUCTS as $product) {
                list($prod_abbr, $prod_name, $prod_price) = $product;
                if ($prod_abbr == $name_pt) {
                    $sub_tot = $val * $prod_price;
                    // build string to display order info
                    $str .= "<p>$val $prod_name at $" . number_format($prod_price, 2) . 
                        ' each for $' . number_format($sub_tot, 2) . '</p>';
                    $total += $sub_tot;
                    $order .= "\r$val $prod_name\r";
                }
            }
        }
    }
    $total = number_format($total, 2);
    $order = rtrim($order, ', ');
    if ( $str === '' ) {
        $str = '<p>You didn\'t order anything.</p>';
    } else {
        $str = "<h2>Your Order:</h2>$str<p><strong>Total: $$total</strong></p>
        <p>We will contact you as soon as possible. Thank you!</p>";
        sendAdminEmail($total, $order);
    }
    
    return $str;
}
?>