// Move your helper functions into this tab.
// The Arduino build system automatically joins every .ino file in this folder
// into one program, so functions defined here can be called from the main sketch.

void readSensor() {
  temperature = Environment.readTemperature();
  humidity = Environment.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
}


void updateDisplay() {
  Oled.setFont(u8x8_font_chroma48medium8_r);

  Oled.clearDisplay();

  Oled.setCursor(0, 0);
  Oled.print("Temperature:");

  Oled.setCursor(0, 1);
  Oled.print(temperature);
  Oled.print(" C");

  Oled.setCursor(0, 3);
  Oled.print("Humidity:");

  Oled.setCursor(0, 4);
  Oled.print(humidity);
  Oled.print(" %");

  Oled.refreshDisplay();
}


void checkAlert() {
  const float TEMP_LIMIT = 30.0;

  Oled.setCursor(0, 6);

  if (temperature >= TEMP_LIMIT) {
    Oled.print("!!! REALLY HOT"); // gotta add that 3 !!!.
  } else {
    Oled.print("Temperature OK"); // inspired by dyson's machine
  }

  Oled.refreshDisplay();
}
