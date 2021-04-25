function greenForm(){
    $('#login').css("border", "7px solid #79c603");
}
function redForm(){
    $('#login').css("border", "7px solid red");
}

let loginTrue = "Логин свободен";
let loginFalse = "Логин занят";

function CheckLogin(){
    let login = $('#login').val();

    let xhr = new XMLHttpRequest();

    xhr.open('POST', 'http://web/registration/checkLogin');

    xhr.setRequestHeader('Content-Type', 'application/json');

    xhr.onreadystatechange = function(){
        if(xhr.readyState === 4 && xhr.status === 200) {
            let serverResponse = xhr.responseText;
            if(serverResponse == 0){
                greenForm();
                $('#response').css("color", "#79c603");
                $('#response').css("margin-left", "15px");
                $('#response').text(loginTrue);
            }else{
                redForm();
                $('#response').css("color", "red");
                $('#response').css("margin-left", "15px");
                $('#response').text(loginFalse);
            }
        }
    };

    xhr.send(JSON.stringify({'login':login}));
}

