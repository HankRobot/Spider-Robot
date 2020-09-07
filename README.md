# Spider-Robot
A spider-similar locomotion robot with video feed to scare my lecturers

<div align="center">
<img src="https://media.giphy.com/media/fU43JVDDEdu4ARzo8f/giphy.gif">
</div>

# Project Description
1. Using a few codes from Matthew Hallberg's streaming code (https://youtu.be/4X_EjUZp2c0), the smartphone is attached on a 6 legged spider robot to stream videos to a desktop app, desktop app in turns gives commands to ESP8266 device, in turn which the device does a 2^4 combination of led pinouts to control the CT-Uno G15 shield spider-robot.
2. The robot also has image target to track objects using vuforia with the smartphone.

# Folder AR-Robot
- [x] Unity project for streaming smartphone app and desktop app 
- [x] Unity project for image tracking

# Folder ControlSpider
- [x] CT-UNO powered G15 shield to control spider robot

# Folder SpiderArduino
- [x] ESP8266 device to receive commands from desktop app via UDP

# Improvements
- [x] Matthew Hallberg's code always crashes on my android phone due to object buildup, hence GC is implemented to avoid crashing.
