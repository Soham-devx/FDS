// Pin definitions
const int sensorPin = A0;
const int ledPin1 = 7; // Top LED (Low threshold)
const int ledPin2 = 6; // Middle LED (Medium threshold)
const int ledPin3 = 5; // Bottom LED (High threshold)

void setup() {
  Serial.begin(9600);
  
  // Set LED pins as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  // Read raw analog value from TMP36
  int sensorVal = analogRead(sensorPin);
  
  // Convert the reading to voltage (for 5V Arduino)
  float voltage = (sensorVal / 1024.0) * 5.0;
  
  // Convert voltage to temperature in Celsius
  // TMP36 has a 500mV offset and 10mV per degree Celsius
  float temperatureC = (voltage - 0.5) * 100.0;
  
  // Print temperature to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" C");

  // Control LEDs based on temperature thresholds
  if (temperatureC < 20.0) {
    // Below 20°C: All LEDs off
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  } 
  else if (temperatureC >= 20.0 && temperatureC < 30.0) {
    // 20°C to 29.9°C: 1 LED on
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
  } 
  else if (temperatureC >= 30.0 && temperatureC < 40.0) {
    // 30°C to 39.9°C: 2 LEDs on
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, LOW);
  } 
  else {
    // 40°C and above: All 3 LEDs on
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin3, HIGH);
  }

  delay(500); // Short delay for stability
}