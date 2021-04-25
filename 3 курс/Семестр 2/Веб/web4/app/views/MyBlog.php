<main>
    <h1>Мой блог</h1>
    <h2>
        <form>
            <button type="button" name="test"><a href="/postloader/index">Загрузка сообщений блога</a></button>
        </form>
    </h2>

    <div class="test">
        <h2>Записи блога:</h2><br>
        <ul id="blogMessage">
            <?php foreach ($parameters['tableData'] as $key => $post):
                $path = "/assets/userimage/" . $post['imageName'];
                if ($post['theme'] != "") { ?>
                    <li>
                        -------------------------------------------------------------------------------------------------
                    </li><br>
                    <li><?= $post['dateTime'] ?></li>
                    <li>Тема сообщения: <?= $post['theme']; ?></li>
                    <li><img src="<?= $path ?>"></li>
                    <li>Сообщение: <?= $post['message'] ?></li>
                    <?php if ($_SESSION['isUser']) { ?>
                        <li>
                            <button style="background: #c5b7db; font-size: 28px" class="addComment" value="<?= $post['id']; ?>">Добавить комментарий</button>
                        </li>
                    <?php } ?>
                    <li>
                        <?php
                        $comment = new Comment();
                        $comments = $comment->findUserComments($post['id']);
                        if($comments != 0) { ?>
                        <div style="border: 7px solid #ac8dc9;" class="commentDiv" id="comment<?= $post['id']; ?>">
                                <?php foreach ($comments as $comment){
                                    echo '<p><b>Автор:   </b><i>' . $comment['fio'] . '</i><br>' . $comment['comment'] . '</p>';
                                } ?>
                        </div>
                         <?php }else{ ?>
                            <div class="commentDiv" id="comment<?= $post['id']; ?>">
                        <?php }
                            ?>
                    </li>
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

