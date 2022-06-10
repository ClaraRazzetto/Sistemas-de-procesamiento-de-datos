#include <IRremote.h>
int RECV_PIN = 14;
int IRData = 0;
int Led_Pin = 7;
int Led_Status = 0;
int Led_Pin1 = 13;
int Led_Status1 = 0;
int Rel_Pin = 2;
int Rel_Status = 0;
bool test_mode = true;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
	Serial.begin(9600);	
	pinMode(Led_Pin, OUTPUT);
	irrecv.enableIRIn();
}

void loop()
{
	if (irrecv.decode(&results))
	{
		// Mostrar Lectura
		IRData = results.value;
		irrecv.resume();
		// Ver Valores
		if (test_mode == true)
		{
			Serial.print("Datos: ");
			Serial.print(IRData, HEX);
			Serial.print(" {");
			Serial.print(IRData);
			Serial.println("}");
		}
		switch (IRData)
		{
		case 2295:
          	Serial.println("Boton 1");
			if (Led_Status == 0)
			{
				Serial.println("Led Encendido");
				digitalWrite(Led_Pin, 1);
  				Led_Status = 1;
			}
			else
			{
				Serial.println("Led Apagado");
				digitalWrite(Led_Pin, 0);
				Led_Status = 0;
			}
			break;
		case -30601:
          	Serial.println("Boton 2");
			if (Rel_Status == 0)
			{
				Serial.println("Motor encendido");
				digitalWrite(Rel_Pin, 1);
				Rel_Status = 1;
			}
			else
			{
				Serial.println("Motor Apagado");
				digitalWrite(Rel_Pin, 0);
				Rel_Status = 0;
			}
			break;
		case 18615:
			Serial.println("Boton 3");
			break;
        case 12495:
          	Serial.println("Boton 0");
          	if (Led_Status1 == 0)
			{
				Serial.println("Led Encendido");
				digitalWrite(Led_Pin1, 1);
  				Led_Status1 = 1;
			}
			else
			{
				Serial.println("Led Apagado");
				digitalWrite(Led_Pin1, 0);
				Led_Status1 = 0;
			}
          	break;
		default:
			Serial.println("Boton No Permitido"); 
		}
	}
}
