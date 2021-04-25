function Clear() {
    var fio = document.forms[0].FIO;
    var date = document.forms[0].date;
    var email = document.forms[0].email;
    var phone = document.forms[0].phone;
    var textm = document.forms[0].textm;

    fio.classList.remove('is-invalid');
    date.classList.remove('is-invalid');
    email.classList.remove('is-invalid');
    phone.classList.remove('is-invalid');
    textm.classList.remove('is-invalid');
}

function Validate() {
    var fio = document.forms[0].FIO;
    var date = document.forms[0].date;
    var email = document.forms[0].email;
    var phone = document.forms[0].phone;
    var textm = document.forms[0].textm;

    if (FioCheck(fio) && Check(date) && Check(email) && PhoneCheck(phone) && Check(textm)) {
        return true;
    }
    else return false;
}

function FioCheck(fio) {
    var arrayFio = fio.value.split(' ');
    if ((arrayFio.length != 3) || (fio.value.match(/[0-9]+/))) {
        fio.classList.add('is-invalid');
        fio.focus();
        return false;
    }
    fio.classList.remove('is-invalid');
    return true;
}

function PhoneCheck(phone) {
    if (!phone.value.match(/^\+(7|3)\d{8,10}$/)) {
        phone.classList.add('is-invalid');
        phone.focus();
        return false;
    }
    phone.classList.remove('is-invalid');
    return true;
}

function Check(field) {
    if (field.value == '') {
        field.classList.add('is-invalid');
        field.focus();
        return false;
    }
    field.classList.remove('is-invalid');
    return true;
}
