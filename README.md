# ArduFi

Visit: https://www.arduino.cc/en/Main/Software

Download the Arduino IDE Installer for your Operating System

Install the software

Open File -> Preferences and paste this link http://arduino.esp8266.com/stable/package_esp8266com_index.json in “Additional Boards Manager URLs”

Open Tools -> Board:-> Boards Manager dialog box. Somewhere in there you will see the entry “esp8266 of ESP8266 Community” select that. The Install button will appear, click the Install button. Wait for a while… This process will take some time to download and complete. After the install it is a good idea to shut the Arduino program and restarted it.

Go to Tools -> Board: scroll way down and select WeMos D1 R2 & mini. 

To select the speed of communication between the WeMos-D1R2 and the computer. Go to Tools | Upload Speed: and select 921600. We are ready to upload our first sketch.

Test drive the complete setup using the boiler plate sketch.

To upload the boiler plate sketch go to Sketch | Upload or use the shortcut key Crtl+U or click on the right arrow button next to the check mark. A successful compile and upload means all systems are working and we are ready to get to the real stuff.

TODO: Download https://github.com/tzapu/WiFiManager and move in the library folder
