# Collision engine

Work in progress...

What is working:
- Engine creates and moves one sphere object

To be implemented:
- Applying boundaries
- Object collision, gravity
- Drawing vectors of velocity and acceleration
- User input to control object movement
- More sophisticated objects
- Different simulations scenarios: 
⋅⋅⋅filling bucket with small spheres⋅⋅
⋅⋅⋅elastic collisions simulations⋅⋅
- Simple GUI for handling different simulations
 
## Dependencies installation
~~~
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install build-essential cmake libsfml-dev
~~~

## Building
~~~
$ git clone https://github.com/aleksander-piprek/Collision-Engine.git
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
~~~
