<main>
    <h1>Статистика посещений</h1>

    <div class="test">
        <ul id="blogMessage">
            <?php foreach ($parameters['statsData'] as $key => $comment):
                if ($comment['dateTime'] != "") { ?>

                    <li>
                        -------------------------------------------------------------------------------------------------
                    </li><br>
                    <li><?= $comment['dateTime'] ?></li>
                    <li>Web-страница посещения: <?= $comment['webPage']; ?></li>
                    <li>IP-адрес компьютера посетителя: <?= $comment['ip']; ?></li>
                    <li>Имя хоста компьютера посетителя: <?= $comment['hostName']; ?></li>
                    <li>Название браузера, который использовал посетитель: <?= $comment['browserName'] ?></li>

                <? }
            endforeach; ?>
        </ul>
        <ul id="pagination">
            <li>
                <?php
                $paginationInfo = $parameters['paginationInfo'];
                $numOfPages = $paginationInfo['numOfPages'];
                $recordsOnPage = $paginationInfo['recordsOnPage'];

                for ($i = 0; $i < $numOfPages; $i++) {
                    $page = $i + 1;
                    $lowLimit = $i * $recordsOnPage + 1;
                    $upperLimit = ($i * $recordsOnPage) + $recordsOnPage;
                    if ($i == $numOfPages - 1) {
                        $upperLimit = $paginationInfo['count'];
                    }
                    if ($lowLimit == $upperLimit) {
                        $limitString = $upperLimit;
                    } else {
                        $limitString = $lowLimit . "-" . $upperLimit;
                    }
                    echo "<a id='pagination' href='/admin/stats?page=$page'>$limitString</a>";
                } ?>
            </li>
        </ul>
    </div>
</main>
