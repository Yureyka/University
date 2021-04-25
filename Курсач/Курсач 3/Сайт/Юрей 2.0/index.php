<!DOCTYPE html>
<html lang="ru">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Турагенство Юрей</title>
    <link rel="shortcut icon" href="img\av.jpg" type="image/png">
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <link rel="stylesheet" href="css/style.css">
  </head>

  <body>
    <nav class="navbar navbar-expand-lg navbar-light navbg sticky-top">
      <button class="navbar-toggler pb-2" data-toggle="collapse" data-target="#navbarMenu">
        <span class="navbar-toggler-icon"></span>
      </button>
      <div class="collapse navbar-collapse" id="navbarMenu">
        <ul class="navbar-nav mr-auto ml-auto">
          <li class="nav-item active pr-5">
            <a href="main.html" class="nav-link nav-font">Главная</a>
          </li>
          <li class="nav-item pr-5">
            <a href="study.html" class="nav-link nav-font">Учеба</a>
          </li>
          <li class="nav-item pr-5">
            <a href="album.html" class="nav-link nav-font">Фотоальбом</a>
          </li>
          <li class="nav-item pr-5">
            <a href="test.html" class="nav-link nav-font">Тест</a>
          </li>
          <li class="nav-item pr-5">
            <a href="contact.html" class="nav-link nav-font">Контакт</a>
          </li>
          <li class="nav-item">
            <a href="about.html" class="nav-link nav-font">Обо мне</a>
          </li>
        </ul>
      </div>
    </nav>

    <section class="main-content container">
      <form class="" action="add.php" method="post">
        <label for="tur"><h4>Добавить запись</h4></label>
        <input type="text" name="tur" id="tur" class="form-control" placeholder="ФИО" required>
        <div class="invalid-feedback">Введите в формате: Фамилия Имя Отчество</div>
        <button type="submit" name="submit" class="btn btn-success"></button>
      </form>

    </section>

    <script src="https://code.jquery.com/jquery-3.3.1.slim.min.js" integrity="sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js" integrity="sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1" crossorigin="anonymous"></script>
    <script src="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js" integrity="sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM" crossorigin="anonymous"></script>
  </body>
</html>
