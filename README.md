# ESP8266_with_OLED
My first trying with Arduino and a mini OLED display.<br>
Its display a logo and welcome text and after thet its will be animated.

## Parts: 
- Adafruit ESP8266 as NodeMCU 1.0 (ESP-12E modul),
- 0.96″ 128x64 mini OLED display (I use white color for that project),
- Jumper cables.


You can see a picture from the full setup here:<br>
![Picture from the setup](/ESP8266-OLED.jpg)

## Arduino Modules:
- Adafruit_SSD1306,
- Adafruit_GFX.

If you get an error message for the display, or the display shows wrong resolution, make this change, but my code trying to overwrite the defaults.<br>
The display size must be changed in the Adafruit_SSD1306.h header file to make it work for us.<br>
*My Documents > Arduino > libraries > Adafruit_SSD1306 > Adafruit_SSD1306.h*<br>
Open Adafruit_SSD1306.h file in a text editor. Scroll down the file to find the section with the SSD1306 Displays or directly go to line no. 28-29. Comment out #define SSD1306_128_32 and uncomment #define SSD1306_128_64

## Connection:
- The display GND to ESP G
- The display VCC to ESP 3V
- The display SCL to ESP D1 as GPIO 1
- The display SDA to ESP D2 as GPIO 2

Coding in Arduino IDE 1.8.19<br>
I made this code from sources of the internet. There is no copyright, use it as you want.
