import { SerialPort } from "serialport";

// serial port content

SerialPort.list().then (
    ports => ports.forEach(port => console.log(port.path))
)