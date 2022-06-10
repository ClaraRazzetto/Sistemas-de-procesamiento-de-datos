int lectura = 0;
int distancia = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando");
}

void loop()
{
  lectura = readUltrasonicDistance(7,7);
  distancia = 0.01723 * lectura;
  Serial.print(distancia);
  Serial.println("cm");
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