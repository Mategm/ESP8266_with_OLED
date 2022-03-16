/*********
  Gabor Mate
  https://github.com/Mategm
*********/

#include <Wire.h>
#include <Adafruit_GFX.h> // Its needed for the animations
#include <Adafruit_SSD1306.h> // OLED library

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins) SDA = D2; SCL = D1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200); // I think, its good for everything, utnil now there is no problem.

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Init, Its works for my 128x64 OLED 0,96" screen
    Serial.println(F("SSD1306 allocation failed")); // Print to com port the error
    for(;;); // Don't proceed, loop forever
  }
  display.display(); // its display the inbuilt logo
  delay(5000); // display the logo for 5 sec
  display.clearDisplay(); // Delete the logo from the screen

  display.setTextSize(1); //1-8; 1 is default
  display.setTextColor(WHITE); // WHITE is the the default text color, BLACK, WHITE is the inverted
  display.setCursor(1,1); //0,0 to 120,57
  // Display static text
  display.println("Hello world!");
  display.println("Hello user!");
  display.setTextColor(BLACK, WHITE); //Inverted text
  display.println("Its works!");
  display.drawRect(0, 0, 73, 26, WHITE); // border for the text
  display.display(); // update the screen
  delay(5000); // wait 5 seconds before animating
}

void loop() {
  // Scroll in various directions, pausing in-between:
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(2000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrolldiagright(0x00, 0x07); // Only white screen, not works on Yellow-Blue dual screen
  delay(2000);
  display.startscrolldiagleft(0x00, 0x07); // Only white screen, not works on Yellow-Blue dual screen
  delay(2000);
  display.stopscroll();
  delay(1000);
}
