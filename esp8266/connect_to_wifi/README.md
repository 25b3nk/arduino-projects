## Introduction
Connect to your wifi connection using esp8266

## Items required

### Hardware
1. Arduino UNO
2. ESP8266 module
3. Male/Female Jumper pins

### Software and apps
1. Arduino IDE for uploading sketch

## Working
ESP8266 module connects to the WiFi and prints its own IP address onto the serial monitor. We can then ping this address.

## Notes
1. Connect `RST` of the esp8266 module to GND and remove to reset the module.
1. To run the program after uploading, remove `GPIO_0` from GND and reset the module.

## To-Do

- [x] Connect `ESP8266` to any WiFi connection.
- [ ] Create a `fritzing` circuit diagram and upload here.

## References
1. [Code reference](https://tttapa.github.io/ESP8266/Chap07%20-%20Wi-Fi%20Connections.html)
1. [Circuit connection reference](https://www.youtube.com/watch?v=N5MoXarCF_4&ab_channel=Technolabcreation)
