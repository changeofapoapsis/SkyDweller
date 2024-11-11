#include "../include/payload_integration.h"
#include <dji_logger.h>
#include <unistd.h> // For sleep function

int main() {
    DJI::Payload::PayloadIntegration payload;

    if (payload.Initialize() != DJI_ERROR_SYSTEM_MODULE_CODE_SUCCESS) {
        DjiLogger_Error("Failed to initialize the payload.");
        return -1;
    }

    if (payload.Activate() != DJI_ERROR_SYSTEM_MODULE_CODE_SUCCESS) {
        DjiLogger_Error("Failed to activate the payload.");
        return -1;
    }

    DjiLogger_Info("Payload activated. Sending ultrasonic data...");

    while (true) {
        // Read data from ultrasonic sensor (pseudo-code)
        float distance = readUltrasonicSensor();

        if (distance >= 0) {
            uint8_t dataBuffer[4];
            memcpy(dataBuffer, &distance, sizeof(float));

            // Send data to the drone
            if (payload.SendData(dataBuffer, sizeof(dataBuffer)) == DJI_ERROR_SYSTEM_MODULE_CODE_SUCCESS) {
                DjiLogger_Info("Sent ultrasonic distance: %.2f cm", distance);
            } else {
                DjiLogger_Error("Failed to send ultrasonic data.");
            }
        } else {
            DjiLogger_Error("Failed to read data from ultrasonic sensor.");
        }

        // Delay to simulate periodic data sending
        sleep(1);
    }

    return 0;
}

// Pseudo-function to read distance from ultrasonic sensor
float readUltrasonicSensor() {
    // Replace with actual sensor reading logic, returning distance in cm
    return 75.0; // Replace with actual sensor reading in cm
}
