// general.js - general purpose JavaScripts
// Author: Ken Geddes
// Date:   05/19/2006

var scale = 2; 
window.onerror = handleError;

function enhanceImage(image) {
	image.width = image.width * scale;
	image.height = image.height * scale;
} // enhanceImage

function handleError(type, url, lineNo) {
   window.status = 'Error: ' + type + ' on line ' + lineNo;
   return true; // so status bar displays message
} // handleError

// open kensBank.html in a new window with no statusbar (for extra sneakiness)
function openKensBank() {
	var url = 'http://ciswebs.smc.edu/cs85/geddes_james/examples/kensBank.html';
	var target = '';
	var features = 'location,menubar,innerHeight=400,innerWidth=500,resizable,scrollbars,titlebar,toolbar';
	window.open(url, target, features);
   return false;
} // openKensBank

function restoreImage(image) {
	image.width = image.width / scale;
	image.height = image.height / scale;
} // restoreImage

function toggleFullText() {
	//fullTextVisibility = (?:);
} // toggleFullText
