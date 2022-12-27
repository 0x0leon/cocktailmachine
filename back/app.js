var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var app = express();


var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');
var machineRoter = require('./routes/machine');


var { SerialPort, ReadlineParser } = require('serialport');

const serialport = new SerialPort({ path: 'COM3', baudRate: 9600 })
const parser = serialport.pipe(new ReadlineParser({ delimiter: '\n' }))

// Add headers before the routes are defined
app.use(function (req, res, next) {

  // Website you wish to allow to connect
  res.setHeader('Access-Control-Allow-Origin', 'http://127.0.0.1:3001');

  // Request methods you wish to allow
  res.setHeader('Access-Control-Allow-Methods', 'GET, POST, OPTIONS, PUT, PATCH, DELETE');

  // Request headers you wish to allow
  res.setHeader('Access-Control-Allow-Headers', 'X-Requested-With,content-type');

  // Set to true if you need the website to include cookies in the requests sent
  // to the API (e.g. in case you use sessions)
  res.setHeader('Access-Control-Allow-Credentials', true);

  // Pass to next layer of middleware
  next();
});

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));


app.use('/', indexRouter);
app.use('/users', usersRouter);
app.use('/machine', machineRoter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

app.use(function(req,res,next){
    args = req.url.split(',');
})



//_____________________________________________________________________________


const http = require('http').Server(app)
const io = require('socket.io')(http)

io.on('connection', function(socket) {
    console.log('Node is listening to port');
});

parser.on('data', function(data) {
    console.log('Received data from port: ' + data);
    io.emit('data', data);
});

//_____________________________________________________________________________


/*
------------------------------------------------------------------------------------------------------
*/


console.log("test")


// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.send('error');
});

module.exports = app;
