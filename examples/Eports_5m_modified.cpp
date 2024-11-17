
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
    uint8_t sensorData[4];  // Assuming sensor outputs ASCII data for distance
    HAL_UART_Receive(&huart1, sensorData, sizeof(sensorData), HAL_MAX_DELAY);

    // Convert the ASCII data to a float (distance in meters)
    float distance = atof((char *)sensorData) / 100.0;  // Assuming input is in cm, convert to meters
    return distance;
}

// Function to send an alert via UART2
void sendAlert(const char *message) {
    HAL_UART_Transmit(&huart2, (uint8_t *)message, strlen(message), HAL_MAX_DELAY);
}

// Main loop for monitoring distance
void monitorDistance() {
    while (1) {
        float distance = readUltrasonicDistance();
        
        // Check if distance is less than 5 meters
        if (distance < 5.0) {
            char alertMessage[50];
            snprintf(alertMessage, sizeof(alertMessage), "ALERT: Object at %.2f meters\n", distance);
            sendAlert(alertMessage);
        }

        HAL_Delay(100);  // Polling interval (adjust as needed)
    }
}
