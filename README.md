# Game of Thrones Tapestry 
This project consists of 2 separate .ino files for Arduino boards, and, of course, everything else on the 2ft by 3ft tapestry that cannot go in a Github repo directly. For pictures of the project, jump down to the bottom of the README, which has the demonstration images, and even a video of the theme song off an Arduino buzzer!

## Background

This project was created originally for my CSCI 497 class, but quickly became a passion project as I spent an obscene amount of time creating a completely functional and (relatively) to-scale map of the Game of Thrones universe. The map I used was the concept map for the show adaptation's later seasons, which in the end isn't the 'canon' map, or even makes sense in-universe, but who cares! Definitely not me... ~~I will never forgive you, David Benioff and D.B. Weiss~~ 😅

## Concepts

This project combines 3 core skills: Sewing, Electrical circuitry, and 2 Arduino's C++ programming.
I am no good at sewing, and electrical circuitry is more of a personal passion than my profession, but in the end, a working tapestry was made! By combining actuators and sensors along the various pins available on both my first Arduino board (Lilypad Protosnap Plus) and my second board (FLORA), allowing for one of the most complex projects I have completed.

## Implementation

### Motherboard
The map itself is created on a black fabric 2x3' tapestry, which acts as the 'motherboard' of the project. This is because every piece of electronics on the tapestry is connected using conductive thread, and if ANY of them touch, it will short the Arduino and turn off for safety reasons. This means the electrical thread is (for the most part) extremely organized, well-spaced, and definitely did not make me almost rage quit the project.

### Land Mass
The landmass of the project is created from a papyrus fabric cut into the shape of the 2 continents and the various islands, of which most are not even mentioned. Because of this, I only really added the islands that appear in the show, like the Iron Islands, Dragonstone, etc.

### Cities & Keeps (Lights - Actuator)
The castles of Game of Thrones are divided in their structure between Westeros and Essos (West and East continents). Westeros has a feudal system much like medieval Europe, where families and clans would make alliances, declare war, and most importantly, bend the knee. To demonstrate this in this project, the LEDs used for the different cities' house colors matched their color in the universe! Red for Lannister, Orange for Dorne, etc. Normal LEDs, like ones on a Christmas tree, are used for these general colors, and more complex colors like teal for The Vale are done with the limited Neopixels I had for the midterm.  

Essos, on the other hand, is filled with self-governing cities. Since there is no house color to base the cities off, I decided to use Neopixels for every city in Essos. With them all being Neopixels, I was able to program their color to match the culture, traditions, and beliefs associated with each city in Essos. For instance, (<ins>**SPOILER**</ins>) Braavos, a city where the many-faced god resides, is a tealish color, since their practices consist of water, illusions, and espionage.

### Wiring
Wiring the Arduinos, sensors, and actuators is completely done with conductive thread. Unlike a normal piece of thread, conductive thread has a woven structure like rope. This makes it strong, but also allows a super tiny piece of conductive thread to get unraveled or torn in only a few pieces of conductive 'twine.' This would not be an issue if it were not for these pieces of near-invisible metal to bridge the gap to a neighboring piece of conductive thread, or even worse, come off the parent thread completely and bridge a random arc anywhere on the tapestry! This is why a clean work space, pre-planning the conductive thread routes, and careful sewing are all crucial when wiring a project like this.   

The most important wiring is what should be done first - all of the sensors, followed by each house separately on its own port. This is crucial for the next various sensors, controlling them, since they would not otherwise be individually controllable, and it just makes the most sense for each house to have its own connection port.

### Sensors
The sensors controlling the lights for each Arduino consist of at least an on/off switch for the lights. On the Westeros Arduino, there is also a button for the song to play, which requires the lights to be on, and a light sensor to detect how dark the room is. The Essos Arduino has a gravity switch, which, when upright, will send an on signal (1) and an off signal (0) when hanging upside down.

### Light Behavior
The buzzer is programmed to play the Game of Thrones song by having 2 arrays - 1 for the note pitch and the other for its duration. Combining these arrays allows the song to be played, but why stop there? Using the pitch of the note along with the different ports, which are each connected to a different house in Westeros, means we can dynamically change the tapestry while the song is playing! This is done through a function that can quickly determine what lights should be on and off based on the song's pitch. This creates a wave or movement effect, where as the song gets higher pitch, more of Westeros lights up.  
  
Unlike Westeros' Arduino, Essos does not have a buzzer or button connected to it. Because of this limitation, I instead opted to have the gravity sensor control Denary's journey through Essos. She starts in Pentos, moves to the Dathraki camp, and then the rest would be spoilers! If you haven't seen it and have gotten this far in the documentation, please, I beg you, at least watch the first episode. If you don't think you can muster eight seasons, don't worry! ~~Only to season 5, maybe 6 is good.~~

### Power
Each Arduino is connected to a battery of some kind. The Westeros Arduino has a 3.3V rechargeable battery, which recharges when the Arduino is connected to a computer, while the Essos Arduino consists of a 5V battery pack containing 3 AAA batteries.


## Demonstration

