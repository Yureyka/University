var path = "D:/Универ/3 курс/Web/Лаб2/Юрей 2.0/gallery/"

var photos = [
  [
    { pic: path + "1.jpg", title: "В бутылке лимонад" },
    { pic: path + "2.jpg", title: "Ага" },
    { pic: path + "3.jpg", title: "Книга" },
  ],
  [
    { pic: path + "5.jpg", title: "Рисунок" },
    { pic: path + "6.jpg", title: "Глаз" },
    { pic: path + "7.jpg", title: "Свеча" },
    { pic: path + "13.jpg", title: "Ветви" },
  ],
  [
    { pic: path + "9.jpg", title: "Дуся с большим языком" },
    { pic: path + "10.jpg", title: "Дуся с маленьким языком" },
    { pic: path + "12.jpg", title: "Севастопольский закат" },
  ],
  [
    { pic: path + "4.jpg", title: "Укулеле" },
    { pic: path + "8.jpg", title: "Смородина и улитка" },
    { pic: path + "11.jpg", title: "Отдых после побега с мексиканской границы" },
  ]
];

photos.forEach(element => {
    document.writeln("<div class='col-lg-3'>");
    element.forEach(elementLast => {
        document.writeln(`<div class='pic'><div class='img-wrapper rounded-lg grow'><a href='${elementLast.pic}' data-lightbox='my-gallery'><img class='img-fluid rounded-sm' src='${elementLast.pic}' title='${elementLast.title}'></a><h5 class='pic-desc'>${elementLast.title}</h5></div></div>`);
    });
    document.writeln("</div>");
})
