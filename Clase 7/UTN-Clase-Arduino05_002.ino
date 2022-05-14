	int Led_Pin = 13;
	int Buz_Pin = 6;
	int Int_Pin = 2;
	int inputValue = 0;

void setup()
{
	pinMode(Led_Pin, OUTPUT);
	pinMode(Buz_Pin, OUTPUT);
	pinMode(Int_Pin, INPUT);
	delay(250);
	digitalWrite(Led_Pin, 1);
	tone(Buz_Pin, 900, 250);
	delay(500);
	digitalWrite(Led_Pin, 0);	
	tone(Buz_Pin, 900, 250);
	delay(500);
	digitalWrite(Led_Pin, 1);
	tone(Buz_Pin, 900, 250);
	delay(800);
	digitalWrite(Led_Pin, 0);
}

void loop()
{
	inputValue = digitalRead(Int_Pin);
	
  	if (inputValue == HIGH)
	{
		tone(Buz_Pin, 200, 1014);
		delay(1000);
		tone(Buz_Pin, 200, 1275);
		delay(1000);
	}
	else
	{
		noTone(Buz_Pin);
	}
	
  	delay(1000);
	digitalWrite(Led_Pin, 1);
	delay(250);
	digitalWrite(Led_Pin, 0);
}