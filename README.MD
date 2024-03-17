# Collision engine

Work in progress...

What is working:
- Engine creates and moves one sphere object

To be implemented:
- User input to control object movement
- More sophisticated objects
- Screen boundaries
- Object collision, gravity
- Different simulations scenarios (i.e. filling bucket with small circles)

## Dependencies
~~~
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install build-essential cmake libsfml-dev
~~~

## Running
~~~
$ git clone https://github.com/aleksander-piprek/Collision-Engine.git
$ mkdir build
$ cd build
$ cmake ..
$ cmake --build .
~~~
