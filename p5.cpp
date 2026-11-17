int sensorValue = 0;
int ledValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  sensorValue = analogRead(A0);
  
  ledValue = map(sensorValue, 0, 255, 0, 1023);
  Serial.println(sensorValue);
  
  digitalWrite(0, ledValue);
  
  delay(10);
  
  
}