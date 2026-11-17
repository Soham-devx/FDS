const int ldrPin = A0;
const int ledPin = 9;
const int threshold = 500;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightValue = analogRead(ldrPin);
  Serial.println(lightValue);
  // Turn the LED on when the measured light level is low.
  digitalWrite(ledPin, lightValue < threshold ? HIGH : LOW);
  delay(200);
}