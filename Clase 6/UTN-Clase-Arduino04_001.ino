int Led_Pin = 6;
int Fot_Pin = A0;
int sensorValue = 0;
int outputValue = 0;

void setup()
{
	Serial.begin(9600);
	pinMode(Led_Pin, OUTPUT);
}

void loop()
{
	digitalWrite(Led_Pin, HIGH);
 	sensorValue = analogRead(Fot_Pin);
 	outputValue = map(sensorValue, 0, 1023, 0, 255);
 	analogWrite(Led_Pin, outputValue);
 	Serial.print("Lectura: ");
 	Serial.println(sensorValue);
 	Serial.print("Mapeado: ");
 	Serial.println(outputValue);
 	delay(250);
 	digitalWrite(Led_Pin, LOW);
 	delay(250);
}