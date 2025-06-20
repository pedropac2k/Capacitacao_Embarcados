#include <LiquidCrystal.h>

const int sensorPin = 9;
const int ledPin = 10;

//configura os pinos que estão ligados ao display lcd.
LiquidCrystal display(12, 11, 5, 4, 3, 2);

int leitura;

void setup(){
  display.begin(16, 2);
  //define as dimensões do display lcd.
  Serial.begin(9600);

}

void loop(){ 
  leitura = digitalRead(sensorPin);
  //armazena o estado do sensor na variével 'leitura'.
  
  if(leitura == HIGH){
    //caso o sensor detecte movimento, uma mensagem é exibida no display e o led acende.
  	digitalWrite(ledPin, HIGH);
    
    display.setCursor(3, 0);
    display.print("Movimento");
    
    display.setCursor(3, 1);
    display.print("Detectado");
  }else{
    //caso contrário o display é limpo e o led desliga.
  	digitalWrite(ledPin, LOW);
    display.clear();

  }
} 