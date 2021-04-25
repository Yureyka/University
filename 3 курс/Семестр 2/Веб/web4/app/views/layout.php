<!DOCTYPE html>
<html lang="en" dir="ltr">
<head>
    <meta charset="utf-8">
    <title><?= $title ?></title>
    <link rel="stylesheet" href="/assets/css/web1Style.css">
    <script src="/assets/js/main_skript.js" defer></script>
    <script type="text/javascript" src="/assets/js/calendar.js"></script>
    <script type="text/javascript" src="/assets/js/jQuery.js"></script>
    <script type="text/javascript" src="/assets/js/CheckLogin.js"></script>
    <script type="text/javascript" src="/assets/js/AddComment.js"></script>
</head>
<body onload="mouseLis(); submenu(); date_time();">
<header>
    <div class="clock">
        <p id="digital_watch"></p>
    </div>
    <div class="limitation">
        <nav id="one">
            <ul class="menu">
                <li class="menu-item"><a class="navi" href="/page/main">Главная</a></li>
                <li class="menu-item"><a class="navi" href="/page/about">Обо мне</a></li>
                <li class="menu-item"><a class="navi" href="/page/interests">Мои интересы</a>
                    <ul class="sub-menu">
                        <li><a href="/page/interests/#Sport">Спорт</a></li>
                        <li><a href="/page/interests/#Music">Музыка</a></li>
                        <li><a href="/page/interests/#Books">Книги</a></li>
                    </ul>
                </li>
                <li class="menu-item"><a class="navi" href="/page/study">Учёба</a></li>
                <li class="menu-item"><a class="navi" href="/photo/index">Фотогалерея</a></li>
                <li class="menu-item"><a class="navi" href="/contacts/index">Контакты</a></li>
                <li class="menu-item"><a class="navi" href="/guestsbook/guestsbook">Гостевая книга</a></li>
                <li class="menu-item"><a class="navi" href="/blog/index">Мой блог</a></li>
                <?php
                if ($_SESSION['isUser']) {
                    echo '<li class="menu-item"><a style="font-weight: bold" class = "navi" href = "/authorization/logOut">Выйти</a></li>';
                } else {
                    echo '<li class="menu-item"><a style="font-weight: bold" class = "navi" href = "/authorization/index">Войти</a></li>';
                }
                ?>
                <?php if ($_SESSION['isUser']) {
                    echo '<li class="menu-item"><p><b>Пользователь:</b><br></p><p id= "userName">' . $_SESSION['userName'] . '</p></li>'; ?>
                <?php } ?>

            </ul>
        </nav>
    </div>
</header>
<?
include '../app/views/' . $contentView;
?>
<footer>
    <a href="https://vk.com/lerunchik_99"><img src="/assets/img/vk.png" alt="" title="Вконтакте"></a>
    <p>
        Email: lerunchik_99@mail.ru, тел. +79788125145
    </p>
</footer>

</body>

<div class="expanded">
    <div class="modalwindow">
        <h3>Добавить коментарий!</h3>
        <form onsubmit="return false;">
            <textarea name="comment" id="comment" placeholder="Введите ваш коментарий..." cols="40"
                      rows="10"></textarea><br>
        <button class="asyncButton" type="reset" onclick="CloseModalWindow();">Закрыть</button>
        <button class="asyncButton" type="submit" onclick="AddComment();" id="addB">Добавить</button>
        </form>
    </div>
</div>

</html>

