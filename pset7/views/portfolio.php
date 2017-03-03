

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

<div align="center">
 <table class="brd">
     
  <tr>
   <td><p><?= "symbol"?></p></td>
   <td><p><?= "name" ?></p></td>
   <td><p><?= "shares" ?></p></td>
   <td><p><?= "price" ?></p></td>
   <td><p><?= "total" ?></p></td>
  </tr>
  
  
  <?php foreach ($positions as $position): ?>

    <tr>
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["name"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= number_format($position["price"],3) ?></td>
        <td><?= $position["total"] ?></td>
    </tr>
  
    <?php endforeach ?>
    <tr>
        <td><?= "CASH" ?></td>
        <td colspan="3"><?= "&nbsp"?></td>
        <td><?= "$cash" ?></td>
    </tr>
 </table>
</div>
<div>
<img src="/img/1.png" width=300 height=200 align="left">
</div>



