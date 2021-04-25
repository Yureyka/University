var anchors = [
    { id: "#books", name: "Книги" }, { id: "#music", name: "Музыка" },
    { id: "#films", name: "Фильмы" }, { id: "#games", name: "Игры" }, { id: "#hobby", name: "Хобби" }
]

function Anchors (){
  for (var i = 0; i < arguments.length; i++) {
      document.writeln(`<li class='nav-item pr-5'><a class='nav-link nav-font2' href='${arguments[i].id}'>${arguments[i].name}</a></li>`);
  }
}

Anchors (anchors[0], anchors[1], anchors[2], anchors[3], anchors[4]);
