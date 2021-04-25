  <main>
<!--    <div class="testic"  id = "one">-->
<!--      <a class="testic" href="/user/main">Вернуться на главную</a>-->
<!--    </div>-->
    <h1>Пройдите тест</h1>
      <div>
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
      <?php
      $isTestPassed = false;

      if(empty($errors)){
          $results = $model->validator->scores;
          $isTestPassed = true;
      }
      if (($isTestPassed)):
          ?>
          <div id="contactPageErrors">
              <?php

              echo "<p style='color: ivory'>Ваш результат " . $results['numOfCorrectAns'] ." / 3 !</p>";

              ?>
          </div>
      <?php
      endif;
      ?>
      </div>

    <div class="feedback-form alone">
      <form action="/test/index" method = "POST" name = "form" onsubmit=" if (validateTestForm()==false){return false;}else{return true}"  onchange="activate()">
        <div class="test">
          <input type="text" placeholder="Введите ФИО" id="name" name="name"><br>
          <select name="group">
            <optgroup label="1 курс">
              <option>ИС/б-11</option>
              <option>ИС/б-12</option>
              <option>ПИ/б-11</option>
            </optgroup>
            <optgroup label="2 курс">
              <option>ИС/б-21</option>
              <option>ИС/б-22</option>
              <option>ПИ/б-21</option>
            </optgroup>
            <optgroup label="3 курс">
              <option>ИС/б-31</option>
              <option>ИС/б-32</option>
              <option>ПИ/б-31</option>
            </optgroup>
            <optgroup label="4 курс">
              <option>ИС/б-41</option>
              <option>ИС/б-42</option>
              <option>ПИ/б-41</option>
            </optgroup>
          </select>
          <h2>Предмет: Безопасность жизнедеятельности</h2>
          <p class="test">
            1. По скорости распространения огня и высоте пламени лесные пожары подразделяются на:<br>
            <select name="ans1">
              <option>сильные</option>
              <option>слабые</option>
              <option value="гигантские">гигантские</option>
              <option>средние</option>
              <option>мощные</option>
              <option>ошеломительные</option>
              <option>страшные</option>
            </select>
          </p>
          <p class="test">
            2. Каким значением характеризуется лёгкая тяжесть работы по потреблению кислорода и энерготратам ?<br>
          </p>
          <input type='text' name="ans2" value="4">
          <!--<input type="text" placeholder="Введите ответ" id="que" name="question"><br>-->
          <p class="test">
            3. Какой фазы работоспособности не существует?<br>
            <label class="container" for = "check1">Утомление
              <input type="checkbox" checked="checked" name="ans3" value="Утомление" id="check1">
              <span class="checkmark"></span>
            </label>
            <label class="container" for = "check2">Средней работоспособности
              <input type="checkbox" name="ans3" value="Средней работоспособности" id="check2">
              <span class="checkmark"></span>
            </label>
          </p>
          <div class = "form-buttons">
            <input type="submit" class = "helper-button" value = "Отправить">
            <input type= "reset" class = "helper-button" value = "Сбросить">
          </div>
        </div>
      </form>
    </div>
  </main>
