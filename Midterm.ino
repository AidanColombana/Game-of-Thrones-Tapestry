// Author: Aidan Colombana
// Project: Midterm Project Code
// Date: May 2025

const int switchPin = A9;  // switch for turning on the tapestry
const int buzzer = A3; // buzzer plays song
const int button = A4; // button

// game of thrones melody in pitches
int melody[] = {
  392, 262, 311, 349, 392, 262, 311, 349,
  392, 262, 311, 349, 392, 262, 311, 349,
  392, 262, 330, 349, 392, 262, 330, 349,
  392, 262, 330, 349, 392, 262, 330, 349,
  392, 262,

  311, 349, 392, 262, 311, 349,
  294,
  349, 233,
  311, 294, 349, 233,
  311, 294, 262,

  392, 262,

  311, 349, 392, 262, 311, 349,
  294,
  349, 233,
  311, 294, 349, 233,
  311, 294, 262,
  392, 262,
  311, 349, 392, 262, 311, 349,

  294,
  349, 233,
  294, 311, 294, 233,
  262,
  523,
  466,
  262,
  392,
  311,
  311, 349,
  392,

  523,
  466,
  262,
  392,
  311,
  311, 294,
  523, 392, 415, 466, 523, 392, 415, 466,
  523, 392, 415, 466, 523, 392, 415, 466,

  0, 831, 932, 1047, 784, 831, 932,
  1020, 784, 831, 932, 1020, 784, 831, 932
};


// duration of each note in the song
int durations[] = {
  8, 8, 16, 16, 8, 8, 16, 16,
  8, 8, 16, 16, 8, 8, 16, 16,
  8, 8, 16, 16, 8, 8, 16, 16,
  8, 8, 16, 16, 8, 8, 16, 16,
  4, 4,

  16, 16, 4, 4, 16, 16,
  1,
  4, 4,
  16, 16, 4, 4,
  16, 16, 1,

  4, 4,

  16, 16, 4, 4, 16, 16,
  1,
  4, 4,
  16, 16, 4, 4,
  16, 16, 1,
  4, 4,
  16, 16, 4, 4, 16, 16,

  2,
  4, 4,
  8, 8, 8, 8,
  1,
  2,
  2,
  2,
  2,
  2,
  4, 4,
  1,

  2,
  2,
  2,
  2,
  2,
  4, 4,
  8, 8, 16, 16, 8, 8, 16, 16,
  8, 8, 16, 16, 8, 8, 16, 16,

  4, 16, 16, 8, 8, 16, 16,
  8, 16, 16, 16, 8, 8, 16, 16
};


// lights for the song playing
const int led15 = 15;
const int led16 = 16;
const int led17 = 17;
const int led18 = 18;
const int led19 = 19;
const int led20 = 20;

#define DORNE_PIN 11 // the port all the neopixels are ran off of
#define NUMPIXELS 4  // 4 in order Vale -> Dragonstone -> Sunspear -> other Dorne city

#include <Adafruit_NeoPixel.h>


// lights for the different houses on the map
Adafruit_NeoPixel dorneLEDPixel(NUMPIXELS, DORNE_PIN, NEO_GRB + NEO_KHZ800); // Setting up neopixel chained LEDs

const int ledTheReach = A5;  // house Reach - Green
const int ledLannister = 6;        // house Lannister - Red
const int ledTheStormLands = A7;  // house StormLands - Yellow
const int ledTheRiverlands = A8;  // house Riverland - Blue (And stark attatched)
// const int ledStark = 11;          // house Stark - White


void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(button, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  // music lights on board
  pinMode(led15, OUTPUT);
  pinMode(led16, OUTPUT);
  pinMode(led17, OUTPUT);
  pinMode(led18, OUTPUT);
  pinMode(led19, OUTPUT);
  pinMode(led20, OUTPUT);

  // house colors through Neopixel Chain
  dorneLEDPixel.begin();
  dorneLEDPixel.setBrightness(75); // not 100% brightness because can damage eyes and draws more power than needed.

  // house colors normal LEDs
  pinMode(ledTheReach, OUTPUT);
  pinMode(ledLannister, OUTPUT);
  pinMode(ledTheStormLands, OUTPUT);
  pinMode(ledTheRiverlands, OUTPUT);
  // pinMode(ledStark, OUTPUT);
}

