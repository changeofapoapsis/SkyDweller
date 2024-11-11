# Configuration Guide

This guide explains how to configure the DJI Payload SDK and set up the payload integration.

## 1. Register with DJI Developer Portal

Sign up and create a new project in the [DJI Developer Portal](https://developer.dji.com/). You will receive an App Key, which is required for PSDK integration.

## 2. Configure PSDK Settings

1. Open the main configuration file (usually located in the `psdk` folder of your DJI PSDK installation).
2. Add your App Key to enable the SDK.
3. Customize payload parameters if necessary, such as `payload type` and `communication settings`.

## 3. Test Configuration

Once the PSDK and payload configurations are complete:
1. Run a test using example code:
   ```bash
   ./your-payload-example

Confirm the payload is detected in the DJI Pilot app or other monitoring interface.


---

#### File: `docs/USAGE.md`

```markdown
# Usage Guide

This guide provides instructions for running and controlling the custom payload using the sample code.

## Running the Payload

1. **Activate the Payload**:
   Use the provided example code to activate the payload:
   ```bash
   ./build/your-payload-example

Control and Monitor Payload: You can monitor and control the payload via DJI Pilot or using the logging outputs from the example code.

Sending Data: Modify the SendData function in payload_integration.cpp to send custom data to the drone.

Receiving Data: Use the ReceiveData function to handle data from the drone.

Ensure the drone is powered on and that the payload is properly connected and recognized.

Check DJI Pilot or any other interface to view real-time data.


