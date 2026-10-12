# Arduino Ultrasonic Distance Alarm
A beginner project using an ultrasonic sensor to measure distance and give a visual auditory output via a buzzer and an led.

## Project Overview
This project demonstrates how an Arduino can read distance measurements from an ultrasonic sensor and use that information to control an LED and a buzzer.

**Project status:** Tinkercad simulation completed; physical hardware testing pending.

## Features

- Measures distance using an HC-SR04 ultrasonic sensor.
- Displays distance readings in the Serial Monitor.
- Activates a red LED and buzzer when an object enters the warning zone.
- Changes the beep interval based on the measured distance.

## Components

| Components |

| Arduino Uno R3 | 1 |
| HC-SR04 ultrasonic sensor | 1 |
| Red LED | 1 |
| 220–330 Ω resistor | 1 |
| Active buzzer | 1 |
| Breadboard | 1 |
| Jumper wires | As required |

## Circuit Connections

| Component pin | Arduino pin |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | Digital pin 9 |
| HC-SR04 ECHO | Digital pin 10 |
| LED anode through a current-limiting resistor | Digital pin 7 |
| LED cathode | GND |
| Buzzer positive | Digital pin 8 |
| Buzzer negative | GND |

## How It Works

The HC-SR04 sends an ultrasonic pulse and measures the time taken for its echo to return. 
It has 2 digital pins trig and echo apart from vcc and gnd. The trig pin goes goes low for 2 microseconds and high for 10, as is mentioned in the code. The echo pin is HIGH until it detects the returning ultrasonic pulse and goes LOW. This time is then used to measure the distance which is given by: 

Distance (cm) = Echo duration × 0.0343 ÷ 2
.0343 is distance of sound in cm/ microseconds.

The Arduino compares the measured distance with a configurable warning threshold, in this case 50cm(line 7 of the code, u can change it as per your liking).
When the object is within the warning zone, the LED turns on and the buzzer beeps.

## Software and Simulation

- Arduino-style C++ sketch
- Tinkercad Circuits

## Testing
The circuit was tested in Tinkercad by changing the simulated target distance and observing the distance readings, LED and buzzer. 
Detailed test measurements will be added after the results are recorded.

## Limitations and Future Improvements

- Verify the circuit on physical hardware.
- Record measurement accuracy at different distances.
- Improve the buzzer pattern and warning levels.
- Add a visual distance indicator or display.
- Explore an ESP32 version in a future project.

## Learning Objectives

By completing this project, beginners can learn about ultrasonic sensing, Arduino digital input and output, conditional logic, timing functions and basic electronics troubleshooting.

---

This project is part of my journey of learning robotics through practical projects and documenting the process for other beginners.

**Feedback and suggestions are welcome.**
