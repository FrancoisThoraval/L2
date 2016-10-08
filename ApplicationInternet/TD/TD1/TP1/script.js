var today = new Date();
var h1;
function Alert(){
    alert("Today is:" + today.toString());
}

//Modifie le titre en accedant à h1title dans le DOM
window.addEventListener("load", function() {
    Alert();
    h1 = document.getElementById("h1Title");
    h1.innerHTML= "Ye sé po sé ki fô fêrre";
});
