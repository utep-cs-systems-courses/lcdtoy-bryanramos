## Project 3

# Introduction

The purpose of this lab was to understand how to draw a variety of shapes
and strings on the screen of the Launchpad board using for loops and such
as well as make the screen work in unison with the buttons, lights, etc.
similar to what was completed for lab 2.

# How to Use

* Make sure the MSP430 is connected to the system via USB.
* From the project folder, navigate to the /src folder.
* When inside the src folder, run "make load", press enter.
* The file will be loaded onto the MPS430 if connected property. Play away!

# Functions of project 3

* When the program is loaded onto the MSP430, the default menu is displayed
with options for the user.
* If S1 is pressed, a song plays, and a description of Mario is displayed along
with a red background and a white square.
* If S2 is pressed, a song plays, and a descripton of Luigi is displayed along
with a green background and white rectangle with a green diamond inside, the 
diamond inside square/rectangle shape.
* If S3 is pressed, a song plays, and a description of Princess Peach is displayed
along with a pink background and a white triangle.
* if S4 is pressed, a song plays, and a description of Bowser along with a purple
background and white trapezoid is shown.

Because of time constraints I could not finish fixing a bug where S2 must be pressed
first for the rest of the menu to work properly when displaying images on screen.
In addition, I would have like to have implemented a return to showing the menu I created
at the beginning, but again, ran out of time!
