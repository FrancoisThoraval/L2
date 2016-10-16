var bPlus = document.getElementById("bPlus");
var stpBut = document.getElementById("stopButton");
var fiveBut = document.getElementById("fiveButton");
var clockDiv = document.getElementById("horlogeDOM");
var settings=document.getElementById("Settings");
var nbAlarms=0;
var ringtoneGlobal;



function Clock() {
  setTimeout(function(){
    var date=new Date();
    var hours = date.getHours();
    var minutes = date.getMinutes();
    var seconds = date.getSeconds();
    // var milliseconds = date.getMilliseconds();
    hours = ("0" + hours).slice(-2);
    minutes=("0" + minutes).slice(-2);
    seconds = ("0" + seconds).slice(-2);
    clockDiv.innerHTML= hours + ":" + minutes + ":" + seconds;
    Clock();
  },999);
}

function checkClock(id){
  var checkBox = document.getElementById(id);
  var userHours = checkBox.nextSibling.value;
  var userMinutes = checkBox.nextSibling.nextSibling.value;
  var getMessage =document.getElementById("message");
  var messageShow=document.getElementById("msgAlert");
  var ringtone;
  console.log("messagemodal: " + messageShow.innerHTML);
  if (checkBox.checked) {
    var audioHandler=document.getElementById("select").value;
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
      var date=new Date();
      var hours = date.getHours();
      var minutes = date.getMinutes();
      var seconds = date.getSeconds();
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
  }
}

function addClock(){
  console.log("A que coucou");
  // Creation div qui contient les options
  var divContent = document.createElement("div");
  divContent.className="form-group";
  settings.appendChild(divContent);

  // Creation formulaire
  var form=document.createElement("form");
  form.className="form-inline";
  divContent.appendChild(form);

  // Creation checkbox
  var checkBox = document.createElement("input");
  checkBox.type = "checkBox";
  checkBox.id = "Alarm n°"+nbAlarms;
  checkBox.class="form-control";
  divContent.appendChild(checkBox);

  // Creation saisie heures
  var hours=document.createElement("input");
  hours.type ="number";
  hours.min= "0";
  hours.max="23";
  hours.class="form-control";
  divContent.appendChild(hours);

  // Creation saisie minutes
  var minutes=document.createElement("input");
  minutes.type ="number";
  minutes.min="0";
  minutes.max="59";
  minutes.class="form-control";
  divContent.appendChild(minutes);

  // Creation saisie label
  var text=document.createElement("input");
  text.type="text";
  text.id="message";
  text.class="form-control";
  divContent.appendChild(text);

  // Choix des musiques
  var optionArray = ["john Cena","darude Sandstorm","tetris","turn Down For What"];

  // Creation select des musiques
  var select=document.createElement("select");
  select.id="select";
  divContent.appendChild(select);
  // Creation des options
  for (var i = 0; i < optionArray.length; i++) {
    var option = document.createElement("option");
    option.value=optionArray[i];
    option.text=optionArray[i];
    select.appendChild(option);
  }

  // Creation du bouton supprimer
  var deleteBtn = document.createElement("button");
  deleteBtn.type = "button";
  deleteBtn.id= "Alarm n°"+nbAlarms;
  deleteBtn.className = "btn btn-danger";
  deleteBtn.innerHTML="-";
  divContent.appendChild(deleteBtn);

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
