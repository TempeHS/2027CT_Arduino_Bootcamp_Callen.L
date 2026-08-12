// Move your helper functions into this tab.
// The Arduino build system automatically joins every .ino file in this folder
// into one program, so functions defined here can be called from the main sketch.

int readDistance() {
  return ultrasonic.read();
}

int classifyZone(int distance, int nearLimit, int farLimit) {
  if (distance < nearLimit) {
    digitalWrite(LED_PIN, HIGH);  // 5 volts on the pin: LED on
    return 0;              // danger

  } else if (distance < farLimit) {
    digitalWrite(LED_PIN, HIGH);  // 5 volts on the pin: LED on
    digitalWrite(LED_PIN, LOW);   // 0 volts: LED off
    return 1;              // warning
  }
    digitalWrite(LED_PIN, LOW);   // 0 volts: LED off
  return 2;                // safe
}
