/*---------------------calendar------------------------*/
function Calendar(){
  var mainDiv = document.getElementById("calendar");
  var days = ["Вс", "Пн", "Вт","Ср","Чт","Пт","Сб"];



  function FillForm(num){
  dateField.value = num + ' ' + month.value + ' ' + years.value;
}

  var dateField = document.getElementById('contactDate');
  var month=document.getElementById('month');
  var years= document.getElementById('years');
  var monthForDraw = 0;

function addNullDays(){
var years= document.getElementById('years');
var month=document.getElementById('month');

  if(month.value == "January"){
    monthForDraw = 0;
    console.log(':(');
  }

  if(month.value=="February")
    monthForDraw = 1;
  if(month.value=="March")
    monthForDraw = 2;
 if(month.value=="April")
    monthForDraw = 3;
  if(month.value=="May")
    monthForDraw = 4;
   if(month.value=="June")
    monthForDraw = 5;
  if(month.value=="July")
    monthForDraw = 6;
  if(month.value=="August")
    monthForDraw = 7;
  if(month.value=="September")
    monthForDraw = 8;
  if(month.value=="October")
    monthForDraw = 9;
  if(month.value=="November")
    monthForDraw = 10;
  if(month.value=="December")
    monthForDraw = 11;

dateForDraw = new Date(years.value,monthForDraw,1);
numOfEmptyDivs = dateForDraw.getDay();

if(numOfEmptyDivs !== 0){
  for(i = 0 ; i<numOfEmptyDivs; i++){
    var subDiv = document.createElement("div");
    subDiv.className = "calendarDay";
    mainDiv.appendChild(subDiv);
    }
  }
}

function daysInMonth(iMonth, iYear) {
   return 32 - new Date(iYear, iMonth, 32).getDate();
}

function addDaysNames(){
  for(i=0;i<days.length;i++){
    var subDiv = document.createElement("div");
     subDiv.innerHTML = days[i];
     subDiv.className = "calendarDay";
     mainDiv.appendChild(subDiv);
  }
}

function DrawCalenarBody(){
for(i=0;i<daysInMonth(monthForDraw,years.value);i++){
  var subDiv = document.createElement("div");
    subDiv.className = "calendarDay";
    subDiv.innerHTML = i+1;
    subDiv.addEventListener("click", function(){dateField.value=this.firstChild.nodeValue+' '+month.value+' '+years.value});
    mainDiv.appendChild(subDiv);
  }
}

function DeleteSubDivs(){
  while(mainDiv.firstElementChild){
    mainDiv.firstElementChild.remove();
  }
}

var selectMonth = document.getElementById("month");
var selectYears = document.getElementById("years");
var monthOption = selectMonth.getElementsByTagName("option");
selectMonth.onchange = function a(){ DeleteSubDivs();addDaysNames(); addNullDays();  DrawCalenarBody();};
selectYears.onchange = function b(){DrawNewCalendar()};

function DrawNewCalendar(){
  DeleteSubDivs();
  addDaysNames();
  addNullDays();
  DrawCalenarBody();
}

FillForm(1);
DrawNewCalendar();
}
