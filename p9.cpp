// Pin Definitions based on your Tinkercad circuit
const int trigPin = 12;
const int echoPin = 11;
const int buzzerPin = 7;
const int redLedPin = 2;
const int greenLedPin = 3;

// Variables for distance calculation
long duration;
int distance;

// Distance threshold in centimeters (adjust as needed)
const int thresholdDistance = 50;

void setup() {
  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  // Initialize Serial Monitor for debugging
  Serial.begin(9600);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the sensor by setting trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin (returns sound wave travel time in microseconds)
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in cm
  distance = duration * 0.034 / 2;

  // Print distance to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Control LEDs and Buzzer based on distance
  if (distance > 0 && distance <= thresholdDistance) {
    // Object detected within range
    digitalWrite(redLedPin, HIGH);
    digitalWrite(greenLedPin, LOW);
    tone(buzzerPin, 1000); // Play 1000Hz tone on buzzer
  } else {
    // Area is clear
    digitalWrite(redLedPin, LOW);
    digitalWrite(greenLedPin, HIGH);
    noTone(buzzerPin);     // Turn off buzzer
  }

  delay(100); // Short delay for stability
}