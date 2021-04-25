<main>
    <h1>Редактор блога</h1>
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
            <form action="/blogpost/index" enctype="multipart/form-data" method="POST" name="form">
                <div class="test">

                    <p class="test">Введите тему сообщения:</p><br>
                    <input class="Red-green" type="text" placeholder="Введите тему сообщения: " name="theme" id="theme"><br>

                    <p class="test">Загрузите изображение:</p><br>
                    <input class="Red-green" type="file" name="photo"
                           id="photo"><br>

                    <p class="test">Введите сообщение:</p><br>

                    <textarea placeholder="Введите сообщение..." name="feedback"></textarea>


                    <div class="form-buttons">
                        <input type="submit" class="helper-button" value="Отправить">
                        <input type="reset" class="helper-button" value="Сбросить">
                    </div>
                    <h2>Записи блога:</h2><br>
                    <ul id="blogMessage">
                        <?php foreach ($parameters['tableData'] as $key => $comment):
                            if ($comment['theme'] != "") {
                                $path = "/assets/userimage/" . $comment['imageName']; ?>

                                <li>
                                    -------------------------------------------------------------------------------------------------
                                </li><br>
                                <li>Тема сообщения: <?= $comment['theme']; ?></li>
                                <li><img src="<?= $path ?>"></li>
                                <li>Сообщение: <?= $comment['message'] ?></li>
                                <li><?= $comment['dateTime'] ?></li>

                            <? }
                        endforeach; ?>
                    </ul>

                    <ul id="pagination">
                        <li>
                            <?php
                            $paginationInfo = $parameters['paginationInfo'];
                            $numOfPages = $paginationInfo['numOfPages'];
                            $postsOnPage = $paginationInfo['postsOnPage'];

                            for ($i = 0; $i < $numOfPages; $i++) {
                                $page = $i + 1;
                                $lowLimit = $i * $postsOnPage + 1;
                                $upperLimit = ($i * $postsOnPage) + $postsOnPage;
                                if ($i == $numOfPages - 1) {
                                    $upperLimit = $paginationInfo['postsCount'];
                                }
                                if ($lowLimit == $upperLimit) {
                                    $limitString = $upperLimit;
                                } else {
                                    $limitString = $lowLimit . "-" . $upperLimit;
                                }
                                echo "<a id='pagination' href='/blogpost/index?page=$page'>$limitString</a>";
                            } ?>
                        </li>
                    </ul>
            </form>
        </div>
    </div>
    </div>
</main>