<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select class="form-control" name="свSymbol">
                <option disabled selected value="">Symbol</option>
                <?php
                    
        $content = CS50::query("SELECT symbol FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        foreach($content as $item)
        {
          echo("<option value='{$item["symbol"]}'>{$item["symbol"]}</option>");
        }
                ?>
            </select>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">Sell</button>
        </div>
    </fieldset>
</form>