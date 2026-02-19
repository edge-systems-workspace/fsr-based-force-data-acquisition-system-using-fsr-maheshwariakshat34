/**
 * @file main.ino
 * @brief Read FSR sensor values and print them to the Serial console.
 *
 * This lightweight Arduino sketch reads an analog value from a force-sensitive
 * resistor (FSR) attached to an analog input pin and prints the reading every
 * 500 ms. Designed for quick diagnostics and logging of raw ADC values.
 *
 * @author Akshat Lakhotiya
 * @version 1.0
 * @date 2026-02-19
 */

#include <Arduino.h>

/**
 * @def FSR_PIN
 * @brief Analog input pin connected to the FSR sensor.
 *
 * Use an available analog pin on the target board (for example `A0` on many
 * Arduino boards). Change this macro if the sensor is connected to a different
 * analog input.
 */
#define FSR_PIN A0

/**
 * @brief Holds the most recent analog reading from the FSR sensor.
 *
 * The numeric range depends on the board ADC resolution (commonly 0..1023 for
 * a 10-bit ADC). This variable is updated inside `loop()` and printed to
 * Serial for monitoring.
 */
static int value = 0;

/**
 * @brief Initialize serial communication and configure the FSR pin.
 *
 * - Starts Serial at 9600 baud for logging.
 * - Configures the FSR pin as an input (harmless for analog pins but explicit
 *   for clarity).
 *
 * @note Call once during device startup.
 * @return void
 */
void setup() {
    Serial.begin(9600);
    pinMode(FSR_PIN, INPUT);
}

/**
 * @brief Main application loop: read FSR and print the value.
 *
 * The loop performs the following steps:
 * 1. Read the analog value from the FSR attached to `FSR_PIN`.
 * 2. Print the value to the Serial console followed by a newline.
 * 3. Wait 500 ms before taking the next reading.
 *
 * @note Adjust the sampling delay or baud rate to suit your application.
 * @return void
 */
void loop() {
    value = analogRead(FSR_PIN);
    Serial.println(value);
    delay(500);
}