void loop() {

  // Serial.begin(9600);

  int switchState = digitalRead(switchPin);  // Read the state of the switch
  int buttonState = digitalRead(button);

  Serial.print("SwitchState Value: ");
  Serial.print(switchState);
  Serial.print("    button Value: ");
  Serial.println(buttonState);

  delay(250);  // delay for prints

  if (switchState == 0) {  // switch lights sewn to the tapestry to on. Also allows button to be pressed.

    if (buttonState == 1) {  // button not pressed - just switch on
      turnOnHouseLeds();


      // Delay between playing song
      delay(250);  // 250 + 250 is 0.5 second after button pushed

    } else if (buttonState == 0) {  // hit button to play music once

      turnOffHouseLeds(); // set all LEDs to off before dynamically setting them during melody

      for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(melody[0]); thisNote++) {
        int noteDuration = 1000 / durations[thisNote];  // Calculate note duration for song
        tone(buzzer, melody[thisNote], noteDuration);   // Play the note

        showNoteLights(melody[thisNote]);

        // multiplied by 1.5 so that notes durations are drawn out an extra 50%
        int pauseBetweenNotes = noteDuration * 1.5;  // Pause between notes for duration
        delay(pauseBetweenNotes);                    // Wait before playing the next note

        // LEDBrightness is not used, but could be in the future if needed

        // int LEDBrightness = melody[thisNote] / 4; //
        // Serial.print("LEDBrightness Value: ");
        // Serial.println(LEDBrightness);

        digitalWrite(led15, LOW);
        digitalWrite(led16, LOW);
        digitalWrite(led17, LOW);
        digitalWrite(led18, LOW);
        digitalWrite(led19, LOW);
        digitalWrite(led20, LOW);

        noTone(buzzer);  // Stop playing the tone
      }
    }

  } else {  // turn all lights off when switched off
    turnOffHouseLeds();
  }
}

void turnOnHouseLeds() {
  // Setting neopixel chain on with house colors and using a .show after each.
  dorneLEDPixel.setPixelColor(0, dorneLEDPixel.Color(0, 220 , 200));  // Dark red for Dragonstone
  dorneLEDPixel.show();
  dorneLEDPixel.setPixelColor(1, dorneLEDPixel.Color(80, 0, 0));  // Dark red for Dragonstone
  dorneLEDPixel.show();
  dorneLEDPixel.setPixelColor(2, dorneLEDPixel.Color(255, 150, 0));  // Orange for House Dorne
  dorneLEDPixel.show();
  dorneLEDPixel.setPixelColor(3, dorneLEDPixel.Color(255, 150, 0));  // Orange for House Dorne
  dorneLEDPixel.show();

  // Normal digitalWrite for basic LEDs
  digitalWrite(ledTheReach, HIGH);
  digitalWrite(ledLannister, HIGH);
  digitalWrite(ledTheStormLands, HIGH);
  digitalWrite(ledTheRiverlands, HIGH);
  // digitalWrite(ledStark, HIGH);
}

void turnOffHouseLeds() {
  // digitalWrite(ledDorne, LOW);
  dorneLEDPixel.setPixelColor(0, 0);  // Set off
  dorneLEDPixel.setPixelColor(1, 0);  // Set off
  dorneLEDPixel.setPixelColor(2, 0);  // Set off
  dorneLEDPixel.setPixelColor(3, 0);  // Set off
  // dorneLEDPixel.show();
  dorneLEDPixel.show();
  digitalWrite(ledTheReach, LOW);
  digitalWrite(ledLannister, LOW);
  digitalWrite(ledTheStormLands, LOW);
  digitalWrite(ledTheRiverlands, LOW);
  // digitalWrite(ledStark, LOW);
}

