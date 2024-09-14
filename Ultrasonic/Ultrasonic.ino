#include <NewPing.h>

// Define the pins for the Ultrasonic Sensor
#define TRIG_PIN 5
#define ECHO_PIN 5

// Maximum distance we want to measure (in centimeters)
#define MAX_DISTANCE 100

// Create a NewPing object to interface with the sensor
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
}

void loop() {
  // Measure distance using the ultrasonic sensor
  unsigned int distance = sonar.ping_cm();

  // Print the measured distance
  if (distance == 0) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  // Wait a little before taking the next measurement
  delay(1000);
}
