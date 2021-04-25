<main>
    <h1>Загрузка сообщений блога</h1>

    <div class="feedback-form alone">
        <form action="/postloader/index" enctype="multipart/form-data" method = "POST" name = "form" onsubmit=" if (validateContactsForm()==false){return false;}else{return true}"  onchange="activate()">
            <div class="test">
                <p class="test">Загрузите файл с записями:</p><br>
                <input class="Red-green" type="file" name="record"
                       id="record"><br>
                <p></p>

                <div class = "form-buttons">
                    <input type="submit" class = "helper-button" value = "Отправить">
                    <input type= "reset" class = "helper-button" value = "Сбросить">
                </div>

            </div>
        </form>
    </div>
</main>
