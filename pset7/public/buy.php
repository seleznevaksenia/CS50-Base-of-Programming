<?php
    // configuration
    require("../includes/config.php");
   
    
    //если записей в портфолио нету...то ошибка при открытии вкладки
        $cash = CS50::query("SELECT * FROM users WHERE id = ?", $_SESSION["id"]);
        $cash_=$cash[0]["cash"];
        if($cash_==0)
        {
            apologize("You have not money!");
        }
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
         render("buy_form.php", ["title" => "Buy"]);
        
    }
    else if($_SERVER["REQUEST_METHOD"] == "POST")
    
    {   
        //если в поле вобора юзер не выбрал акцию для продажи или отрицательное количество
        if (empty($_POST["Symbol"]) || empty($_POST["Share"]))
        {
            apologize("You must select a stock to buy and non-negative quontity");
        }
        if (preg_match("/^\d+$/", $_POST["Share"]) == false)
        {
            apologize("You must enter a whole, positive integer.");
        }
        

        $stock = lookup($_POST["Symbol"]);
       
        if ($stock != false && $cash_>= $stock["price"]*$_POST["Share"]){ //&& $_POST["Share"] > 0){
        $query = CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES (?, ?, ?)
        ON DUPLICATE KEY UPDATE shares = shares + ?
        ", $_SESSION["id"],$_POST["Symbol"],$_POST["Share"] ,$_POST["Share"] );

        
        //запросы
       
        $queryes = CS50::query("UPDATE users SET cash = cash - ? WHERE id = ?",$_POST["Share"]* $stock["price"], $_SESSION["id"]);
        if ($queryes === false)
            {
               apologize("Error buying shares.");
            }
        
        
      $status = 'BUY';
        
        //добавление записи в историю
        $query = CS50::query("INSERT INTO History (transaction,symbol,number,price,time,user_id) VALUES (?,?,?,?,now(),?)"
        ,$status,strtoupper($_POST["Symbol"]),$_POST["Share"] ,$stock["price"],$_SESSION["id"]);
      
     redirect("/");
    }
    else apologize("Invalid share or Symbol");
    }
?>