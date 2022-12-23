const { SerialPort, ReadlineParser } = require('serialport')
const serial = require('serialport')

// serial port content

const port = new SerialPort("COM3" , {
    baudRate: 9600,
})
 

const parser = new ReadlineParser();
port.pipe(parser);


port.on("data", data => console.log(data));

port.write("DATA DATA DATA")