#include <IRremote.h>

int RecvPin = 14;
int IRData = 0;

//creo un objeto para el receptor(sensor) especificando el pin
IRrecv irrecv (RecvPin);
//Variable results se guardan los datos recibidos por sensor
decode_results results;

void setup()
{
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
 }   
}