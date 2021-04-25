function forGalley(){
  var titles = [
    "Природа", "Природа", "Природа", "Природа", "Природа",
    "Горы", "Красная поляна", "Казань", "Санкт-Петербург",
    "Гитара",  "Пляжка", "Соревнования", "1-е место",
    "Волейбол", "Команда"];

    var fotos = new Array();
    var path = "D:/OpenServer/OSPanel/domains/web/public/asset/img/";
    for(i = 0; i < 15; i++){
      fotos[i] = path + (i+1) + ".jpg";
    }
    for(i = 0; i < 15; i++){
      if (i%5 === 0){
        document.write('<tr class="photo">');
      }
      document.write('<td class="photo">');
      document.write('<figure>');
      document.write('<img src="' + fotos[i] + '" title="' + titles[i] + '">');
      document.write('<figcaption>' + titles[i] + '</figcaption>');
      document.write('</figure>');
      document.write('</td>');
    }
  }
