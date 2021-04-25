<main>
    <h1>Гостевая книга</h1>
    <h2><form>
            <button type="button" name="test"><a href="/feedback/index">Загрузка сообщений гостевой книги</a></button>
        </form></h2>
    <div class="default-container contact-container clearfix">
        <?php
        $errors = $model->validator->errors;
        if (!empty($errors)):
            ?>
            <div id="contactPageErrors">
                <?php
                foreach ($errors as $field => $message) {
                    echo "<p>$message</p>";
                }
                ?>
            </div>
        <?php
        endif;
        ?>
    <div class="feedback-form alone">
        <form action="/guestsbook/guestsbook" method = "POST" name = "form" onsubmit=" if (validateContactsForm()==false){return false;}else{return true}"  onchange="activate()">
            <div class="test">
                <input type="text" placeholder="Введите фамилию" id="surname" name="surname"><br><br>
                <input type="text" placeholder="Введите имя" id="name" name="name"><br><br>
                <input type="text" placeholder="Введите отчество" id="patronymic" name="patronymic"><br><br>
                <input type="text" placeholder="Введите e-mail" id="e-mail" name="e-mail"><br><br>
                <form>
                    <textarea placeholder="Оставьте отзыв..." name="feedback"></textarea>
                </form>

                <div class = "form-buttons">
                    <input type="submit" class = "helper-button" value = "Отправить">
                    <input type= "reset" class = "helper-button" value = "Сбросить">
                </div>
                <table>
                    <caption>Отзывы посетителей</caption>
                    <thead>
                    <tr>
                        <th>Дата</th>
                        <th>ФИО</th>
                        <th>E-mail</th>
                        <th>Текст отзыва</th>
                    </tr>
                    </thead>
                    <tbody>
                    <?php foreach ($parameters['fileData'] as $key => $comment): ?>
                    <tr>
                        <td><?= $comment['date'] ?></td>
                        <td><?= $comment['fio'] ?></td>
                        <td><?= $comment['mail'] ?></td>
                        <td><?= $comment['feedback'] ?></td>
                    </tr>
                    <? endforeach; ?>


                    </tbody>

                </table>
            </div>
        </form>
    </div>
</main>
