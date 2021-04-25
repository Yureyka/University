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
              <li class="menu-item"><a class = "navi" href = "/admin/index">Вход</a></li>
              <li class="menu-item"><a class = "navi" href = "/admin/blogEditor">Редактор блога</a></li>
              <li class="menu-item"><a class = "navi" href = "/admin/feedback">Загрузка сообщений гостевой книги</a></li>
              <li class="menu-item"><a class = "navi" href = "/admin/stats">Статистика посещений</a></li>
          </ul>
      </nav>
    </div>
  </header>
  <?
  include '../app/admin/views/'.$contentView;
  ?>
  <footer>
    <a href = "https://vk.com/lerunchik_99"><img src = "/assets/img/vk.png" alt = "" title = "Вконтакте"></a>
    <p>
        Email: lerunchik_99@mail.ru, тел. +79788125145
    </p>
  </footer>
</body>
</html>

