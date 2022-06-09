// Temperatura
int readValue = 0;
int readValue1 = 0;
int lastValue = 1;
int lastValue1 = 1;
int sensorPin = A4;
int sensorPin1 = A0;
float voltsValue;
float tempValue;
float voltsValue1;
float tempValue1;

void setup()
{
	Serial.begin(9600);
}

void loop()
{	
  	readValue1=analogRead(sensorPin1);
	readValue = analogRead(sensorPin);
	if (lastValue != readValue) {
		Serial.print("readValue: ");
		Serial.print(readValue);
		lastValue = readValue;
		voltsValue = 5.0 / 1024 * readValue;
		Serial.print(" -> Voltaje sensor 1: ");
		Serial.print(voltsValue);
		tempValue = voltsValue * 100 - 50;
		Serial.print(" -> Temperatura sensor 1: ");
		Serial.println(tempValue);
	}
  	if (lastValue1 != readValue1) {
		Serial.print("readValue: ");
		Serial.print(readValue1);
		lastValue1 = readValue1;
		voltsValue1 = 5.0 / 1024 * readValue1;
		Serial.print(" -> Voltaje sensor 2: ");
		Serial.print(voltsValue1);
		tempValue1 = voltsValue1 * 100 - 50;
		Serial.print(" -> Temperatura sensor 2: ");
		Serial.println(tempValue1);
	}
  	
	delay(100);
}