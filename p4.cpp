int button1 = 7;
int button2 = 12;

int led1 = 5;
int led2 = 6;

void setup()
{
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  
  pinMode(led1,OUTPUT);
  pinMode(led2, OUTPUT);
  
  Serial.begin(9600);
};

void loop()
{
  if(digitalRead(button1) == LOW)
  {
    digitalWrite(led1, HIGH);
    Serial.println("LED 1 is ON.");
  }
  else
  {
  	digitalWrite(led1, LOW);
    Serial.println("LED 1 is OFF.");
  }
                   
  if(digitalRead(button2) == LOW)
  {
    digitalWrite(led2, HIGH);
    Serial.println("LED 2 is ON.");
  }
  else
  {
  	digitalWrite(led2, LOW);
    Serial.println("LED 2 is OFF.");
  }
        
  delay(100);
}