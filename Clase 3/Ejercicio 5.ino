//estado del botón
int buttonState = 0;

//configuro pines de entrada y salida
void setup()
{
	pinMode(2, INPUT);
	pinMode(5, OUTPUT);
	pinMode(12, OUTPUT);
}

void loop()
{
	//Leo el estado del puerto de entrada 2
	buttonState = digitalRead(2);

  	//según estado 
	if (buttonState == HIGH)
    {
      	
		digitalWrite(5, HIGH);//prender led rojo
      	delay(500);//esperar medio seg
      	digitalWrite(5,LOW);//apagar led rojo
      	delay(500);//esperar medio seg
		digitalWrite(5, HIGH); //prender led rojo
		delay(500); //esperar
      	digitalWrite(5, LOW); //apagar led rojo
      	digitalWrite(12, HIGH);//prender led amarillo
		delay(500);//esperar
		digitalWrite(12, LOW); //apagar led amarillo
      	delay(500); //esperar
      	digitalWrite(12, HIGH); //prender led amarillo
		delay(500);//esperar
      	digitalWrite(12, LOW);//apagar led amarilloo
    }else 
    {
      //apagar ambos leds
		digitalWrite(5, LOW);
		digitalWrite(12, LOW);
	}
}