// This function is used inside of the music loop to dynamically set the lights
// on and off based on the frequency of the notes being played
void turnOffHouseLedsVariable(bool dorne, bool dragonstone, bool vale, bool lannister, bool reach, bool stormlands, bool riverlands, bool stark) {
  if (dorne == false) {
    dorneLEDPixel.setPixelColor(2, 0);
    dorneLEDPixel.setPixelColor(3, 0);
    dorneLEDPixel.show();
  } else {
    dorneLEDPixel.setPixelColor(2, dorneLEDPixel.Color(255, 150, 0));  // Orange for House Dorne
    dorneLEDPixel.setPixelColor(3, dorneLEDPixel.Color(255, 150, 0));  // Orange for House Dorne
    dorneLEDPixel.show();
  }
  if (dragonstone == false) {
    dorneLEDPixel.setPixelColor(1, 0);
    dorneLEDPixel.show();
  } else {
    dorneLEDPixel.setPixelColor(1, dorneLEDPixel.Color(80, 0, 0));  // Dark red for Dragonstone
    dorneLEDPixel.show();
  }
  if (vale == false) {
    dorneLEDPixel.setPixelColor(0, 0);
    dorneLEDPixel.show();
  } else {
    dorneLEDPixel.setPixelColor(0, dorneLEDPixel.Color(0, 220 , 200));  // teal for vale
    dorneLEDPixel.show();
  }
  if (lannister == false) {
    digitalWrite(ledLannister, LOW);
  } else {
    digitalWrite(ledLannister, HIGH);
  }
  if (reach == false) {
    digitalWrite(ledTheReach, LOW);
  } else {
    digitalWrite(ledTheReach, HIGH);
  }
  if (stormlands == false) {
    digitalWrite(ledTheStormLands, LOW);
  } else {
    digitalWrite(ledTheStormLands, HIGH);
  }
  if (riverlands == false) {
    digitalWrite(ledTheRiverlands, LOW);
  } else {
    digitalWrite(ledTheRiverlands, HIGH);
  }
  // Stark is connected to Riverlands - truly ironic. but is something I could change for final since I'll have more ports - could not happen without extra hardware
  // if (stark == false) {
  //   digitalWrite(ledStark, LOW);
  // } else {
  //   digitalWrite(ledStark, HIGH);
  // }
}

// Function that plays the different lights based off the notes pitch
void showNoteLights(int note) {
  if (note > 800) {
    digitalWrite(led20, HIGH);
    turnOffHouseLedsVariable(true, true, true, true, true, true, true, false);
  } else if (note > 600) {
    digitalWrite(led19, HIGH);
    turnOffHouseLedsVariable(true, true, true, true, true, true, true, false);
  } else if (note > 550) {
    digitalWrite(led18, HIGH);
    turnOffHouseLedsVariable(true, true, true, true, true, true, false, false);
  } else if (note > 500) {
    digitalWrite(led18, HIGH);
    turnOffHouseLedsVariable(true, true, false, true, true, false, true, false);
  } else if (note > 450) {
    digitalWrite(led17, HIGH);
    turnOffHouseLedsVariable(false, true, false, true, true, false, false, false);
  } else if (note > 390) {
    digitalWrite(led17, HIGH);
    turnOffHouseLedsVariable(true, true, true, true, false, false, true, false);
  } else if (note > 350) {
    digitalWrite(led16, HIGH);
    turnOffHouseLedsVariable(true, true, false, true, false, true, false, false);
  } else if (note > 300) {
    digitalWrite(led16, HIGH);
    turnOffHouseLedsVariable(false, false, true, false, true, true, false, false);
  } else if (note > 269) {
    digitalWrite(led15, HIGH);
    turnOffHouseLedsVariable(true, false, true, false, false, false, false, false);
  } else if (note < 270) {
    digitalWrite(led15, HIGH);
    turnOffHouseLedsVariable(true, true, false, false, false, false, false, false);
  } 
  
}
