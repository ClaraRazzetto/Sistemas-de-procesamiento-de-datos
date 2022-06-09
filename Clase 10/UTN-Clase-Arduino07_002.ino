#include <IRremote.h>

int RecvPin = 14;
int IRData = 0;
int LedPin = 13;
int LedStatus = 0;
int LedPin1 = 7;
int LedStatus1 = 0;

//creo un objeto para el receptor(sensor) especificando el pin
IRrecv irrecv (RecvPin);
//Variable results se guardan los datos recibidos por sensor
decode_results results;

void setup()
{
  pinMode(LedPin,OUTPUT);
  Serial.begin(9600);
  //Comienzo la recepcion por IR
  irrecv.enableIRIn(); 
}

void loop()
{
 //Si recibo un dato por sensor (aprieto un botón del control)
 if(irrecv.decode(&results))
 {
  //Guardo el valor en la variable IRData
  IRData= results.value;
  //Inicia una nueva recepción
  irrecv.resume();
  //Muestro el dato recibido en su valor Hexadecimal
  Serial.print("Datos: ");
  Serial.print(IRData, HEX);
  Serial.print(" {");
  //Dato en decimal
  Serial.print(IRData);
  Serial.print("} ");
   
  //Controlar el LED
   //al apretar el botón de 1 se enciende el LED
   //Se apagará si lo aprieto nuevamente 
  if(IRData == 2295)
  {
   if(LedStatus == 0)
   {
    digitalWrite(LedPin,1);
    LedStatus = 1;
   }
   else
   {
    digitalWrite(LedPin,0);
    LedStatus = 0;
   }
  }
    
  //Si presiono la tecla 0 se prende y apaga el LED amarillo
  if(IRData == 12495)
  {
   if(LedStatus1 == 0)
   {
    digitalWrite(LedPin1,1);
    LedStatus1 = 1;
    delay(1000);
    digitalWrite(LedPin1,0);
    LedStatus1 = 0;
   }
  }
 }
}