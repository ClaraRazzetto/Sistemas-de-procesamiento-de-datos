//Libreria para LCD
#include <LiquidCrystal.h>

//Cnfiguro LCD (pines)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int triggerPin = 7;
int echoPin = 7;
float distancia = 0;
int lectura = 0;
int anterior = 0;

void setup()
{
  //Inicializo el LCD 
  lcd.begin(16,2);
  //Mando un mensaje para mostrar en el LCD
  lcd.print("Iniciando");
  //Indico la línea en la que se muestra el mensaje
  lcd.setCursor(0,1);
  lcd.print("Sistema");
  delay(1000);
  //Limpio el LCD
  lcd.clear();

  //Muestro nuevamente
  lcd.print("Iniciando");
  lcd.setCursor(0,1);
  lcd.print("Sistema");
  delay(1000);
  lcd.clear();
  
  //Nuevo mensaje
  lcd.print("Distancia en cm: ");
  lcd.setCursor(0,1);
}
 
void loop()
{ 
  lcd.setCursor(0,1);
  lectura = readUltrasonicDistance(triggerPin,echoPin);
  if (lectura != anterior){
   distancia = 0.01723 * lectura;
   lcd.print(distancia);
   anterior = lectura;
  }
  delay(100);
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}


