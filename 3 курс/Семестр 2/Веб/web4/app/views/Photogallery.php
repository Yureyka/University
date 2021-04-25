<main>
        <h1>Фотогалерея</h1>
        <div class="photo">
            <table class='photo' id='Photogallery'>";
                <?php
                for ($i = 0; $i < 5; $i++) { ?>
                <tr class='photo'>
                    <?php for ($j = 0; $j < 3; $j++) {
                    $imgName = ($j + 1) + (3 * $i);
                    $imgLink = "http://" . $_SERVER["SERVER_NAME"] . $model->path . $imgName . ".jpg"; ?>
                     <td class='photo'>
                     <figure>
                     <img src = " <?= $imgLink ?>" title = "<?= $model::TITLES[$imgName-1] ?>">
                     <figcaption> <?= $model::TITLES[$imgName-1] ?></figcaption>
                     </td>
            <?php }
            } ?>
            </table>;

        </div>
    </main>
</div>
<div class="expanded">
    <div class="cross"><img src="img/arrow.png" alt="close"></div>
    <div class="bigPhoto"></div>
    <div id="prev">Предыдущее</div>
    <div id="next">Следующее</div>
</div>

