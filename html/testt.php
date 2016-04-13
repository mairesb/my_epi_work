<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title>coucou</title>
  </head>
  <body>
    <form action"testt.php" method="post">
      <label for="name"> Votre nom de batard </label>
      <input type="text" name="name"></input>
      <label for="name"> Votre prenom de batard </label>
      <input type="text" name="prename"></input>
      <input type="submit" name="submit"/>
      <?php
          $name = $_POST['name'];
          $password = $_POST['prename'];
          if (preg_match("#^[a-z][2-4].\\b#", $name))
            echo $name;
          else
            echo "toto";
          echo $password;
       ?>
  </body>
</html>
