<main>
    <h1 id="top">Мои интересы</h1>
    <div id="anchors">
        <ul>
            <?php
            $hobbyLinks = Interest::HOBBY_LINKS;
            $hobbyNames = Interest::HOBBY_NAME;
            $hobbyDescriptions = Interest::HOBBY_DESCRIPTION;
            for ($i = 0; $i < count($hobbyLinks); $i++) {
                echo '<li><a href="#' . $hobbyLinks[$i] . '">' . $hobbyNames[$i] . '</a></li>';
            }
            ?>

        </ul>
    </div>
    <div class="border">
        <?php
        for ($i = 0; $i < count($hobbyLinks); $i++) {?>
             <h2 id="<?=  $hobbyLinks[$i]  ?>"> <?= $hobbyNames[$i] ?></h2>
             <div class="hobby">
             <img src="<?= Interest::$path . $hobbyLinks[$i] . ".jpg" ?>">
             <p>
             <br><br><br>
             <?=$hobbyDescriptions[$i]?>
             </p>
             <br><br>
             </div>
        <?php } ?>

    </div>
    <!--<aside>
    <a href="#top"><img src="img/raketa.jpg" alt="" title="Наверх &#8679;"></a>
  </aside>-->
    <a class="up" href="#top"><img class="up" src="/assets/img/raketa.jpg" alt="" title="Наверх &#8679;"></a>
</main>
