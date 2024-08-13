const int soundSensorPin = 34; // GPIO pin for sound sensor digital output
const int ledPin = 27;         // GPIO pin for LED

void setup() {
  Serial.begin(115200);
  
  pinMode(soundSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  Serial.println("Sound Sensor Test");
}

void loop() {
  int soundValue = digitalRead(soundSensorPin);

  if (soundValue == HIGH) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("Clap detected, LED turned on");
    delay(1000); // Delay to debounce the sensor and avoid multiple triggers
    digitalWrite(ledPin, LOW);  // Turn off the LED after a short delay
    delay(1000);
  } else {
    digitalWrite(ledPin, LOW); // Ensure LED is off if no sound detected
  }
}
