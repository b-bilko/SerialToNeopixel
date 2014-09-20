#include <Adafruit_NeoPixel.h> //includes neopixel library

/*
  Serial input with parsing and neopixel display for driver station
 
 
 The circuit:
 * Neopixels on Pin 6 (subject to change)
 
 created 7 May 2013
 by Tom Igoe
 
 edited on September 20 2015
 by Daniel Rostovtsev
 
 */
 
#define PIN      6  //subject to change
#define NUMPIXELS      4  //subject to change

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_RGB + NEO_KHZ800);
int delayTime = 500;

void setup() {
  Serial.begin(9600); //subject to to change
  pixels.begin(); //initiates pixels
}

void loop() {
  // Assumes a string in from the serial port like so:
  // P ledNumber, Red, Green , Blue\n
  // for example: "s5,200\n":

  int pixelNumber = 0;
  int red = 0;
  int green = 0;
  int blue = 0;
  
  if (Serial.find("P")) {
    pixelNumber = Serial.parseInt(); // parses numeric characters before the comma
    red = Serial.parseInt(); // parses numeric characters after the comma
    green = Serial.parseInt(); // parses numeric characters after the comma
    blue = Serial.parseInt(); // parses numeric characters after the comma
    
    // set the neopixels:
       // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(pixelNumber, pixels.Color(red,green,blue)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(delayTime); // Delay for a period of time (in milliseconds).
    
  }
}




