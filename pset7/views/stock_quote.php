<style type="text/css">
    table {
        border-collapse: collapse;
         background: maroon; /* Цвет фона таблицы */
    color: white; /* Цвет текста */
    }
    table th,
    table td {
        padding: 0 3px;
    }
    table.brd th,
    table.brd td {
        border: 1px solid #000;
    }
</style>

<h1>Last price</h1>
<div align="center">
 <table class="brd">
  <tr>
   <td><p><?= "symbol"?></p></td>
   <td><p><?= "stock" ?></p></td>
   <td><p><?= "price" ?></p></td>
  </tr>
  <tr>
   <td><p><?= "$symbol"?></p></td>
   <td><p><?= "$name"?></p></td>
   <td><p><?= number_format("$price", 2, ',', ' ')?></p></td>
  </tr>
  
 </table>
</div>
<div>
    or <a href="quote.php"> lookup another stock </a>
</div>

