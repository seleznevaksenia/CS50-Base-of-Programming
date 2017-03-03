<?php

    // configuration
    require("../includes/config.php"); 
 
    $rows = CS50::query ("SELECT symbol, shares FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    $cash = CS50:: query ("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
    $cash_ = $cash[0]["cash"];

    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
        $positions[] = [
            "name" => $stock["name"],
            "price" => $stock["price"],
            "shares" => $row["shares"],
            "symbol" => $row["symbol"],
            "total"  => sprintf("%.3f",$stock["price"]*$row["shares"])
        ];
        }
    }
    // render portfolio
    render("portfolio.php", ["positions" => $positions,"cash" => $cash_, "title" => "Portfolios"]);


?>
