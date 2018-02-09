 
var BitStuffing = function () {
var counter = 0;
var BITS = ['0','1','1','1','1','1','1','0','1','1','1','1','1','1','0'];
var flag = "01111110";
var stuffedBits = "";
var c;
var charCounterNormal;
var charCounterStuffed;
    
  for (charCounterNormal = 0; charCounterNormal < BITS.length; charCounterNormal++ ){
};
//console.log(charCounterNormal);
  for (var i = 0; i<BITS.length; i++) {
    c = BITS[i];
    stuffedBits = stuffedBits + c;
    if (BITS[i] == 1) {
      counter++;
    }
    if (counter == 5) {
      stuffedBits = stuffedBits + "0";
    }
if (counter == 11) {
      stuffedBits = stuffedBits + "0";
  }
  }
for (charCounterStuffed = 0; charCounterStuffed < stuffedBits.length; charCounterStuffed++){{}
}
//console.log(stuffedBits);
//console.log(charCounterStuffed);
var framing = flag + stuffedBits + flag;
var framedAsString = framing.split('').join(' ');
var BITSAsString = BITS.join(' ');
var stuffedBitsAsModifiedString = stuffedBits.split('').join(' ');
//console.log(stuffedBitsAsModifiedString);
console.log('Before Stuffing: ' + BITSAsString + ' -- ' + charCounterNormal + ' charachters');
console.log('After Stuffing:  ' + stuffedBitsAsModifiedString + ' -- ' + charCounterStuffed + ' charachters');
console.log('After framing:' + framedAsString);
}

BitStuffing();
