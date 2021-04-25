<main>
    <h1>Авторизация</h1>
    <div class="default-container contact-container clearfix">
        <?php
        $errors = $model->validator->errors;
        echo '<div id="contactPageErrors">';
        if (!empty($errors)):
            ?>

            <?php
            foreach ($errors as $field => $massage) {
                echo "<p>$massage</p>";
            }
            ?>

        <?php
        endif;
        ?>
        <?php
        //$existUser = $parameters['existUser'];
        if($_SESSION['isUser']){
            echo "<p style='color: limegreen'>Авторизация прошла успешно</p>";
        } ?>
    </div>
    <?php if(!$_SESSION['isUser']) {?>
    <div class="feedback-form alone">
        <form action="/authorization/index" method = "POST" name = "form">
            <div class="test">
                <p class="test">Введите логин:</p><br>
                <input type="text" placeholder="Введите логин" id="login" name="login"><br>

                <p class="test">Введите пароль:</p><br>
                <input type="password" placeholder="Введите пароль" id="password" name="password"><br><br>

                <div class = "form-buttons">
                    <input id = "post" type="submit" class = "helper-button" value = "Войти">
                    <input type= "reset" class = "helper-button" value = "Сбросить"><br>
                </div>
                <h2 style="text-align: left; margin-left: 65px;">
                    <form>
                        <button style="font-size: 32px; " type="button" name="test"><a href="/registration/index">Регистрация</a></button>
                    </form>
                </h2>
            </div>
        </form>
    </div>
    <?php } ?>
    </div>
</main>





