# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---
## Reflections
The project aims to control the car through a curved road using PID Controller. The unity simulator provided by Udacity provides:
*	The cross track error (cte : Distance between car and lane center)
*	Speed
*	Steering angle
Data via local websocket.

We can control the car by manually or automatically setting `steer_value` and `throttle` arguments. I have used PID controller to automatically control `steer_value`.

### Describe the effect of the P, I, D component of the PID algorithm.

**P in PID controller stands for Proportional**: This coefficient (K_p) controls the vehicle proportional to the cte. If the car is towards right, it will try to bring the car back to centre so as to reduce cte. When we use only Kp coefficient to control the car oscillates and not able to handle sharp turns, goes out of the lane.

**D coefficient (K_d)** tries to reduce the change in cte (derivative of cte wrt time). This coefficient helps in reducing the oscillations and ensure that the vehicle makes changes smoothly.

**I coefficient (K_I)** controls the total error, it is integrate coefficient, and it sums up all the errors. Its purpose is to ensure that total cte error stays low. This helps us in taking care of any systematic bias present in the system.


### Initialization and Optimization of PID coefficients

The most crucial step in PID controller is choosing the right values of PID coefficients. Initially, I decided to use the **Twiddle method** as described in Udacity Lectures  to tune the car, but the car would go off the road, making the optimization hard. Then, I decided to tune the PID coefficients manually based on [Ziegler–Nichols method]
(https://en.wikipedia.org/wiki/Ziegler%E2%80%93Nichols_method). 

[The Oscillating Car](https://youtu.be/2sDTvcmIvcQ)

Initially I set K_d and K_I zero, and reached a value for K_p s.t. the car oscillates around lane center(you can the see the video above), the rough period of oscillations was ~ 5 seconds.  Resulting K_I ~ 2.8,  once the two parameters were set I twiddled around with the value of K_d, initially starting with 0.105, it was observed that when it is high the car kept large oscillations and was almost moving in circle. So I reduced it by a factor of 10, achieving sufficient good results for 
K_p = 0.14, K_d = 0.000105, K_I = 2.8

[Final Parameters](https://youtu.be/vHmVpY6e2Og)

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## How to write a README
A well written README file can enhance your project and portfolio.  Develop your abilities to create professional README files by completing [this free course](https://www.udacity.com/course/writing-readmes--ud777).

