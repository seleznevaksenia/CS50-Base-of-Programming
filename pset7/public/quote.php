<?php

    // configuration
    require("../includes/config.php");

    //if user reached page via GET (as by clicking a link or via redirect)
   if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "quote"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"] )){
          apologize("Enter symbol");  
        }
        $stock = lookup($_POST["symbol"]);
        if($stock  == false){
          apologize("I can't download this symbol");  
        }
        else{
            $stock = lookup($_POST["symbol"]);
            render("stock_quote.php", ["symbol" => $stock["symbol"],
            "name" => $stock["name"],
            "price" => $stock["price"]
            ]);
        }
            
    }
?>