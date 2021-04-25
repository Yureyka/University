function display_list(hrefs, ...param)
{
  var parent = document.getElementById("anchors");
  var hobby = parent.querySelector("ul");
  var lists = hobby.querySelectorAll("li");
  lists.forEach(function(item)
  {
    hobby.removeChild(item);
  });
  for(index in param){
    var li = document.createElement("li");
    var a = document.createElement("a");
    if (hrefs[index] != undefined) a.setAttribute("href", hrefs[index]);
    a.textContent = param[index];
    li.appendChild(a);
    hobby.appendChild(li);
  }
}
document.addEventListener("DOMContentLoaded", function()
{
  var hrefs =
  [
    "#Sport",
    "#Music",
    "#Books"
  ];
  display_list(hrefs, "Спорт", "Музыка", "Книги");
});
