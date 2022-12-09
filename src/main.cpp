/*

TITRE          : Test Final ELTE.
AUTEUR         : Franck Nkeubou Awougang
DATE           : 09/12/2022
DESCRIPTION    : Donner une description du programme
VERSION        : 0.0.1

*/



#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define NUM_LED 1     // Number of LEDs in a strip

int ledPin = LED_BUILTIN;                // Connect LED to pin 13
int RGB_PIN = 4;
int switcher = 3;                 // Connect Tilt sensor to Pin3
int MotorPIN = 5;                  // Pin to control motor.

Adafruit_NeoPixel RGB_Strip = Adafruit_NeoPixel(NUM_LED, RGB_PIN, NEO_GRB + NEO_KHZ800);

void colorWipe(uint32_t c);

void setup()
{
  // Configuration des broches.
  pinMode(ledPin, OUTPUT);      // Set digital pin 13 to output mode
  pinMode(MotorPIN, OUTPUT);      // Set digital pin 5 to output mode
  pinMode(switcher, INPUT);       // Set digital pin 3 to input mode
  // Configuration de la LED RGB.
  RGB_Strip.begin();
  RGB_Strip.show();
  RGB_Strip.setBrightness(128);    // Set brightness, 0-255 (darkest - brightest)

}
void loop()
{

   if(digitalRead(switcher)==HIGH) //Read sensor value
     {
        digitalWrite(ledPin, HIGH);   // Turn on LED when the sensor is tilted
        digitalWrite(MotorPIN, HIGH);   // Turn on the motor
        colorWipe(RGB_Strip.Color(0, 255, 0));  // Green
     }
   else
     {
        digitalWrite(ledPin, LOW);    // Turn off LED when the sensor is not triggered
        digitalWrite(MotorPIN, LOW);    // Turn off the motor
        colorWipe(RGB_Strip.Color(255, 0, 0));  // RED
     }
}


void colorWipe(uint32_t c) {
  for (uint16_t i = 0; i < RGB_Strip.numPixels(); i++) {
    RGB_Strip.setPixelColor(i, c);
    RGB_Strip.show();
  }
}