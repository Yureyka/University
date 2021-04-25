<!DOCTYPE html>
<html lang="en" dir="ltr">
<head>
  <meta charset="utf-8">
    <title><?=$title?></title>
  <link rel="stylesheet" href="/assets/css/web1Style.css">
  <script src = "/assets/js/main_skript.js" defer></script>
    <script type="text/javascript" src="/assets/js/calendar.js"></script>
</head>
<body onload="mouseLis(); submenu(); date_time();">
  <header>
    <div class="clock">
      <p id="digital_watch"></p>
    </div>
    <div class="limitation">
      <nav id="one">
          <ul class="menu">
              <li class="menu-item"><a class = "navi" href = "/page/main">Главная</a></li>
              <li class="menu-item"><a class = "navi" href = "/page/about">Обо мне</a></li>
              <li class="menu-item"><a class = "navi" href = "/page/interests">Мои интересы</a>
                  <ul class="sub-menu">
                      <li><a href="/user/interests/#Sport">Спорт</a></li>
                      <li><a href="/user/interests/#Music">Музыка</a></li>
                      <li><a href="/user/interests/#Books">Книги</a></li>
                  </ul>
              </li>
              <li class="menu-item"><a class = "navi" href = "/page/study">Учёба</a></li>
              <li class="menu-item"><a class = "navi" href = "/photo/index">Фотогалерея</a></li>
              <li class="menu-item"><a class = "navi" href = "/contacts/index">Контакты</a></li>
              <li class="menu-item"><a class = "navi" href = "/guestsbook/guestsbook">Гостевая книга</a></li>
              <li class="menu-item"><a class = "navi" href = "/blog/index">Мой блог</a></li>
          </ul>
      </nav>
    </div>
  </header>
  <?
  include '../app/views/'.$contentView;
  ?>
  <footer>
    <a href = "https://vk.com/lerunchik_99"><img src = "/assets/img/vk.png" alt = "" title = "Вконтакте"></a>
    <p>
        Email: lerunchik_99@mail.ru, тел. +79788125145
    </p>
  </footer>
</body>
</html>

