var containerTwo = document.getElementsByClassName("containerTwo")[0];
var containerThree = document.getElementsByClassName("containerThree")[0];
var checkIcon = document.getElementsById("checkIcon");
var xIcon = document.getElementById("xIcon");

checkIcon.addEventListener("click", function(){createNote();})

xIcon.addEventListener("click", function(){typeNote();})

function createNote(){
    var noteText = document.getElementById("noteText").value;
    var node0 = document.createElement("div");
    var node1 = document.createElement("h1");

    node1.innerHTML = noteText;
    node1.setAttribute("style", "width: 250px; height: 250px; font-size: 25px; padding: 25px; margin-top: 10px; overflow: hidden; box-shawdow: 0px 10px 24px 0px rgba(0,0,0,0.75)");
    node1.style.margin = setMargin();
    node1.style.transform = setRotation();
    node1.style.background = setColor();
    
    node0.appendChild(node1);
    containerTwo.insertAdjacentElement("beforeend", node0);

    node0.addEventListener("mouseenter", function(){
        node0.style.transform = "scale(1.1)";
    })
    node0.addEventListener("mouseleave", function(){
        node0.style.transform = "scale(1)";
    })

    node0.addEventListener("dblclick", function(){
        node0.remove();
    })

    document.getElementById("noteText").value = ' ';
}

function typeNote(){
    if(containerThree.style.display == "none")
        containerThree.style.display = "block";
    else
        containerThree.style.display = "none";
}

function setMargin(){
    var randomMar = ["-5px", "1px", "5px", "10px", "7px"];
    return randomMar[Math.floor(Math.random() * randomMar.length)];
}

function setRotation(){
    var randomRot = ["rotate(3deg)", "rotate(1deg)", "rotate(-1deg)", "rotate(-3deg)", "rotate(-5deg)", "rotate(-8deg)"];
    return randomRot[Math.floor(Math.random() * randomRot.length)];
}

function setColor(){
    var randomCol = ["#c2ff3d","#ff3de8","#3dc2ff","#04e022","#bc83e6","#ebb328"];
    return randomCol[Math.floor(Math.random() * randomCol.length)];
}