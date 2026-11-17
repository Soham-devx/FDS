// Pin definitions based on your circuit wiring
const int gasSensorPin = A0;  // Gas sensor connected to Analog Pin A5
const int buzzerPin = 12;      // Buzzer (+) connected to Digital Pin 7

// Threshold value for triggering the alarm (adjust as needed)
int gasThreshold = 400;       

void setup() {
  pinMode(gasSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);         // Start Serial Monitor to view sensor readings
}

void loop() {
  // Read the analog value from the gas sensor (0 to 1023)
  int sensorValue = analogRead(gasSensorPin);
  
  // Print the reading to the Serial Monitor for debugging
  Serial.print("Gas Sensor Value: ");
  Serial.println(sensorValue);

  // Check if gas concentration exceeds the threshold
  if (sensorValue > gasThreshold) {
    tone(buzzerPin, 1000);    // Sound the buzzer at 1000 Hz
  } else {
    noTone(buzzerPin);        // Turn off the buzzer
  }

  delay(200);                 // Short delay for stability
}