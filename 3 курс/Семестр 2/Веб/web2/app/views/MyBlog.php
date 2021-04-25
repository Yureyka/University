<main>
    <h1>Мой блог</h1>
    <h2>
        <form>
            <button type="button" name="test"><a href="/blogpost/index">Редактор блога</a></button>
            <button type="button" name="test"><a href="/postloader/index">Загрузка сообщений блога</a></button>
        </form>
    </h2>

    <div class="test">
        <h2>Записи блога:</h2><br>
        <ul id="blogMessage">
            <?php foreach ($parameters['tableData'] as $key => $comment):
                $path = "/assets/userimage/" . $comment['imageName'];
                if ($comment['theme'] != "") { ?>

                    <li>
                        -------------------------------------------------------------------------------------------------
                    </li><br>
                    <li><?= $comment['dateTime'] ?></li>
                    <li>Тема сообщения: <?= $comment['theme']; ?></li>
                    <li><img src="<?= $path ?>"></li>
                    <li>Сообщение: <?= $comment['message'] ?></li>

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
                    echo "<a id='pagination' href='/blog/index?page=$page'>$limitString</a>";
                } ?>
            </li>
        </ul>
    </div>
</main>
