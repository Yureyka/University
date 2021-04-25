<main>
    <h1>Загрузка сообщений гостевой книги</h1>

            <div class="feedback-form alone">
                <form action="/admin/feedback" enctype="multipart/form-data" method = "POST" name = "form" onsubmit=" if (validateContactsForm()==false){return false;}else{return true}"  onchange="activate()">
                    <div class="test">
                        <p class="test">Загрузите файл с отзывами:</p><br>
                        <input class="Red-green" type="file" name="feedback"
                               id="feedback"><br>

                        <div class = "form-buttons">
                            <input type="submit" class = "helper-button" value = "Отправить">
                            <input type= "reset" class = "helper-button" value = "Сбросить">
                        </div>

                    </div>
                </form>
            </div>
</main>
