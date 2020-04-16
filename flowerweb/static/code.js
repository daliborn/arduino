alert();
function changeBackground(color) {
	var moisture = {{ moisture }};
	alert(moisture);
	document.body.style.background = "green";
	if (moisture > 600) {
	  document.getElementById("content").innerHTML = "<h1>Vlaznost niska, zalij odmah!</h1> nivo vlage: " + moisture;
	  document.body.style.background = "red";
	} else if (moisture > 500) {
		document.getElementById("content").innerHTML = "<h1>Vlaznost opada, zalij kad stigneš!</h1> nivo vlage: " + moisture;
		document.body.style.background = "yellow";
	} else{
		document.getElementById("content").innerHTML = "<h1>Dobra vlaznost, ne zalijevaj!</h1> nivo vlage: " + moisture;
		document.body.style.background = "green";
	}
}