<main>
    <h1>Контакты</h1>
      <div class="default-container contact-container clearfix">
          <?php
          $errors = $model->validator->errors;
          if (!empty($errors)):
              ?>
              <div id="contactPageErrors">
                  <?php
                  foreach ($errors as $field => $massage) {
                      echo "<p>$massage</p>";
                  }
                  ?>
              </div>
          <?php
          endif;
          ?>
    <div class="feedback-form alone">
      <form action="/contacts/index" method = "POST" name = "form">
        <div class="test">
          <p class="test"><span class="jQtooltip" title="Введите имя в формате: Фамилия Имя Отчество">ФИО:</span></p><br>
          <input class="Red-green" type="text" placeholder="Введите ФИО" name="name" id="name" onblur="checkName()"><br>
   				<div class = "messageBlock" id="up-name"><p>Введите полное имя!</p></div>

          <p class="test"><span class="jQtooltip"
                                title="Введите номер в формате: +3XXXXXXXXXX или +7ХХХХХХХХХХ">Номер телефона:</span></p><br>
          <input class="Red-green" type="text" placeholder="Введите номер телефона" name="phone" id="phone" onblur="checkPhone()"><br>
          <div class = "messageBlock" id="up-phone"><p>Введите номер(9-11 цифр) с +3/+7</p></div>

          <p class="test"><label for="e-m"><span class="jQtooltip" title="Введите ваш имейл">Адрес эл.почты:</span></p><br>
          <input class="Red-green" type="text" placeholder="Введите E-mail" name="e-mail" id="mail" onblur="checkMail()"><br>
          <div class = "messageBlock" id="up-mail"><p>Введите корректный E-mail!</p></div>



            <p class="test"><label for="e-m"><span class="jQtooltip" title="Введите ваш имейл рокет чата">Адрес рокет чата:</span></p><br>
            <input class="Red-green" type="text" placeholder="Введите E-mail" name="e-mailR" id="mailК" onblur="checkMail()"><br>



          <form>
            <input name="sex" type="radio" value="male" id="qwe" checked>
            <p>М</p>
            <input name="sex" type="radio" value="female" id="qwe">
            <p>Ж</p>
          </form>
          <br>

          <p class="test">
            Выберите свой возраст:<br>
            <select>
              <option>16-20</option>
              <option>21-25</option>
              <option>26-30</option>
              <option>31-40</option>
              <option>41-50</option>
              <option>51-60</option>
            </select>
          </p>
          <table class="calendar">
            <tr>
              <td><label>Дата рождения:</label></td>
              <td>
                <input type="text" id="contactDate" style = " margin-top: 20px">
                <div class="calendarTop">
                  <select id="month" >
                    <option>January</option>
                    <option >February</option>
                    <option >March</option>
                    <option>April</option>
                    <option>May</option>
                    <option>June</option>
                    <option>July</option>
                    <option>August</option>
                    <option>September</option>
                    <option>October</option>
                    <option>November</option>
                    <option >December</option>
                  </select>
                  <select id="years">
                    <option>1990</option>
                    <option>1991</option>
                    <option>1992</option>
                    <option>1993</option>
                    <option>1994</option>
                    <option>1995</option>
                    <option>1996</option>
                    <option>1997</option>
                    <option>1998</option>
                    <option>1999</option>
                    <option>2000</option>
                    <option>2001</option>
                    <option>2002</option>
                    <option>2003</option>
                    <option>2004</option>
                    <option>2005</option>
                  </select>
                </div>
                <div class = "clearfix"  id ="calendar">
                  <script type="text/javascript">
                  Calendar();
                  </script>
                </div>
              </td>
            </tr>
          </table>
          <form onsubmit="valid(this)">
            <textarea placeholder="Оставьте свои пожелания..."></textarea>
            <!-- <div class = "messageBlock" id="up-e-mail" onblur= "checkE_mail()"><p>Введите текст сообщения</p></div> -->
          </form>
          <div class = "form-buttons">
            <input id = "post" type="submit" class = "helper-button" value = "Отправить">
            <input type= "reset" class = "helper-button" value = "Сбросить">
          </div>
<!--          <div class="expanded">-->
<!--            <div>-->
<!--              <div id="modalWindow">-->
<!--                <label id="modalLabel">ВЫ УВЕРЕНЫ?</label>-->
<!--                <input type="button" name="no" id="submitNo" value="НЕТ">-->
<!--                <input type="submit" name="yes" id="submitYes" value="ДА">-->
<!--              </div>-->
<!--            </div>-->
<!--          </div>-->
        </div>
      </form>
      </div>

    </main>

</div>
