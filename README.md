# ArduFi

How to Install Arduino IDE Software

* Visit: https://www.arduino.cc/en/Main/Software

* Download the Arduino IDE Installer for your Operating System

* Install the software

For ESP32 Board (Windows):

* Download and install the Arduino IDE: https://www.arduino.cc/en/Main/Software 

* Download https://github.com/espressif/arduino-esp32/archive/master.zip 

* Move the downloaded zip to ”C:/Users/[YOUR_USER_NAME]/Documents/Arduino/hardware/espressif/esp32” and unzip it

* Open “tools” and double-click “get.exe”

* Download the drivers from https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers and unzip the file

* Open CP210x_Universal_Windows_Driver/ and double-click CP210xVCPInstaller_version.exe

* Plug your ESP32 board and wait for the drivers to install

* Start Arduino IDE

* Select your board in Tools > Board menu

* Select the COM port that the board is attached to

* Compile and upload (You might need to hold the boot button while uploading)

For ESP32 Board (MacOS):

* Download and install the Arduino IDE: https://www.arduino.cc/en/Main/Software 

* Open Terminal, copy and paste the following: xcode-select --install 

* After first installation, open terminal and paste the following:
mkdir -p ~/Documents/Arduino/hardware/espressif && \ cd ~/Documents/Arduino/hardware/espressif && \ git clone https://github.com/espressif/arduino-esp32.git esp32 && \ cd esp32 && \ git submodule update --init --recursive && \ cd tools && \ python get.py 

* Download the drivers from https://www.silabs.com/products/development-tools/software/usb-to-uart-bridge-vcp-drivers and unzip the file

* Install the drivers

* Plug your ESP32 board and wait for the drivers to install

* Start Arduino IDE

* Select your board in Tools > Board menu

* Select the COM port that the board is attached to

* Compile and upload (You might need to hold the boot button while uploading)

For ESP8266 Board:

* Open File -> Preferences and paste this link http://arduino.esp8266.com/stable/package_esp8266com_index.json in “Additional Boards Manager URLs”

* Open Tools -> Board:-> Boards Manager dialog box. Somewhere in there you will see the entry “esp8266 of ESP8266 Community” select that. The Install button will appear, click the Install button. Wait for a while… This process will take some time to download and complete. After the install it is a good idea to shut the Arduino program and restarted it.

* Go to Tools -> Board: scroll way down and select WeMos D1 R2 & mini. 

* To select the speed of communication between the WeMos-D1R2 and the computer. Go to Tools | Upload Speed: and select 921600. We are ready to upload our first sketch.

* Test drive the complete setup using the boiler plate sketch.

* To upload the boiler plate sketch go to Sketch | Upload or use the shortcut key Crtl+U or click on the right arrow button next to the check mark. A successful compile and upload means all systems are working and we are ready to get to the real stuff.
