const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int tempo =200;
  
const int buzzerPin = 8;
const int ledPin1 = 12;
const int ledPin2 = 13;
 
int counter = 0;
 
void setup()
{
  //Setup pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}
 
void loop()
{
 
  //Play first section
  firstSection();
 
  //Play second section
  secondSection();
}
 
void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }else
  {
    digitalWrite(ledPin2, HIGH);
    delay(duration);
    digitalWrite(ledPin2, LOW);
  }
 
  //Stop tone on buzzerPin
  noTone(buzzerPin);
 
  delay(tempo);
 
  //Increment counter
  counter++;
}
 
void firstSection()
{
  beep(e, tempo);
  beep(e, tempo);    
  beep(e, tempo*2);    
  beep(e, tempo);    
  beep(e, tempo);    
  beep(e, tempo*2);    
  beep(e, tempo);  
  beep(g, tempo);  
  beep(c, tempo);
  beep(d, tempo);  
  beep(e, tempo*2);  
  
  delay(tempo*2);

}
 
void secondSection()
{
  beep(f, tempo);  
  beep(f, tempo);  
  beep(f, tempo);  
  beep(f, tempo);
  beep(f, tempo);  
  beep(e, tempo);  
  beep(e, tempo);
  beep(e, tempo);  
  beep(e, tempo);  
  beep(d, tempo);
  beep(d, tempo);
  beep(e, tempo*2);
  beep(d, tempo*2);
  beep(g, tempo);

  delay(tempo*2);
}