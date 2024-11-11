# SkyDweller

DJI Payload SDK (PSDK) Custom Payload Integration

**Please note the following cannot be integrated into a platform using the provide repository this is sample code for custom payload integration**

For integrating an ultrasonic sensor with a DJI payload using the DJI PSDK, you’ll want a sensor that provides flexible connectivity options, reliable data output, and ease of interfacing with microcontrollers or embedded systems. Here are some commonly used ultrasonic sensor platforms that work well for this type of integration, especially if they support UART, I2C, or PWM (Pulse Width Modulation) for straightforward data transfer.

Recommended Ultrasonic Sensor Platforms

MaxBotix Ultrasonic Sensors (e.g., MB1240 XL-MaxSonar-EZ4)
Interface Options: UART, PWM, and Analog output.
Range: 20 cm to 765 cm (varies by model).
Resolution: High resolution with easy integration options.
Features: MaxBotix sensors are highly reliable, offer accurate readings, and are known for noise suppression and long-range capabilities. They provide multiple output formats, which can be useful depending on your integration setup.
Integration Suitability: MaxBotix sensors with UART output are ideal, as the DJI PSDK can read UART data with minimal latency. If PWM or analog output is preferred, a microcontroller can be used to convert readings to UART before sending data to the payload.


Garmin LIDAR-Lite v3
Interface Options: I2C and PWM.
Range: 5 cm to 40 m.
Resolution: Up to 1 cm.
Features: Although marketed as LIDAR, Garmin’s LIDAR-Lite v3 has similar functionalities to ultrasonic sensors and works well for obstacle detection with high accuracy and range. Its I2C interface allows easy data readouts and straightforward integration with embedded systems.
Integration Suitability: I2C data can be processed via a microcontroller that reads the distance data and sends it over UART to the DJI payload. This setup provides high accuracy for longer-range measurements.


HC-SR04 (Budget Option)
Interface Options: Trigger and Echo pins (typically requires microcontroller processing).
Range: 2 cm to 400 cm.
Resolution: Approximate.
Features: The HC-SR04 is a low-cost option and widely available. It provides reliable performance for short to medium distances but requires a microcontroller to read the Trigger and Echo signals and convert the data for transmission to the payload.
Integration Suitability: The HC-SR04 can be a good budget choice, but it requires a microcontroller to handle the timing for Trigger/Echo signals and convert the output to UART for the DJI payload integration.
TE Connectivity (Measurement Specialties) TS601-200 Ultrasonic Sensor
Interface Options: UART and analog.
Range: 30 cm to 500 cm.
Resolution: High precision for reliable measurements.
Features: Known for accuracy and industrial-grade robustness, TE Connectivity’s ultrasonic sensors are effective for outdoor and variable environmental conditions. This sensor is also water-resistant, making it suitable for drones that may encounter wet environments.
Integration Suitability: The TS601-200 works well for DJI integration due to its UART interface and rugged design, which offers durability in varying operational conditions.


DYP-A02YY Ultrasonic Distance Sensor
Interface Options: UART and PWM.
Range: 3 cm to 4.5 m.
Resolution: Up to 1 mm.
Features: This sensor has good accuracy and a compact design, making it suitable for integration on smaller payloads. Its UART output is easily readable by microcontrollers and embedded systems.
Integration Suitability: The DYP-A02YY’s UART interface is well-suited for direct data transmission to the DJI payload, and its small form factor makes it ideal for lightweight or space-constrained payloads.


**Integration Considerations**
When selecting an ultrasonic sensor for DJI payload integration, consider the following factors:

Interface Compatibility: Choose sensors with UART output for the simplest integration with DJI payloads. I2C can work but may require a microcontroller to handle data conversion.
Range and Accuracy: Select a sensor with a range and accuracy that meets the application requirements (e.g., obstacle avoidance vs. precise landing).
Environmental Tolerance: Industrial-grade sensors are recommended for outdoor or rough conditions, as they tend to be water-resistant and more durable.
Microcontroller Requirements: For sensors without UART output, a microcontroller such as an Arduino or STM32 can be used to process data and communicate with the DJI payload.


Welcome to the DJI Payload SDK (PSDK) Custom Payload Integration repository! This repository provides a guide, 
sample code, and tools to help developers create and control custom payloads on DJI drones using the DJI Payload Software Development Kit (PSDK).

**Table of Contents**

**Features**

Custom Payload Integration: Control and monitor custom hardware attached to DJI drones.
Event Handling: Implement event-driven responses for payload activation, deactivation, and data communication.
Cross-Platform Compatibility: Supports DJI drones with PSDK compatibility, such as the Matrice series.
Sample Code: Example scripts to demonstrate payload initialization, data communication, and basic controls.
Documentation: In-depth guide and comments in code to assist developers in customizing the payload.

Requirements

DJI Payload SDK (PSDK)
DJI drone compatible with the PSDK, such as the DJI Matrice series
Computer with DJI PSDK libraries installed
Basic knowledge of C++ and hardware integration

1. Setting Up the Development Environment
Install DJI PSDK: Download and install the DJI Payload SDK from the DJI Developer Site.
Clone the Repository:

-----------------------------------------------------------------------

git clone https://github.com/your-username/dji-psdk-integration.git
cd dji-psdk-integration

-----------------------------------------------------------------------

Install Dependencies: Follow the DJI PSDK documentation to install the necessary dependencies for your development environment.

2. Hardware Connections
Connect your custom payload hardware to the DJI drone using the appropriate interfaces (e.g., UART, CAN bus). Ensure that the payload meets DJI's specifications for power and connectivity.

**3. Running Example Code**
Build the example payload code:

-----------------------------------------------------------------------

mkdir build && cd build
cmake ..
make

-----------------------------------------------------------------------

Connect the payload to your DJI drone and start the drone.


Check the drone’s remote controller or software interface to confirm that the payload is recognized and operational.

├── examples            # Sample code for custom payload integration
├── docs                # Documentation for setting up and configuring the payload
├── src                 # Source code for custom payload logic
├── **include**         # Header files and PSDK library interfaces
└── README.md           # Project README file

**Contributing**

We welcome contributions to improve this project! If you'd like to contribute, please follow these steps:

Fork the repository.
Create a new branch for your feature or bug fix.
Commit your changes.
Submit a pull request describing your changes

**License**

This project is licensed under the MIT License. See the LICENSE file for more details.
For more information on using the DJI Payload SDK, visit the official DJI Developer Documentation.


