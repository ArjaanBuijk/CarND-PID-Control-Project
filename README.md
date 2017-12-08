# PID Control Project

[![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

---

The goals / steps of this project are the following:

* Implement a Proportional Differential Integral (PID) controller in C++, for steering angle and throttle.
* Test implementation by driving a car simulator around a track.

---

## 1. Files

My project includes the following files:

- [<b>C++</b> - The source code](https://github.com/ArjaanBuijk/CarND-PID-Control-Project/tree/master/src)
- [<b>writeup_report.md</b> - A summary of the project](https://github.com/ArjaanBuijk/CarND-PID-Control-Project/blob/master/writeup_report.md)
- [<b>video_P.gif</b> - Animated gif showing the car driving on the track using a P controller](https://github.com/ArjaanBuijk/CarND-PID-Control-Project/blob/master/Videos/video_P.gif)
- [<b>video_PD.gif</b> - Animated gif showing the car driving on the track using a PD controller](https://github.com/ArjaanBuijk/CarND-PID-Control-Project/blob/master/Videos/video_PD.gif)
- [<b>video_PID.gif</b> - Animated gif showing the car driving on the track using a PID controller](https://github.com/ArjaanBuijk/CarND-PID-Control-Project/blob/master/Videos/video_PID.gif)
    ![track1](https://github.com/ArjaanBuijk/CarND-PID-Control-Project/blob/master/Videos/video_PID.gif?raw=true)



---
## 2. Implementation of PI controller for throttle

I implemented a simple PI controller for the throttle, to keep the speed close to a target speed.

The target speed I used is 25.

The controller was simply copied from the Term 1, Project 3.


## 3. Implementation of P controller for the steering angle

First, I implemented a P controller only. As expected, the car oscillates. It is possible to complete the track at low speeds, but at higher speeds, the oscilations grows and the car drives off the track. This video shows the behavior:
![track1](https://github.com/ArjaanBuijk/CarND-PID-Control-Project/blob/master/Videos/video_P.gif?raw=true)


## 4. Implementation of PD controller for the steering angle

To avoid the overshoot and oscillations, I added the D controller part. This part of the controller 'counter steers' and avoids the overshoot or at least minimizes it.

I ran many cases, tweaking the parameters Kp and Kd, representing the Proposional and Differential coefficients respectively. I used a 'Twiddle' approach in a manual manner. I increased or decreased each parameter a little bit, and based on the outcome, I increased or decreased them more. As the results got better or worse, I decreased the amount of change applied to the parameters, until the car drove nicely around the track.

![track1](https://github.com/ArjaanBuijk/CarND-PID-Control-Project/blob/master/Videos/video_PD.gif?raw=true)


# 5. Implementation of PID controller for the steering angle

Finally, I checked if there is a bias in the steering angle. I ran the simulator without giving any feedback on the steering angle, and it showed that the steering angle is not zero. The value was quite small, but not zero. This indicates that there is a small bias in the system.

To deal with this, I added the Integral part of controller, and again ran some trials to check the influence. The influence was small.

The values chosen were:

|Coefficient| Value|
|-|-|
|Kp| 0.2 |
|Ki| 0.0004|
|Kd|1.0|

A video of the end result is shown at the beginning of this document.


# 6. Summary

The result can be summarized as follows:

- at low speeds (~10) a P controller can drive the car around the track, but it weaves a lot.
- at medium speeds (~25) a PID controller can drive the car around the track very nicely with minimum weaving.
- at high speeds (50+) I was not able to keep the car on the road with just the PID controller. Perhaps there are improvements possible in the parameters, but I believe that because the PID controller only reacts to the error, there is simply a limit on how fast a car it can control. It needs to be combined with other observations from Lidar, Radar and Video.


---

# Dependencies

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
