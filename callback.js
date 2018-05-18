//Blocking Code Service 

var fs = require('fs');

var data = fs.readFileSync('web322.txt');

console.log(data.toString());

console.log('Dense Webdev course');
console.log('Really nice WebDev course');
console.log('A little tough web course');

console.log('Blocking Program Ended');

console.log('************************************************');

//Non Blocking Code Example 

var fs = require('fs');

fs.readFile('web322.txt' , function(err , data ){

    if(err){

     return console.error(err);

    }

    console.log(data.toString());

});

console.log('Dense Webdev course');
console.log('Really nice WebDev course');
console.log('A little tough web course');

console.log('Non Blocking Program Ended');
