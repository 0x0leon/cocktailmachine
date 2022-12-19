import { SerialPort } from "serialport";

// serial port content


function printPorts(){
    SerialPort.list().then (
        ports => ports.forEach(port => console.log(port.path))
    )
}
