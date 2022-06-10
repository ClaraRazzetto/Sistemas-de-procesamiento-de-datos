int sensorPin = A1;

// Variables de Luz
int Led_Pin = 3;
int Fot_Pin = A0;
int Int_Pin = 2;
int sensorValue = 0;
int inputValue = 0;

// Variables de Temperatura
int readValue = 0;
int lastValue = 1;
int tempPin = A1;
float voltsValue;
float tempValue;

int counter = 0;
int start = 0;
int stop = 0;

// Limites Invierno
int start1 = 18;
int stop1 = 24;

// Limites Verano
int start2 = 20;
int stop2 = 1;

void setup()
{
  Serial.begin(9600);
  pinMode(Led_Pin, OUTPUT);
  pinMode(Int_Pin, INPUT);
}

void loop()
{
  // Lectura Digital
  inputValue = digitalRead(Int_Pin);
  if (inputValue == HIGH)
  {
    Serial.println("Luminaria: Encendido");
	digitalWrite(Led_Pin, 1);
  }
  else
  {
    // Lectura Temperatura
    readValue = analogRead(tempPin);
    lastValue = readValue;
    voltsValue = 5.0 / 1024 * readValue;
    tempValue = voltsValue * 100 - 50;
    Serial.println("Temperatura: ");
	Serial.println(tempValue);
    Serial.println("Voltaje: ");
	Serial.println(voltsValue);
    if( tempValue < 20 ){
      start = start1;
      stop = stop1;
    }
    else
    {
      start = start2;
      stop = stop2;
    }  
    // Lectura Luz
	if(counter >= start){
      // Lectura Analoga
      sensorValue = analogRead(Fot_Pin);
	  if(sensorValue < 500){
        Serial.println("Luminaria: Encendido");
		digitalWrite(Led_Pin, 1);
      } else {
        Serial.println("Luminaria: Apagado");
      	digitalWrite(Led_Pin, 0);
      }
    }
    else
    {
      Serial.println("Luminaria: Apagado");
      digitalWrite(Led_Pin, 0);
    }
  }
  counter++;
  Serial.print("Hora: ");
  Serial.println(counter);
  if (counter == 24)
  {
    counter =0;
  }
  delay(1000);
}