// Author: Aidan Colombana
// Project: Final Project Code
// Date: June 2025


#include <Adafruit_NeoPixel.h>

const int switchPin = 12;  // switch for turning on the tapestry
const int tiltPin = 9;  // tilt sensor used for Daenery's travel according to show adaptation

#define CENTER_PIN 8 // Digital pin connected to the NeoPixel (SUPER BRIGHT)

#define EAST_PIXELS 6 // the port for the Neopixel chain of Braavos, Pentos, Myr, and Tyrosh
#define WEST_PIXELS 10 // the port for the Neopixel chain of the rest of the Essos cities

// Pins to controls the Neopixel Chains off of
#define NUMPIXELSWEST 4
#define NUMPIXELSEAST 8

// Create the Neopixel Chains
Adafruit_NeoPixel WestLEDPixels(NUMPIXELSWEST, WEST_PIXELS, NEO_GRB + NEO_KHZ800); // Setting up neopixel chained LEDs
Adafruit_NeoPixel EastLEDPixels(NUMPIXELSEAST, EAST_PIXELS, NEO_GRB + NEO_KHZ800); // Setting up neopixel chained LEDs

// Central light on Arduino - very bright and unneeded
Adafruit_NeoPixel centralLEDLight(NUMPIXELSWEST, CENTER_PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  Serial.begin(9600);  
  
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(tiltPin, INPUT_PULLUP);

  centralLEDLight.begin();
  centralLEDLight.setBrightness(5); // could be 0 but can be buggy with 0, so set to 5

  WestLEDPixels.begin();
  WestLEDPixels.setBrightness(70); 

  EastLEDPixels.begin();
  EastLEDPixels.setBrightness(70);

}

void loop() {

  centralLEDLight.setPixelColor(0, centralLEDLight.Color(0, 0, 0)); // Turn off central light it will give you a migraine
  centralLEDLight.show();

  int switchState = digitalRead(switchPin);  // Read the state of the switch
  int tiltState = digitalRead(tiltPin); // Read the state of the tilt switch

  Serial.print("SwitchState Value: ");
  Serial.print(switchState);

  Serial.print("    tiltState Value: ");
  Serial.println(tiltState);

  delay(250);  // delay for prints

  if (switchState == 0) {  // switch lights sewn to the tapestry to on. Also allows button to be pressed.


    // Toggles light show for cities Daenerys Targaryen visits in order
    if (tiltState == 0) {// tilt sensor flipped

      // Daenerys visits 6 cities, 2 visited twice, and a last run to show all conquered area (7 cities but Dragonstone isn't connected to Essos Arduino and between continents technically)
      for (int i = 0; i < 9; i++) {
        daenerysConqueredCity(i);
      }

      // turnOffEssosLEDS()
      delay(500);
    } else { // not flipped

      turnOnEssosLEDS();

    }
    
    delay(250);  // delay for prints

  } else { // Switch set to off
 
    turnOffEssosLEDS();

  }

}

// Turns on all Essos LEDs
void turnOnEssosLEDS() {

  // End & Start of show Esso cities
  WestLEDPixels.setPixelColor(0, WestLEDPixels.Color(20, 200, 150));  // Bravos - Many faced god
  WestLEDPixels.setPixelColor(1, WestLEDPixels.Color(20, 70, 255));  // Pentos - Rich / Winter is Coming

  // Not in show cities, but talked about
  WestLEDPixels.setPixelColor(2, WestLEDPixels.Color(60, 100, 80));  // Myr - never visited but craftsman
  WestLEDPixels.setPixelColor(3, WestLEDPixels.Color(30, 20, 250));  // Tyrosh - dyed beards?

  WestLEDPixels.show();

  EastLEDPixels.setPixelColor(0, EastLEDPixels.Color(100, 150, 0));  // Vaes Dathrok - Dathroki Horde Camp
  EastLEDPixels.setPixelColor(1, EastLEDPixels.Color(100, 220, 220));  // Qarth - Rich and exotic
  
  // Slaver's Bay Cities 
  EastLEDPixels.setPixelColor(2, EastLEDPixels.Color(150, 20, 0));  // Astapor - Unsullied
  EastLEDPixels.setPixelColor(3, EastLEDPixels.Color(250, 200, 0));  // Yunkai - Second Sons
  EastLEDPixels.setPixelColor(4, EastLEDPixels.Color(50, 150, 40));  // Meereen - Daenerys: Breaker of chains, mother of dragons
  
  EastLEDPixels.setPixelColor(5, EastLEDPixels.Color(120, 120, 120));  // Valyria - The Stone Men
  EastLEDPixels.setPixelColor(6, EastLEDPixels.Color(70, 0, 150));  // Lys - Pleasure, Beuaty, and Perfume
  EastLEDPixels.setPixelColor(7, EastLEDPixels.Color(80, 50, 30));  // Volantis - Oldest free city and home of the Red Temple

  EastLEDPixels.show();

}

