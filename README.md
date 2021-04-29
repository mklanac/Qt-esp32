# Qt esp32
 
* SerialPort is Windows PC GUI created in Visual Studio 2019 (using Qt Visual Studio Tools) that communicates via serial communication with esp32.
* esp32ArduinoSketch is sketch that you upload to esp32. The sketch is used to set the esp32 as an access point (hotspot). When you set the esp32 as an access point you create its own Wi-Fi network and nearby Wi-Fi devices can connect to it. 
* androidApp is Qt Android app created in Qt Creator 4.9.2 (Community). If your phone has Wi-Fi capabilities you can connect to esp32 without the need to connect to your router. When you connect to esp32 and run this app you will be able to send data to esp32, and esp32 can forward that data to your PC using serial communication.