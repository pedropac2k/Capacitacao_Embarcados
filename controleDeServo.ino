#include <Servo.h>
 
//define os limites que o potenciômetro pode assumir.
#define MIN_POT 0
#define MAX_POT 1023
//define os limites de angulação do servo.
#define MIN_SERVO 0
#define MAX_SERVO 180

const int potPin = A2;
const int servoPin = 10;

Servo servo;

int potVal;
int valConvertido;

void setup(){
  servo.attach(servoPin);
  //relaciona o servo com o seu pino
  servo.write(0);
  //faz com que ao iniciar o programa o ângulo do servo seja 0. 
  Serial.begin(9600);
}

void loop(){
  potVal = analogRead(potPin);
  //lê o valor do potenciômetro.
  Serial.print("Potenc: ");
  Serial.println(potVal);
  
  valConvertido = map(potVal, MIN_POT, MAX_POT, MIN_SERVO, MAX_SERVO);
  //converte o valor do potenciômetro para um valor proporcional ao ângulo do servo.
  
  servo.write(valConvertido);
  //determina o ângulo do servo.
  Serial.print("Servo: ");
  Serial.println(valConvertido);
  
  delay(1000);
}