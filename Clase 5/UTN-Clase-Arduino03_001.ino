int LedPin1 = 3;
int PotPin = A0;
int sensorValue = 0;
int outputValue1 = 0;


//configuro pines de entrada y salida
void setup()
{
  pinMode(LedPin1, OUTPUT);
  TestLed();
}

void loop()
{
  sensorValue = analogRead(PotPin); //Leo valores analogicos
  outputValue1 = map(sensorValue, 0, 1023, 0, 254); 
  analogWrite(LedPin1, outputValue1);
}
      	
void TestLed()
{
  digitalWrite(LedPin1, HIGH);//prender led puerto 6
  delay(500);//esperar medio seg
  digitalWrite(LedPin1,LOW);//apagar led puerto 6
  delay(500);//esperar medio seg
  digitalWrite(LedPin1, HIGH); //prender led puerto 6
  delay(500); //esperar
  digitalWrite(LedPin1, LOW); //apagar led puerto 6
}