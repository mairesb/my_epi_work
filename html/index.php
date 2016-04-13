
<?php
declare(strict_types=1);
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title>coucou</title>
  </head>
  <body>
    <form action"test.php" method="get">
      <label for="name"> Votre nom de batard </label>
      <input type="text" name="name"></input>
      <label for="name"> Votre prenom de batard </label>
      <input type="text" name="prename"></input>
      <input type="submit"/>
    <?php
    //echo var_dump($toto);
    $toto = [
              "1" => "toto", "2" => "caca"
            ];
    foreach ($toto as $k => $value)
     {
      echo "<p style=\"color: RED;\">";
      echo $value;
      echo "<p>";
    }
    echo "<p style=\"color: RED;\">";
    echo var_dump($toto);
    echo "</p>";

    function totoo(int $i)
    {
      echo "<p style=\"color: RED;\">";
      echo $i;
      echo "</p>";
    }
    totoo(1);
    ?>
  </body>
</html>
