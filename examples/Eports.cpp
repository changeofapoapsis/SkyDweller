#include "stm32f4xx_hal.h"
#include <string.h>
#include <stdio.h>

// UART handles
UART_HandleTypeDef huart1; // For ultrasonic sensor (UART1)
UART_HandleTypeDef huart2; // For E-Port communication (UART2)

// Function to initialize UART communication
void UART_Init() {
    // Initialize UART1 for sensor data
    huart1.Instance = USART1;
    huart1.Init.BaudRate = 9600;
    huart1.Init.WordLength = UART_WORDLENGTH_8B;
    huart1.Init.StopBits = UART_STOPBITS_1;
    huart1.Init.Parity = UART_PARITY_NONE;
    huart1.Init.Mode = UART_MODE_TX_RX;
    HAL_UART_Init(&huart1);

    // Initialize UART2 for E-Port data transfer
    huart2.Instance = USART2;
    huart2.Init.BaudRate = 9600;
    huart2.Init.WordLength = UART_WORDLENGTH_8B;
    huart2.Init.StopBits = UART_STOPBITS_1;
    huart2.Init.Parity = UART_PARITY_NONE;
    huart2.Init.Mode = UART_MODE_TX_RX;
    HAL_UART_Init(&huart2);
}

// Function to read distance from the ultrasonic sensor
float readUltrasonicDistance() {
    uint8_t sensorData[4];
    float distanceCm = 0.0;

    // Read 4 bytes from the sensor over UART
    if (HAL_UART_Receive(&huart1, sensorData, 4, 100) == HAL_OK) {
        int distanceInches = (sensorData[0] << 8) | sensorData[1];  // Convert to integer
        distanceCm = distanceInches * 2.54;  // Convert to cm
    }

    return distanceCm;
}

// Main function to send distance data to E-Port
int main(void) {
    HAL_Init();
    UART_Init();
    float distance;

    while (1) {
        distance = readUltrasonicDistance();

        if (distance > 0) {
            char buffer[32];
            snprintf(buffer, sizeof(buffer), "Distance: %.2f cm\n", distance);
            HAL_UART_Transmit(&huart2, (uint8_t *)buffer, strlen(buffer), 100);
        }

        HAL_Delay(500);
    }
}


//The STM32 will read data from the MB1240 sensor using UART and then transmit this data in a format compatible with the DJI E-Port.

//Once the STM32 transmits the distance data to the E-Port, you can read it using the DJI PSDK’s data receive functions. Here’s a simplified PSDK C++.

#include <dji_logger.h>
#include <dji_vehicle.h>

// Callback function to process received data
void ReceiveDistanceDataCallback(const uint8_t* data, uint16_t length) {
    if (length > 0) {
        float distanceCm;
        memcpy(&distanceCm, data, sizeof(float));

        DjiLogger_Info("Received distance from ultrasonic sensor: %.2f cm", distanceCm);
    }
}

int main() {
    // Initialize DJI vehicle
    DJI::OSDK::Vehicle vehicle;

    // Set up data reception
    vehicle->advancedSensing->setUserDataSubscriptionCallback(ReceiveDistanceDataCallback);

    while (vehicle.isActivated()) {
        // Data is processed in callback
        DjiLogger_Info("Listening for distance data...");
        sleep(1);
    }

    return 0;
}
