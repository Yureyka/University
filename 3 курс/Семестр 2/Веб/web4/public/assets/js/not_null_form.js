function swap_to_red(text) {
  document.getElementById('up-' + text).style.display = "block";
  document.getElementsByName(text)[0].classList.add("false");
  document.getElementsByName(text)[0].classList.remove("true");
}

function swap_to_green(text) {
  document.getElementsByName(text)[0].classList.add("true");
  document.getElementsByName(text)[0].classList.remove("false");
  document.getElementById('up-' + text).style.display = 'none';
}

function checkName(){
  var fio = document.getElementsByName('name');
  if (fio[0].value == "" || fio[0].value.split(" ").length !== 3){
    // alert("Введите Ваше полное ФИО");
    swap_to_red('name');
    fio[0].style.border = "5px solid red";
    document.getElementsByName('name')[0].focus();
    //   swap_to_red('name');
    return false;
  }else {
    fio[0].style.border = "5px solid green";
    swap_to_green('name');
    return true;
  }
}

function checkMail(){
  var mail = document.getElementsByName('mail');
  if (mail[0].value== "" || !(/^([A-Za-z0-9_\-\.])+\@([A-Za-z0-9_\-\.])+\.([A-Za-z]{2,4})$/.test(mail[0].value))){
    // alert("Введите корректный адрес Вашей почты");
    swap_to_red('mail');
    mail[0].style.border = "5px solid red";
    document.getElementsByName('mail')[0].focus();
    return false;
  }else{
    mail[0].style.border = "5px solid green";
    swap_to_green('mail');
    return true;
  }

}
function checkPhone(){
  var phone = document.getElementsByName("phone");
  if (phone[0].value == "" || !(/\+[73]\d{9,11}$/.test(phone[0].value)))
  {
    // alert("Введите правильный телефонный номер (+7[3]...)");
    swap_to_red('phone');
    phone[0].style.border = "5px solid red";
    phone[0].focus();
    return false;
  }else{
    phone[0].style.border = "5px solid green";
    swap_to_green('phone');
    return true;
  }
}

function validateContactsForm() {
 //  var fio = document.getElementsByName('name');
 // if (fio[0].value == "" || fio[0].value.split(" ").length !== 3){
 //     // alert("Введите Ваше полное ФИО");
 //     swap_to_red('name');
 //     fio[0].style.border = "5px solid red";
 //     document.getElementsByName('name')[0].focus();
 //   //   swap_to_red('name');
 //      return false;
 //    }else {
 //      fio[0].style.border = "5px solid green";
 //      swap_to_green('name');
 //      return true;
 //  }


// var mail = document.getElementsByName('mail');
//     if (mail[0].value== "" || !(/^([A-Za-z0-9_\-\.])+\@([A-Za-z0-9_\-\.])+\.([A-Za-z]{2,4})$/.test(mail[0].value))){
//         // alert("Введите корректный адрес Вашей почты");
//         swap_to_red('mail');
//         mail[0].style.border = "5px solid red";
//         document.getElementsByName('mail')[0].focus();
//         return false;
//       }else{
//         mail[0].style.border = "5px solid green";
//         swap_to_green('mail');
//         return true;
//       }

    // var phone = document.getElementsByName("phone");
    // if (phone[0].value == "" || !(/\+[73]\d{9,11}$/.test(phone[0].value)))
    //     {
    //         // alert("Введите правильный телефонный номер (+7[3]...)");
    //         swap_to_red('phone');
    //         phone[0].style.border = "5px solid red";
    //         phone[0].focus();
    //         return false;
    //     }else{
    //             phone[0].style.border = "5px solid green";
    //             swap_to_green('mail');
    //             return true;
    //           }


        var fail = false;
        var sex = form.qwe.value;
        if(sex == ""){
          fail = "Укажите пол";
        }
        if(fail){
          alert(fail);
          return false;
        } else
           return true;
}

function activate() {
  if (checkName() == true && checkPhone() == true && checkMail() == true)
    var button = document.getElementById('post').disabled = false;
  else
    var button = document.getElementById('post').disabled = true;
}

function validateTestForm() {
  var fio = document.getElementsByName('name');
 if (fio[0].value == "" || fio[0].value.split(" ").length !== 3){
     alert("Введите Ваше полное ФИО");
     document.getElementsByName('name')[0].focus();
     return false;
 }
 var question = document.getElementsByName('check');
 var answerCounter = 0;
 for (var i=0; i<question.length;i++)
     if (question[i].checked) answerCounter++;
 if (answerCounter < 1){
     alert("Выберите минимум 1 вариант ответа в 3 вопросе");
     return false;
 }
}
