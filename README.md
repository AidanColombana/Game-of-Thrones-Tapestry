# Game of Thrones Tapestry 
This project consists of 2 seperate .ino files for Arduino boards, and, of course, everything else on the 2ft by 3ft tapestry that cannot go in a Github repo directly.

## Background

This project was created originally for my CSCI 497 class, but quickly became a passion project as I spent an obscene amount of time creating a completely function and (relatively) to scale map of the Game of Thrones universe. The map I used was the concept map for the show adaptation's later seasons, which in the end isn't the 'canon' map, or even makes sense in universe, but who cares! Definitely not me... ~~I will never forgive you David Benioff and D.B. Weiss~~ 😅

## Concepts

This project combines 3 core skills: Sewing, Electrical circuitry, and 2 Arduino's C++ programming.
I am no good at sewing, and electrical circuitry is more of a personal passion than my profession, but in the end a working tapestry was made! By combining actuators and sensors along the various pins available on my both my first Arduino board (Lilypad Protosnap Plus) and my second board (FLORA) allowed for one of the most complex project I have completed.

## Implementation

### Motherboard
The map itself is created on a black fabric 2x3' tapestry which acts as the 'motherboard' of the project. This is because every piece of electronics on the tapestry is connected using conductive thread, and if ANY of them touch, it will short the arduino and turn off for safety reasons. This means the electrical thread is (for the most part) extremely organized, well spaced, and definitely did not make me almost rage quit the project.

### Land Mass
The landmass of the project is created from a papyrus fabric cut into the shape of the 2 continents and the various island, of which most are not even mentioned. Because of this, I only really added the island that appear in the show, like the Iron Islands, Dragonstone, etc.

### Cities & Keeps
The castles of game of thrones are divided in their structure between Westeros and Essos (West and East continents). Westeros has a feudal system much like medieval Europe, where families and clans would make alliances, declare war, and most importantly: bend the knee. To demonstrate this in this project, the LEDs used for the different cities house's colors match their color in the show! Red for Lannister, Orange for Dorne, etc. Normal LEDs, likes ones on a christmas tree, are used for these general colors, and more complex colors like teal for The Vale are done with the limited Neopixels I had for the midterm.  

Essos on the other hand is filled with self governing cities. 

### 

## Demonstration

