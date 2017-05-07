# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Reflection

### PID Components
**P** accounts for the current cte (Cross Track Error). So the further of the car is of the reference line the stronger
the output value will be. A high coefficient for the P-error will allow the car to react quickly but also cause it to
overshoot and oscillate.

**I** accounts for error values in the past. In this case it is just the sum over all errors. 

**D** accounts for future trends based on the current change rate. A higher coefficient reduces overshooting and
therefore helps the car to stay on the reference line.

### Parameter Tuning
To find working parameters for the P, I and D coefficients a manuel approach was chosen. In the beginning Ki and Kd 
were set to zero. Then Kp was increased until the car oscillated. In the next step Kd was increased until the car was
able to quickly reach it's reference. For Ki, a very small value was chosen since the simulator has basically no steering
bias.

The final values for the coefficients for a speed of 60 mph are:

Kp = 0.15</br>
Ki = 0.0002</br>
Kd = 2.0


Effects of increasing a parameter independently

| Response | Rise Time | Overshoot | Settling Time | S-S Error |
|----------|-----------|-----------|---------------|-----------|
| Kp       | Decrease  | Increase  | NT            | Decrease  |
| Ki       | Decrease  | Increase  | Increase      | Eliminate |
| Kd       | NT        | Decrease  | Decrease      | NT        |

Jinghua Zhong (Spring 2006). "PID Controller Tuning: A Short Tutorial" (PDF). Retrieved 2011-04-04.