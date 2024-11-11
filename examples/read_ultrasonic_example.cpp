#include "../include/payload_integration.h"
#include <dji_logger.h>
#include <unistd.h> // For sleep function

int main() {
    DJI::Payload::PayloadIntegration payload;

    if (payload.Initialize() != DJI_ERROR_SYSTEM_MODULE_CODE_SUCCESS) {
        DjiLogger_Error("Failed to initialize the payload.");
        return -1;
    }

    DjiLogger_Info("Payload initialized successfully. Reading ultrasonic data...");

    while (true) {
        // Read data from ultrasonic sensor (pseudo-code, replace with actual read function)
        float distance = readUltrasonicSensor();

        if (distance >= 0) {
            DjiLogger_Info("Ultrasonic sensor distance: %.2f cm", distance);
        } else {
            DjiLogger_Error("Failed to read data from ultrasonic sensor.");
        }

        // Delay to simulate periodic sensor reading
        sleep(1);
    }

    return 0;
}

// Pseudo-function to read distance from ultrasonic sensor
float readUltrasonicSensor() {
    // Replace with actual sensor reading logic, returning distance in cm
    // For example, use GPIO or UART to get distance data from sensor
    return 100.0; // Replace with actual sensor reading in cm
}
