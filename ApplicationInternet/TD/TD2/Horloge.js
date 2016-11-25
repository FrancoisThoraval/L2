var bPlus,stpBut,fiveBut,clockDiv,settings;
var nbAlarms=0;
var ringtoneGlobal;

bPlus = document.getElementById("bPlus");
stpBut = document.getElementById("stopButton");
fiveBut = document.getElementById("fiveButton");
clockDiv = document.getElementById("horlogeDOM");
settings=document.getElementById("Settings");
nbAlarms=0;
ringtoneGlobal;



function Clock() {
  var date,hours,minutes,seconds;

  setTimeout(function(){
    date=new Date();
    hours = date.getHours();
    minutes = date.getMinutes();
    seconds = date.getSeconds();
    // var milliseconds = date.getMilliseconds();

    // Affichage en double digits
    hours = ("0" + hours).slice(-2);
    minutes=("0" + minutes).slice(-2);
    seconds = ("0" + seconds).slice(-2);
    clockDiv.innerHTML= hours + ":" + minutes + ":" + seconds;
    Clock();
  },999);
}

function checkClock(id){
  var checkBox, userHours, userMinutes, getMessage, messageShow, ringtone, audioHandler, pText;
  var date,hours,minutes,seconds;

  checkBox = document.getElementById(id);
  pText = checkBox.nextSibling.nextSibling.nextSibling.nextSibling.nextSibling.nextSibling;
  console.log("test: "+ checkBox.id);
  console.log("test 2: "+ pText.id);
  userHours = checkBox.nextSibling.value;
  userMinutes = checkBox.nextSibling.nextSibling.value;
  getMessage =document.getElementById("message");
  messageShow=document.getElementById("msgAlert");
  console.log("messagemodal: " + messageShow.innerHTML);
  if (checkBox.checked) {
    if ((userHours>23) || (userHours < 0)) {
      pText.innerHTML = "Heures incorrectes";
      pText.style= "color: red";
    }else{
      if ((userMinutes>59) || (userMinutes < 0)) {
        pText.innerHTML = "Minutes incorrectes";
        pText.style= "color: red";
      }else {
        pText.innerHTML = "Horloge Active";
        pText.style = "color: green";
      }
    }
    audioHandler=document.getElementById("select").value;
    audioHandler = audioHandler.replace(/\s+/g, '');
    console.log("music choice: "+audioHandler);
    switch (audioHandler) {
      case "johnCena": ringtone = document.getElementById("johnCena");
        break;
      case "darudeSandstorm": ringtone=document.getElementById("darudeSandstorm");
        break;
      case "tetris": ringtone=document.getElementById("tetris");
        break;
      case "turnDownForWhat": ringtone=document.getElementById("turnDownForWhat");
        break;
    }
    ringtoneGlobal=ringtone;
    console.log("Alarm on");

    setTimeout(function(){
      date=new Date();
      hours = date.getHours();
      minutes = date.getMinutes();
      seconds = date.getSeconds();
      if ((hours==userHours) && (minutes==userMinutes) &&(seconds==0)) {
        console.log("C'est l'heure !!!");
        messageShow.innerHTML = getMessage.value;
        ringtone.play();
        $("#AlertBox").modal("show");
      }
    checkClock(id);
  },1000);
  }
  else {
    console.log("Alarm off");
    pText.innerHTML = "Horloge Inactive";
    pText.style = "color: black";
  }
}

function addClock(){
  var divContent, form, checkBox, hours,minutes,text,optionArray,select,option,deleteBtn;
  console.log("A que coucou");
  // Creation div qui contient les options
  divContent = document.createElement("div");
  divContent.className="form-group";
  settings.appendChild(divContent);

  // Creation formulaire
  form=document.createElement("form");
  form.className="form-inline";
  divContent.appendChild(form);

  // Creation checkbox
  checkBox = document.createElement("input");
  checkBox.type = "checkBox";
  checkBox.id = "Alarm n°"+nbAlarms;
  checkBox.class="form-control";
  divContent.appendChild(checkBox);

  // Creation saisie heures
  hours=document.createElement("input");
  hours.type ="number";
  hours.min= "0";
  hours.max="23";
  hours.class="form-control";
  divContent.appendChild(hours);

  // Creation saisie minutes
  minutes=document.createElement("input");
  minutes.type ="number";
  minutes.min="0";
  minutes.max="59";
  minutes.class="form-control";
  divContent.appendChild(minutes);

  // Creation saisie label
  text=document.createElement("input");
  text.type="text";
  text.id="message";
  text.class="form-control";
  divContent.appendChild(text);

  // Choix des musiques
  optionArray = ["john Cena","darude Sandstorm","tetris","turn Down For What"];

  // Creation select des musiques
  select=document.createElement("select");
  select.id="select";
  divContent.appendChild(select);
  // Creation des options
  for (var i = 0; i < optionArray.length; i++) {
    option = document.createElement("option");
    option.value=optionArray[i];
    option.text=optionArray[i];
    select.appendChild(option);
  }

  // Creation du bouton supprimer
  deleteBtn = document.createElement("button");
  deleteBtn.type = "button";
  deleteBtn.id= "Alarm n°"+nbAlarms;
  deleteBtn.className = "btn btn-danger";
  deleteBtn.innerHTML="-";
  divContent.appendChild(deleteBtn);

  // Creation p pour savoir si l'alarme est active ou non
  pText=document.createElement("p");
  pText.innerHTML = "Horloge Inactive";
  divContent.appendChild(pText);

  // Quand on coche/décoche
  checkBox.addEventListener("change",function(){

    checkClock(this.id);

  });

  // Quand on clique sur le bouton supprimer
  deleteBtn.addEventListener("click",function(){
    this.parentNode.parentNode.removeChild(this.parentNode);
    nbAlarms--;
  });
}

// Quand la page a fini de charger
window.addEventListener("load",function(){
  // Affichage de l'heure en temps réel
  Clock();
  // Quand on clique sur ajouter une alarme
  bPlus.addEventListener("click",function(){
    nbAlarms++;
    // Creation d'une alarme
    addClock();
  });
});

// Quand on clique sur snooze
fiveBut.addEventListener("click",function(){
  ringtoneGlobal.pause();
  setTimeout(function () {
    $("#AlertBox").modal("show");
    ringtone.play();
  },1000*60*5);
});

// Quand on clique sur stop
stpBut.addEventListener("click",function(){
  ringtoneGlobal.pause();
});
