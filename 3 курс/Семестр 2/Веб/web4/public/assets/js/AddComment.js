let postId = "";

$(function () {
    $(".addComment").on('click', function () {
        OpenModalWindow();
        let id = $(this).val();
        postId = id;
    })
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

async function AddComment() {
    let comment = $('#comment').val();
    let author = $('#userName').text();
    let xmlString = "<comment>" +
        " <idBlog>" + escape(postId) + "</idBlog>" +
        " <commentText>" + escape(comment) + "</commentText>" +
        "</comment>";

    let res = await fetch("/blog/addComment", {
        method: 'post',
        headers: {
            "Content-type": "text/xml"
        },
        body: xmlString
    })
        .then(response => response.text())
        .then(body => {
            console.log(body);
            $('#comment'+ postId).append('<p><b>Автор:   </b><i>' + author + '</i><br>' + comment + '</p>');
            CloseModalWindow();
        })
}
