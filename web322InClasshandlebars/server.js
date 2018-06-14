var express = require("express");
var exphbs = require('express-handlebars');
var path = require("path");

var app = express();

var HTTP_PORT = process.env.PORT || 3000;

// call this function after the http server starts listening for requests
function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
}

////////////////////
// Register express-handlebars as the rendering engine for views
app.engine('.hbs', exphbs({ extname: 'hbs' }));
app.set('view engine', '.hbs');


//====================================================
app.get("/viewData", function (req, res) {

    var someData = {
        name: "John",
        age: 23,
        occupation: "developer",
        company: "Scotiabank",
        visible: true,
        contract: false
    };

    // Call res.render() and pass name of hbs view file
    res.render('viewData', {data : someData});

});
//====================================================
// setup http server to listen on HTTP_PORT
app.listen(HTTP_PORT, onHttpStart);