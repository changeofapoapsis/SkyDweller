# SkyDweller
DJI Payload SDK (PSDK) Custom Payload Integration

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