// Turns off all Essos LEDs
void turnOffEssosLEDS() {
  for (int i = 0; i < 4; i++) {
      WestLEDPixels.setPixelColor(i, WestLEDPixels.Color(0, 0 , 0));
    }
    WestLEDPixels.show();

    for (int i = 0; i < 8; i++) {
      EastLEDPixels.setPixelColor(i, EastLEDPixels.Color(0, 0 , 0));
    }
    
    // EastLEDPixels.clear();
    EastLEDPixels.show();
}

// Show each city Daenery's visits in order. In the first city (Pentos) she is a prisoner so it is red.
// After Pentos her character develops and she ends up conquering the following cities besides Qarth,
//  eventually ending up and making her base of operations in Meereen
void daenerysConqueredCity(int city) {

    Adafruit_NeoPixel* strip; // Strip with associated light
    int pixelNumber = 0;

    turnOffEssosLEDS();

    Serial.print("Daenerys is in city case: ");
    Serial.println(city);

    switch (city) {
      case 0: // Pentos 
        // West strip doesn't work as well since 3.3V instead of 5V, but it works out to be
        // red and this works since in Pentos she was a prisoner
        // WestLEDPixels.setPixelColor(1, WestLEDPixels.Color(190, 190, 190));
        strip = &WestLEDPixels;
        pixelNumber = 1;
        break;
      case 1: // Vaes Dothrak
        // EastLEDPixels.setPixelColor(0, EastLEDPixels.Color(190, 190, 190));
        strip = &EastLEDPixels;
        pixelNumber = 0;
        break;
      case 2: // Qarth
        // EastLEDPixels.setPixelColor(1, EastLEDPixels.Color(190, 190, 190));
        strip = &EastLEDPixels;
        pixelNumber = 1;
        break;
      case 3: // Astapor
        // EastLEDPixels.setPixelColor(2, EastLEDPixels.Color(190, 190, 190));
        strip = &EastLEDPixels;
        pixelNumber = 2;
        break;
      case 4: // Yunkai
        // EastLEDPixels.setPixelColor(3, EastLEDPixels.Color(190, 190, 190));
        strip = &EastLEDPixels;
        pixelNumber = 3;
        break;
      case 5: // Meereen
        // EastLEDPixels.setPixelColor(4, EastLEDPixels.Color(190, 190, 190));
        strip = &EastLEDPixels;
        pixelNumber = 4;
        break;
      case 6: // Vaes Dothrak (Second time)
        // EastLEDPixels.setPixelColor(0, EastLEDPixels.Color(190, 190, 190));
        strip = &EastLEDPixels;
        pixelNumber = 0;
        break;
      case 7: // Back to Meereen
        // EastLEDPixels.setPixelColor(4, EastLEDPixels.Color(190, 190, 190));
        strip = &EastLEDPixels;
        pixelNumber = 4;
        break;
      case 8 : // Show all conquered land
        EastLEDPixels.setPixelColor(0, EastLEDPixels.Color(190, 190, 190));
        EastLEDPixels.setPixelColor(2, EastLEDPixels.Color(190, 190, 190));
        EastLEDPixels.setPixelColor(3, EastLEDPixels.Color(190, 190, 190));
        EastLEDPixels.setPixelColor(4, EastLEDPixels.Color(190, 190, 190));

        EastLEDPixels.show();
        delay(1500);
        break;
      default:
        break;
    }

    if (city != 8) {
    // fade in
      for (int i = 0; i < 191; i += 10) {
        strip->setPixelColor(pixelNumber, strip->Color(i, i, i));
        strip->show();
        delay(50);
      }

      // fade out
      for (int i = 190; i > 0; i -= 10) {
        strip->setPixelColor(pixelNumber, strip->Color(i, i, i));
        strip->show();
        delay(50);
      }

      strip->setPixelColor(pixelNumber, strip->Color(0, 0, 0));
      strip->show();
    }

}