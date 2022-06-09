//Libreria para LCD
#include <LiquidCrystal.h>

//Cnfiguro LCD (pines)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int contador = 0;
int ledPin = 13;

void setup()
{
  //configuro el pin del led 
  pinMode(ledPin,OUTPUT);
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
  lcd.print("Contanto Numeros");
  lcd.setCursor(0,1);
  lcd.print("Valor:");
}
 
void loop()
{ 
  lcd.setCursor(7,1);
  lcd.print(contador);
  
  //Muestro una carita y luego la borro si el contador esta en 2
  if(contador > 5 && contador < 10)
  {
    digitalWrite(ledPin,HIGH);
    lcd.print(":)");
    delay(1500);
    digitalWrite(ledPin,LOW);
    lcd.setCursor(8,1);
    lcd.print("  ");
  }
  
  contador++;
  delay(1000);
}