if((navigator.appName == "Netscape" && parseInt(navigator.appVersion) >= 3 && navigator.userAgent.indexOf("Opera") == -1) || (navigator.appName == "Microsoft Internet Explorer" && parseInt(navigator.appVersion) >= 4) || (navigator.appName == "Opera" && parseInt(navigator.appVersion) >= 5)) {
	var MTMCodeFrame = "code";
	for(i = 0; i < parent.frames.length; i++) {
		if(parent.frames[i].name == MTMCodeFrame && parent.frames[i].MTMLoaded) {
			parent.frames[i].MTMTrack = true;
			setTimeout("parent.frames[" + i + "].MTMDisplayMenu()", 50);
			break;
		}
	}
}
