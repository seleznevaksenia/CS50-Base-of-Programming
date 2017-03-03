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

<thead>
        <tr>
            <th>Transaction</th>
            <th>Date/Time</th>
            <th>Symbol</th>
            <th>Number</th>
            <th>Price</th>
        </tr>
    </thead>

  
  <tbody>
  <?php foreach ($history as  $histor): ?>

    <tr>
        <td><?= $histor["transaction"] ?></td>
        <td><?= $histor["time"] ?></td>
        <td><?= $histor["symbol"] ?></td>
        <td><?= $histor["number"] ?></td>
        <td><?= number_format($histor["price"],3) ?></td>
    </tr>
  
    <?php endforeach ?>
    
 </table>
</div>
<tbody>
