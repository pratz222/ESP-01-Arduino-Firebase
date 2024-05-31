# ESP-01-Arduino-Firebase
Working template for Reading sensor data using Arduino Uno and then sending it to Firebase using ESP-01

Connection and Upload Procedure Help : https://www.hackster.io/pratikdesai/how-to-program-esp8266-esp-01-module-with-arduino-uno-598166

Select Board : GENERIC ESP8266






/////////////////////////////////////////////////////////// CONNECTION AND UPLOAD PROCESS ////////////////////////////////////////////////

Step 1:
Connections for programming

(Find the code in attachments)

ESP8266:-------------- >Arduino:

GND -------------------------- GND

GPIO-2 -------------------------- Not connected (open)

GPIO-0 -------------------------- GND

RXD -------------------------- RX

TXD -------------------------- TX

CHPD ------------------------ 3.3V

RST -------------------------- Not connected (open) *(Read Below Instruction)

VCC -------------------------- 3.3V

Very Important Instruction:
Now before hitting upload, take GPIO-0 to ground.

And RST to ground afterwards, remove RST after half a second (the blue LED flashes for some millisecond).

Hit upload, the blue flashes once and then blinks till it gets uploaded.

Now you are all done.



Step 2:
After programming, remove the serial Arduino cable and plug it again and take out GPIO-0 from GND and just interchange the connection of RX and TX that is RX connect to TX and TX connect to RX.

Connections after programming

ESP8266:-------------- >Arduino:

GND -------------------------- GND

GPIO-2 -------------------------- Not connected (open)

GPIO-0 -------------------------- Not connected (open)

RXD -------------------------- TX

TXD -------------------------- RX

CHPD ------------------------ 3.3V

RST -------------------------- Not connected (open)

VCC -------------------------- 3.3V
