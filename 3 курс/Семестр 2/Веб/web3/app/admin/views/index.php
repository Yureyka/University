<main>
    <?php
    if ($parameters['isAdmin']){
        echo '<h1>Ты АДМИН</h1>';
        echo '<h2><form><button type = "button" name = "test" ><a href = "/admin/logOut">Выход</a></button></form></h2>';
    }else { ?>
    <div class="feedback-form alone">
        <form action="/admin/index" method="POST" name="form"
              onsubmit=" if (validateContactsForm()==false){return false;}else{return true}" onchange="activate()">
            <div class="test">
                <h2>ВХОД</h2>
                <input type="text" placeholder="Введите логин" id="login" name="login"><br><br>
                <input type="password" placeholder="Введите пароль" id="password" name="password"><br><br>
                <div class="form-buttons">
                    <input id="post" type="submit" class="helper-button" value="Отправить">
                    <input type="reset" class="helper-button" value="Сбросить">
                </div>
            </div>
            <?php } ?>
        </form>
    </div>
</main>