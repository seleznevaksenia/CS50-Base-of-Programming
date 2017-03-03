<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("password_form.php", ["title" => "Password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["old"] )|| empty($_POST["password"]) || empty($_POST["confirmation"])){
          apologize("Enter old and new password and submit new");  
        }
        $query = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        if(!password_verify($_POST["old"], $query[0]["hash"]) || $_POST["password"] != $_POST["confirmation"])
          apologize("Inalid submission");  
        else{
           
    $new_password =CS50::query("UPDATE users SET hash = ? WHERE id = ?",password_hash($_POST["new"],PASSWORD_DEFAULT), $_SESSION["id"]);
    redirect("/");
    exit;
    }}
?>