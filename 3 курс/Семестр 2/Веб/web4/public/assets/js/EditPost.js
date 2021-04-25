let postId = "";
let myForm = $('#editForm');
let iframe;

$(function () {
    $(".editPostButton").on('click', function () {
        OpenModalWindow();
        postId = $(this).val();
        console.log(postId);
        let themeText = $('#themeText' + postId).text();
        $('#editTheme').val(themeText);
        let postText = $('#postText' + postId).text();
        $('#editPostText').val(postText);
        $('#editId').val(postId);
    })
});

$(function () {
    $('#saveUpdatePost').click(function () {
        let newTheme = $('#editTheme').val();
        let newPostText = $('#editPostText').val();

        iframe = document.createElement('iframe');
        iframe.name = "myFrame";

        iframe.onload = function () {
            if(this.contentWindow.document.body.innerHTML){
                $('#themeText' + postId).text(newTheme);
                $('#postText' + postId).text(newPostText);
                CloseModalWindow();
                $(iframe).remove();
            }
        };

        document.body.appendChild(iframe);
        myForm.submit();
    });
});


function CloseModalWindow() {
    $(".expanded").css("display", "none");
    $(".test").css("filter", "none");
    $(".test").css("pointer-events", "auto");
    $("body").css("background", "");
}

function OpenModalWindow() {
    $(".expanded").css("display", "block");
    $(".test").css("filter", "blur(8px)");
    $(".test").css("pointer-events", "none");
    $("body").css("background", "#000");
}