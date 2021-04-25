//----------Навигационные ссылки-----------------
function mouseLis() {
    var nav = document.getElementById('one');
    var a = nav.getElementsByTagName('a');
    for (let i = 0; i < a.length; i++) {
        a[i].onmouseenter = function () {
            this.style.background = 'rgb(27, 100, 144, 0.4)';
        }
        a[i].onmouseleave = function () {
            this.style.background = 'transparent';
        }
    }
}

/*------------------------submenu------------------------*/
function submenu() {
    var el = document.getElementsByClassName('menu-item');
    for (var i = 0; i < el.length; i++) {
        el[i].addEventListener("mouseenter", showSub, false);
        el[i].addEventListener("mouseleave", hideSub, false);
    }

    function showSub(e) {
        if (this.children.length > 1) {
            this.children[1].style.height = "auto";
            this.children[1].style.overflow = "visible";
            this.children[1].style.opacity = "1";
        } else {
            return false;
        }
    }

    function hideSub(e) {
        if (this.children.length > 1) {
            this.children[1].style.height = "0px";
            this.children[1].style.overflow = "hidden";
            this.children[1].style.opacity = "0";
        } else {
            return false;
        }
    }
}

/*------------------------time------------------------*/
function date_time() {
    let date = new Date();
    let hours = date.getHours();
    let minutes = date.getMinutes();
    let seconds = date.getSeconds();
    let day = date.getDate();
    let month = date.getMonth() + 1;
    let year = date.getFullYear();
    if (day < 10) day = "0" + day;
    if (month < 10) month = "0" + month;
    if (hours < 10) hours = "0" + hours;
    if (minutes < 10) minutes = "0" + minutes;
    if (seconds < 10) seconds = "0" + seconds;
    document.getElementById("digital_watch").innerHTML = hours + ":" + minutes + ":" + seconds + "  " + day + "." + month + "." + year;
    setTimeout("date_time()", 1000);
}

/*----------------------BigPhoto---------------------------*/
function expand_photo() {

    NodeList.prototype.forEach = Array.prototype.forEach;

    let imgDiv = document.querySelector(".expanded .bigPhoto")

    document.querySelectorAll('.photo img')

        .forEach((img, i) => {
            img.addEventListener('click', e => {
                let bigImg = document.createElement('img');
                bigImg.src = `img/${i + 1}.jpg`;
                bigImg.title = i+1;
                imgDiv.innerHTML = " ";

                bigImg.onload = function () {
                    if (bigImg.width <= bigImg.height) {
                        // bigImg.style.marginLeft = bigImg.width / 2 + "px";
                    }
                }
                imgDiv.appendChild(bigImg);
                document.querySelector(".expanded").classList.add("open");
                document.querySelector(".bg-blur").classList.add("bg-blur1");

            })
        })
}

function close_modal_form() {

    var cross = document.getElementsByClassName('cross')[0];
    var div = document.querySelector(".expanded ");
    var bgblur = document.querySelector(".bg-blur");
    cross.addEventListener('click', function () {
        div.classList.remove("open");
        bgblur.classList.remove("bg-blur1");
    });
}
function switchPhoto() {
    $(document).ready(function () {
        $('#next').click(function () {
            var bigImg = $('.bigPhoto').firstChild;
            var bigImg = $('.bigPhoto').find('img');
            var index = bigImg.attr('title');
            var newIndex = +index + +1;
            if (newIndex > 15) {
                newIndex = 1;
            }
            bigImg.remove();
            var div = $('.bigPhoto');
            div.prepend($('<img>', {id: 'theImg', src: 'img/' + newIndex + '.jpg', title: newIndex}))
        });
    })

    $('#prev').click(function () {
        var bigImg = $('.bigPhoto').firstChild;
        var bigImg = $('.bigPhoto').find('img');
        var index = bigImg.attr('title');
        var newIndex = +index - +1;
        if (newIndex < 1) {
            newIndex = 15;
        }
        bigImg.remove();
        var div = $('.bigPhoto');
        div.prepend($('<img>', {id: 'theImg', src: 'img/' + newIndex + '.jpg', title: newIndex}))
    });
}
/*----------------------Cookie---------------------------------*/
function SaveCookies(cname) {
    console.log('1');

    var visits = getCookie(cname);
// if the cookie wasn't found, this is your first visit
    console.log(visits);
    if (!visits) {
        visits = 1; // the value for the new cookie
    } else {
        // increment the counter
        visits = parseInt(visits) + 1;
    }


    var foo = localStorage.getItem(cname);
    if (!foo) {
        foo = 1;
    } else {
        foo = parseInt(foo) + 1;
    }
    console.log(foo);
// set the new cookie
    localStorage.setItem(cname, foo);
    setCookie(cname, visits);
}


