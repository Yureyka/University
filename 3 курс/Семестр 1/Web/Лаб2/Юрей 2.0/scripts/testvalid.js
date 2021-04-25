function Clear() {
    var first_answer = document.forms[0].first;
    var second_answer = document.forms[0].second;
    var fio = document.forms[0].FIO;
    var group = document.forms[0].group;

    fio.classList.remove('is-invalid');
    group.classList.remove('is-invalid');
    first_answer.classList.remove('is-invalid');
    second_answer.classList.remove('is-invalid');
}

function Validate() {
    var first_answer = document.forms[0].first;
    var second_answer = document.forms[0].second;
    var fio = document.forms[0].FIO;
    var group = document.forms[0].group;

    if (CheckFirst(first_answer) && SelectCheck(second_answer) && FioCheck(fio) && Check(group)) {
        return true;
    }
    else return false;
}

function CheckFirst(first_answer) {
    var arrayFirst = first_answer.value.split(' ');
    if ((arrayFirst.length > 30) || (first_answer.value == '') || (first_answer.value.match(/[0-9]+/))) {
      first_answer.classList.add('is-invalid');
      first_answer.focus();
      return false;
    }
    first_answer.classList.remove('is-invalid');
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

function SelectCheck(second_answer) {
    if (second.selectedIndex == 0) {
        second.classList.add('is-invalid');
        second.focus();
        return false;
    }
    second.classList.remove('is-invalid');
    return true;
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
