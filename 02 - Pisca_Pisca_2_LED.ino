// porta digital => ligar e desligar LED alternado (ledVermelho\ledAmarelo)

#define ESPERA	500 // constante

int ledVermelho = 8; // definir pino "8" Arduino (apelidar de ledVermelho)
int ledAmarelo = 7; // definir pino "7" Arduino (apelidar de ledAmarelo)

// ler um vez
void setup() {
	pinMode(ledVermelho, OUTPUT); // pino(porta, saída)
  	pinMode(ledAmarelo, OUTPUT); // pino(porta, saída)
}

// loop infinito
void loop() {
 	digitalWrite(ledVermelho, HIGH); // escrever (porta, ALTO)
  	digitalWrite(ledAmarelo, LOW); // escrever (porta, BAIXO)
  	delay(ESPERA); // esperar 0,5 s
  	
  	digitalWrite(ledVermelho, LOW); // escrever (porta, BAIXO)
  	digitalWrite(ledAmarelo, HIGH); // escrever (porta, ALTO)
  	delay(ESPERA); // esperar 0,5 s
}