function viewSession() {
    var mainPage = parseInt(localStorage.getItem("main"));
    document.getElementById("mainS").innerHTML = returnResult(mainPage);

    var aboutPage = parseInt(localStorage.getItem("about"));
    document.getElementById("aboutS").innerHTML = returnResult(aboutPage);

    var interestsPage = parseInt(localStorage.getItem("interests"));
    document.getElementById("interestsS").innerHTML = returnResult(interestsPage);

    var studyPage = parseInt(localStorage.getItem("study"));
    document.getElementById("studyS").innerHTML = returnResult(studyPage);

    var photoPage = parseInt(localStorage.getItem("photo"));
    document.getElementById("photoS").innerHTML = returnResult(photoPage);

    var contactPage = parseInt(localStorage.getItem("contact"));
    document.getElementById("contactS").innerHTML = returnResult(contactPage);

    var testPage = parseInt(localStorage.getItem("test"));
    document.getElementById("testS").innerHTML = returnResult(testPage);

    var historyPage = parseInt(localStorage.getItem("history"));
    document.getElementById("historyS").innerHTML = returnResult(historyPage);


    var keyMain = "main";
    var valueMain = document.cookie.match(new RegExp(
        "(?:^|; )" + keyMain.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"));

    document.getElementById("mainC").innerHTML = valueMain ? decodeURIComponent(valueMain[1]) : "-";

    var keyAbout = "about";
    var valueAbout = document.cookie.match(new RegExp(
        "(?:^|; )" + keyAbout.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"));

    document.getElementById("aboutC").innerHTML = valueAbout ? decodeURIComponent(valueAbout[1]) : "-";

    var keyInterests = "interests";
    var valueInterests = document.cookie.match(new RegExp(
        "(?:^|; )" + keyInterests.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"));

    document.getElementById("interestsC").innerHTML = valueInterests ? decodeURIComponent(valueInterests[1]) : "-";

    var keyStudy = "study";
    var valueStudy = document.cookie.match(new RegExp(
        "(?:^|; )" + keyStudy.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"));

    document.getElementById("studyC").innerHTML = valueStudy ? decodeURIComponent(valueStudy[1]) : "-";

    var keyPhoto = "photo";
    var valuePhoto = document.cookie.match(new RegExp(
        "(?:^|; )" + keyPhoto.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"));

    document.getElementById("photoC").innerHTML = valuePhoto ? decodeURIComponent(valuePhoto[1]) : "-";

    var keyContact = "contact";
    var valueContact = document.cookie.match(new RegExp(
        "(?:^|; )" + keyContact.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"));

    document.getElementById("contactC").innerHTML = valueContact ? decodeURIComponent(valueContact[1]) : "-";

    var keyTest = "test";
    var valueTest = document.cookie.match(new RegExp(
        "(?:^|; )" + keyTest.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"));

    document.getElementById("testC").innerHTML = valueTest ? decodeURIComponent(valueTest[1]) : "-";

    var keyHistory = "history";
    var valueHistory = document.cookie.match(new RegExp(
        "(?:^|; )" + keyHistory.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"));

    document.getElementById("historyC").innerHTML = valueHistory ? decodeURIComponent(valueHistory[1]) : "-";

}


function returnResult(result) {
    if (isNaN(result)) {
        return " - "
    } else return result;
}


function getCookie(name) {
    var dc = document.cookie;
    var prefix = name + "=";
    var begin = dc.indexOf("; " + prefix);
    if (begin == -1) {
        begin = dc.indexOf(prefix);
        if (begin != 0) return null;
    } else
        begin += 2;
    var end = document.cookie.indexOf(";", begin);
    if (end == -1)
        end = dc.length;
    return unescape(dc.substring(begin + prefix.length, end));
}

function setCookie(name, value) {
    var curCookie = name + "=" + escape(value);
    document.cookie = curCookie;
}


function modalWindow() {
    $(function () {
        $("#post").click(function () {
            $(".expanded").addClass("open");
            $(".bg-blur").addClass("bg-blur2");

        })

        $(function () {
            $("#submitNo").click(function () {
                $(".expanded").removeClass("open");
                $(".bg-blur").removeClass("bg-blur2");
            })
        })
    })
}



function popOvers() {
    $(function () {
        $("#phone").webuiPopover({
            placement: 'auto',
            width: '20px',// Ширина, числом
            height: '20px',// Высота, числом
            title: '1',
            content: 'Введите имя в формате: Фамилия Имя Отчество',
            trigger: 'hover',
            delay: {
                show: 1,
                hide: 40000
            }
        });

    });

}
