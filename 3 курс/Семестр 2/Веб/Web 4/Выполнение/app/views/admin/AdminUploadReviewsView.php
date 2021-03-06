<section class="content container">
    <h2 class="mb-4">Загрузка отзывов</h2>
    <form action="/admin/uploadreviews/create" method="POST" enctype="multipart/form-data">
        <div class="input-group">
            <div class="custom-file">
                <input type="file" name="file" accept=".inc" class="form-control" id="uploadInput" aria-describedby="uploadInputBtn">
                <label class="custom-file-label" for="uploadInput">Загрузите отзывы для гостевой книги</label>
            </div>
            <div class="input-group-append">
                <button class="btn btn-outline-primary" type="submit" id="uploadInputBtn">Отправить файл</button>
            </div>
        </div>
    </form>
    <div class='result-block'>
        <?php 
            if (isset($data['empty'])) {
                echo "<p class='result-block__item error'>Загрузите файл</p>";
            } elseif (isset($data['result'])) {
                echo "<p class='result-block__item success'>Файл был отправлен</p>";
            } elseif (isset($data['error'])) {
                echo "<p class='result-block__item error'>Произошла ошибка</p>";
            }
        ?>
    </div>
    <script>
        const inputFile = document.getElementById("uploadInput");
        const inputLabel = document.getElementsByClassName("custom-file-label")[0];
        inputFile.addEventListener("change", e => {
            inputLabel.innerHTML = e.target.files[0].name;
        });
    </script>
</section>