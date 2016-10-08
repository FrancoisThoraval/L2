// regexr.com
// /.../ = délimite l'expression régulière
// [...] = cherche n'importe quel caractère entre les crochets
// [^...] = cherche n'importe quel caractère différents de ceux
//        entre les crochets
// /.../i = ne prends pas en compte la casse

// /[^a-z_\-]/i
//
// =============================================================================================================================
//

var RegexMaj = /(.*?[A-Z])/;
var RegexMin = /(.*?[a-z])/;
var RegexNum = /(.*?[0-9])/;
var RegexLen = /.{8,}/;
var RegexSpe = /(.*?\W)/;
// var Regex = (/^(?=.*?[A-Z])(?=.*?[a-z])(?=.*?[0-9])(?=.*?\W).{8,}$/) ; Ce regex correspond à une sécurité 100%

var AgeDOM = document.getElementById("age");
var AgeP = document.getElementById("AgeP");
var IdDOM = document.getElementById("Id");
var IdP = document.getElementById("IdP");
var MdpDOM = document.getElementById("Mdp");
var Str = document.getElementById("str");
var MdpConfirmDOM = document.getElementById("MdpConfirm");
var noMatch = document.getElementById("noMatch");
var CocheCaseDOM = document.getElementById("CocheCase");
var SubmitDOM = document.getElementById("Submit");
var CheckGood = false;
var MdpGood = false;
var IdGood = false;
var AgeGood = false;
console.log(CheckGood);

function VerifieAge() {

  if (AgeDOM.value >= 18) {
    AgeGood = true;
    AgeDOM.style.border = "2px solid green";
    AgeP.style.display = "none";
  }
  else {
    AgeDOM.style.border = "2px solid red";
    AgeP.style.display = "inline";
    AgeGood = false;
  }
  if (CheckGood && MdpGood && AgeGood && IdGood) {
    SubmitDOM.disabled = false;
  }
}

function VerifieId() {
  var IdValue = IdDOM.value;
  var IdLength = Id.value.length;
  if ((IdLength > 12) || (IdLength===0) || (/[^a-z_\-]/i.test(IdValue) === true)){
    IdDOM.style.border = "2px solid red";
    IdP.style.display = "inline";
    IdGood = false;
  }
  else {
    IdDOM.style.border = "2px solid green";
    IdP.style.display = "none";
    IdGood = true;
  }
  if (CheckGood && MdpGood && AgeGood && IdGood) {
    SubmitDOM.disabled = false;
  }

}

function VerifieMdpConf(){
  var value = MdpDOM.value;
  var valueConfirm = MdpConfirmDOM.value;
  if (value === valueConfirm) {
    MdpGood = true;
    noMatch.style.display = "none";
  }
  else {
    MdpGood = false;
    noMatch.style.display = "inline";
    noMatch.style.color = "red";
    noMatch.textContent = "Veuillez répeter le mot de passe";
  }
  if (CheckGood && MdpGood && AgeGood && IdGood) {
    SubmitDOM.disabled = false;
  }
}


function VerifieMdp(strength){
  var strength = 0;
  var value = MdpDOM.value;
  var length = MdpDOM.length;

  if (RegexMaj.test(value)) {
    strength+=20;
  }
  if (RegexMin.test(value)) {
    strength+=20;
  }
  if (RegexNum.test(value)) {
    strength+=20;
  }
  if (RegexLen.test(value)) {
    strength+=20;
  }
  if (RegexSpe.test(value)) {
    strength+=20;
  }
  if (strength === 0){
    str.style.color = "red";
    str.textContent = "Force : 0 %";
  }
  if (strength === 20) {
    str.style.color = "orangered";
    str.textContent = "Force : 20 %";
  }
  if (strength === 40) {
    str.style.color = "orange";
    str.textContent = "Force : 40 %";
  }
  if (strength === 60) {
      str.style.color = "slateblue";
      str.textContent = "Force : 60 %";
  }
  if (strength === 80) {
      str.style.color = "yellowgreen";
      str.textContent = "Force : 80 %";
  }
  if(strength === 100){
      str.style.color = "springgreen";
      str.textContent = "Force : 100 %";
  }
}

function VerifieCheck(){
  if (CocheCaseDOM.checked) {
    CheckGood = true;
  }
  else {
    CheckGood = false;
  }
  if (CheckGood && MdpGood && AgeGood && IdGood) {
    SubmitDOM.disabled = false;
  }
}

window.addEventListener("load", function(){
  var strength =0;
  SubmitDOM.disabled = true;

  // Setup des messages lors de l'entree des valeurs dans le formulaire
  IdP.style.display = "none";
  IdP.style.color = "red";
  AgeP.style.display = "none";
  AgeP.style.color = "red";
  str.style.display = "none";
  str.style.color = "red";
  AgeDOM.addEventListener("input",function () {
    VerifieAge();
  });
  IdDOM.addEventListener("input",function () {
    VerifieId();
  });
  MdpDOM.addEventListener("input",function () {
    str.style.display = "inline";
    VerifieMdp(strength);
  });
  MdpConfirmDOM.addEventListener("input",function () {
    VerifieMdpConf();
  });
  CocheCaseDOM.addEventListener("change",function () {
    VerifieCheck();
  });
});
