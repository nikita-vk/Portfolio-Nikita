// script.js

// Get the modal
var modal = document.getElementById("imageModal");
var modalImg1 = document.getElementById("modalImage1");
var modalImg2 = document.getElementById("modalImage2");
var captionText = document.getElementById("caption");

// Get the <span> element that closes the modal
var closeModal = document.getElementById("closeModal");

// Image links
var openMarket = document.getElementById("openMarket");
var openFMEA = document.getElementById("openFMEA");
var openCircuit = document.getElementById("openCircuit");
var openFlowCurve = document.getElementById("openFlowCurve");
var openCAD = document.getElementById("openCAD");
var openUI = document.getElementById("openUI");
var openArduino = document.getElementById("openArduino");
var openWCircuit = document.getElementById("openWCircuit");
var openWCAD = document.getElementById("openWCAD");



openMarket.onclick = function() {
    modal.style.display = "block";
    modalImg1.src = "Market_Analysis.png";
    modalImg1.alt = "Market Analysis";
    modalImg2.style.display = "none"; 
    captionText.innerHTML = "Market Analysis";
}

openFMEA.onclick = function() {
    modal.style.display = "block";
    modalImg1.src = "FMEA_Table_BreatheRight.png";
    modalImg1.alt = "FMEA Table";
    modalImg2.style.display = "none"; 
    captionText.innerHTML = "FMEA Table";
}

openCircuit.onclick = function() {
    modal.style.display = "block";
    modalImg1.src = "Circuit_analysis.png";
    modalImg1.alt = "Electric Circuit Analysis";
    modalImg2.style.display = "none"; 
    captionText.innerHTML = "Electric Circuit Analysis";
}

openFlowCurve.onclick = function() {
    modal.style.display = "block";
    modalImg1.src = "Quality_Assurance.png";
    modalImg1.alt = "Quality Assurance";
    modalImg2.style.display = "none"; 
    captionText.innerHTML = "Quality Assurance- This graph compares our peak flow sensor against a gold standard peak flow sensor to ensure that the device works properly";
}

openCAD.onclick = function() {
    modal.style.display = "block";
    modalImg1.src = "CAD_1.png";
    modalImg1.alt = "CAD (OnShape) - Image 1";
    modalImg2.src = "CAD_2.png";
    modalImg2.alt = "CAD (OnShape) - Image 2";
    modalImg2.style.display = "block"; // Show the second image
    captionText.innerHTML = "CAD (OnShape)";
}

open3D.onclick = function() {
    modal.style.display = "block";
    modalImg1.src = "iphone-images/3D_Print.jpeg";
    modalImg1.alt = "3D Print of BreatheRight";
    modalImg2.style.display = "none"; 
    captionText.innerHTML = "App Dashboard";
}

openUI.onclick = function() {
    modal.style.display = "block";
    modalImg1.src = "UI_Wireframe.png";
    modalImg1.alt = "UI Wireframe";
    modalImg2.style.display = "none"; 
    captionText.innerHTML = "App Dashboard";
}

openArduino.onclick = function() {
    modal.style.display = "block";
    modalImg1.src = "iphone-images/Wheelchair_Code.png";
    modalImg1.alt = "Wheelchair Code";
    modalImg2.style.display = "none"; 
    captionText.innerHTML = "Wheelchair Code";
}

openWCircuit.onclick = function() {
    modal.style.display = "block";
    modalImg1.src = "iphone-images/Wheelchair_Circuit.png";
    modalImg1.alt = "Wheelchair Circuit";
    modalImg2.style.display = "none"; 
    captionText.innerHTML = "Wheelchair Circuit";
}

openWCAD.onclick = function() {
    modal.style.display = "block";
    modalImg1.src = "iphone-images/Wheelchair_CAD.png";
    modalImg1.alt = "Wheelchair CAD";
    modalImg2.style.display = "none"; 
    captionText.innerHTML = "Wheelchair CAD";
}




closeModal.onclick = function() {
    modal.style.display = "none";
}

// When the user clicks anywhere outside of the modal, close it
window.onclick = function(event) {
    if (event.target == modal) {
        modal.style.display = "none";
    }
}
