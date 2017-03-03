<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

   $places = CS50::query("SELECT * FROM places WHERE MATCH(postal_code, place_name) AGAINST (?)", $_GET["geo"]); // TODO: search database for places matching $_GET["geo"], store in $places

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));//Возвращает JSON строку (string) либо или FALSE в случае возникновения ошибки.
?>