<main>
    <h1>Регистрация</h1>
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
            </div>
        <div class="feedback-form alone">
            <form action="/registration/index" method = "POST" name = "form">
                <div class="test">
                    <p class="test">Введите имя:</p><br>
                    <input type="text" placeholder="Введите ФИО" name="name" id="name"><br>

                    <p class="test">Введите e-mail:</p><br>
                    <input type="text" placeholder="Введите E-mail" name="e-mail" id="mail"><br>

                    <p class="test">Введите логин:</p><br>
                    <input type="text" placeholder="Введите логин" id="login" name="login"><p class="test" id="response"></p>

                    <div class = "form-buttons">
                        <input type="button" id="buttonCheckLogin" class = "helper-button" value = "Проверить занятость" onclick="CheckLogin()">
                    </div>

                    <p class="test">Введите пароль:</p><br>
                    <input type="text" placeholder="Введите пароль" id="password" name="password"><br><br>

                    <div class = "form-buttons">
                        <input id = "post" type="submit" class = "helper-button" value = "Отправить">
                        <input type= "reset" class = "helper-button" value = "Сбросить">
                    </div>
                </div>
            </form>
        </div>
    </div>
</main>


