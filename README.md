# FDF

<img width="100%" src="https://user-images.githubusercontent.com/24794294/37569578-b9bcb63e-2ae4-11e8-84e3-eaaeeaab6ba0.png"/>

## Pitch

FDF is a pedagogical project from 42 School which aims to introduce the students to computer graphics.  
With a minimalist in-house graphic library that only allows to open a window, get the pixels buffer for each frame and handle keyboard/mouse inputs, the goal is to produce on screen a 3D representation of a map in the form of x-y-z coordinates in a text file.  
The result is a very basic graphic engine that runs on the CPU, written in C.


## Main features

- Plane-like first person camera to fly around the map, controllable with a game controller or a keyboard.
- Maps (larger than 400x400 vertices) are virtually infinite, being duplicated on every side.
- Audio files can be read by the program and affect the look of the map in different ways, depending on amplitudes of given frequencies.
- Stars

![](https://thumbs.gfycat.com/FlusteredVastDeer-size_restricted.gif)

## Things I have learned

- Better understanding of the C programming language and how to structure the code to keep a growing program maintanable, and open to new features.
- Vectors and matrices related algebra, to be able to create the pipeline which transforms textual coordinates into a human-readable landscape on the screen. Bresenham's algorithm is applied to draw lines, resulting in a wireframe look.
- How to handle sound with FMOD, and how to smooth up the raw data from the FFT to obtain fluid effects.
- Handle input from a game controller with SDL2 and map analog joysticks to rotations and movement.
