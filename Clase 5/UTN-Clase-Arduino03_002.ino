int Led_Pin = 6;
int Pot_Pin = A0;
int Int_Pin = 2;
int sensorValue = 0;
int inputValue = 0;

void setup()
{
	pinMode(Led_Pin, OUTPUT);
	pinMode(Int_Pin, INPUT);
}

void loop()
{
  inputValue = digitalRead(Int_Pin); //lectura digital del interruptor
  
  if(inputValue == HIGH)
  {
    digitalWrite(Led_Pin,1);
  }else
  {
    sensorValue = analogRead(Pot_Pin);//lectura analógica del potenciador
    
      if(sensorValue<800)
    {
      digitalWrite(Led_Pin,1);
    }else
    {
       digitalWrite(Led_Pin,0);
    }
  }
}