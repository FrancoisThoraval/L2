var nb=1;

// Fonction qui récupère le fichier json
function getChap() {
  var url = "https://crossorigin.me/http://mmrissa.perso.univ-pau.fr/pub/book/chapitre"+nb+".json";
  var req = new XMLHttpRequest();
  req.open("GET", url);
  req.onerror = function() {
    console.log("Échec de chargement "+url);
  };
  req.onload = function() {
    if (req.status === 200) {
      var data = JSON.parse(req.responseText);
      affiche(data);
    } else {
      console.log("Erreur " + req.status);
    }
  };
  req.send();
}

// change le nb pour changer de chapitre
function nextChap(idButton){
  var button = document.getElementById(idButton);
  nb = button.href.slice(1);
  console.log(nb);
  getChap();
}

// Affiche les informations en créant et supprimant des elements texte et bouton
function affiche(data) {
  var livre = document.getElementById("livre");

  var divContent =document.createElement("div");
  divContent.id = "divContent";
  livre.appendChild(divContent);

  var text = document.createElement("p");
  text.id = "texte";
  text.innerHTML = data.txt;
  divContent.appendChild(text);
  for (var i = 0; i < data.links.length; i++) {

    var button = document.createElement("button");
    button.type = "button";
    button.id = "button"+i;
    button.href = data.links[i].link;
    button.innerHTML = data.links[i].txt;
    divContent.appendChild(button);

  }
  click();
}

// Gere le clic sur tout les boutons de la page
function click(){
  var goodButton = document.getElementsByTagName("button");
  for (var i = 0; i < goodButton.length; i++) {
    goodButton[i].addEventListener("click", function(){
      console.log(this.id);
      nextChap(this.id);
      this.parentNode.parentNode.removeChild(this.parentNode);
    });
  }
}

window.addEventListener("load",function(){
  getChap();
})
