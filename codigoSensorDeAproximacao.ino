const int TRIGGER_PIN = A0;
const int ECHO_PIN = A1;
const int inter_time = 250;
const int ledVerde1 = 13;
const int ledVerde2 = 12;
const int ledAmarelo1 = 11;
const int ledAmarelo2 = 10;
const int ledVermelho1 = 9;
const int ledVermelho2 = 8;
const int buzzer = 3;

void setup() {
  //Configura quais PINs são de entrada ou saída.
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledAmarelo1, OUTPUT);
  pinMode(ledAmarelo2, OUTPUT);
  pinMode(ledVermelho1, OUTPUT);
  pinMode(ledVermelho2, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

}



void loop() {
  float tempo, distancia;
  float freq_buzzer;
    
  digitalWrite(TRIGGER_PIN, HIGH);
  digitalWrite(TRIGGER_PIN, LOW);
  
  tempo = pulseIn(ECHO_PIN, HIGH);
  //Tempo em que as ondas emitidas atingem o sensor.
  
  distancia = (tempo * .0343)/2;
  /*	
	Utilizamos a velocidade do som em 'ms' para calcular a distância,
  assim multiplicamos o tempo pela velocidade.
  	Dividimos por dois pois as ondas colidem com o receptor
  na metade da distância que percorrem.
  */
  
  freq_buzzer = distancia * 2;
  //Determina o intervalo de ativação do buzzer.
  
  
  /*
  Este aninhamento de condicionais determinam quais leds irão 
  ligar de acordo com a distância, e em que tom o buzzer irá tocar.
  */
  if(distancia < 300 && distancia >= 200){
    tone(buzzer, 350);
    delay(freq_buzzer);
    noTone(buzzer);
    
    digitalWrite(ledVerde1, HIGH);
    digitalWrite(ledVerde2, HIGH);
    digitalWrite(ledAmarelo1, LOW);
    digitalWrite(ledAmarelo2, LOW);
    digitalWrite(ledVermelho1, LOW);
    digitalWrite(ledVermelho2, LOW);
  }
  else if(distancia < 200 && distancia >= 80){
    tone(buzzer, 450);
    delay(freq_buzzer);
    noTone(buzzer);
    
    digitalWrite(ledAmarelo1, HIGH);
    digitalWrite(ledAmarelo2, HIGH);
    digitalWrite(ledVerde1, LOW);
    digitalWrite(ledVerde2, LOW);
    digitalWrite(ledVermelho1, LOW);
    digitalWrite(ledVermelho2, LOW);
   
  }else if(distancia < 80 && distancia >= 20){  
    tone(buzzer, 550);
    delay(freq_buzzer);
    noTone(buzzer);
    
    digitalWrite(ledVermelho1, HIGH);
    digitalWrite(ledVermelho2, HIGH);
    digitalWrite(ledVerde1, LOW);
    digitalWrite(ledVerde2, LOW);
    digitalWrite(ledAmarelo1, LOW);
    digitalWrite(ledAmarelo2, LOW);
  }else if(distancia < 20){
  	tone(buzzer, 650);
  }
  
  delay(inter_time);
}

