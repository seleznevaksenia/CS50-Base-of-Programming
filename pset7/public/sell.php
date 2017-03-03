<?php
    // configuration
    require("../includes/config.php");
   
    
    //если записей в портфолио нету...то ошибка при открытии вкладки
        $positions = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        //$Symbol = $positions[0]["symbol"];
        if(count($positions)==0)
        {
            apologize("You can not sell any shares!");
        }
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
         render("sell_form.php", ["title" => "Sell"]);
        
    }
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {   
        //если в поле вобора юзер не выбрал акцию для продажи
        if (!isset($_POST["Symbol"]))
        {
            apologize("You must select a stock to sell.");
        }
       
        $stock = lookup($_POST["Symbol"]);
        
        $query = CS50::query("SELECT shares FROM portfolios WHERE user_id = ? AND symbol = ? ", $_SESSION["id"],$_POST["Symbol"]);
        $shares = number_format($query[0]["shares"]*$stock["price"],3); //233,200
        
        
        
        //запросы
        $queryes1 = CS50::query("DELETE FROM portfolios where user_id = ? and symbol = ?", $_SESSION["id"], strtoupper($_POST["Symbol"]));
        if ($queryes1 === false)
        {
            apologize("Error while selling shares.");
        }
        $queryes = CS50::query("UPDATE users SET cash = cash + ? WHERE id = ?",$shares, $_SESSION["id"]);
        if ($queryes === false)
            {
               apologize("Error while selling shares.");
            }
        
        $status = 'SELL';
        $value =$query[0]["shares"];
        //добавление записи в историю
        $query = CS50::query("INSERT INTO History (transaction,symbol,number,price,time,user_id) VALUES (?,?,?,?,now(),?)"
        ,$status,strtoupper($_POST["Symbol"]),$value,$stock["price"],$_SESSION["id"]);
      
     redirect("/");
    }
?>