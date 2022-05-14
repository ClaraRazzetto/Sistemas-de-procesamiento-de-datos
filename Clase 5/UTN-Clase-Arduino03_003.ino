int LedPin = 6;
int PotPin = A0;
int IntPin = 2;
int sensorValue = 0;
int inputValue = 0;
int outputValue = 0;

void setup()
{
	pinMode(LedPin, OUTPUT);
	pinMode(IntPin, INPUT);
  	TestLed();
}

void loop()
{
  inputValue = digitalRead(IntPin); //lectura digital del interruptor
  
  if(inputValue == HIGH)
  {
    for(int fadeValue = 0; fadeValue <= 255; fadeValue +=5)
    {
      analogWrite(LedPin,fadeValue);
      delay(30);
    }
  }else
  {
    sensorValue = analogRead(PotPin);//lectura analógica del potenciador
    outputValue = map(sensorValue,0,1023,0,255);
    analogWrite(LedPin, outputValue);
  }
}

void TestLed()
{
  digitalWrite(LedPin,HIGH);
  delay(500);
  digitalWrite(LedPin,LOW);
  delay(500);
  digitalWrite(LedPin,HIGH);
  delay(500);
  digitalWrite(LedPin,LOW);
  delay(500);
  digitalWrite(LedPin,HIGH);
  delay(500);
  digitalWrite(LedPin,LOW);
}
