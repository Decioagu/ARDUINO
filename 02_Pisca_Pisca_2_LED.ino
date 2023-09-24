// porta digital => ligar e desligar LED alternado (ledVerde\ledAmarelo)

// #define => Constante
#define ESPERA	500 // constante de valor 500

int ledVerde = 8; // definir pino "8" Arduino (apelidar de ledVerde)
int ledAmarelo = 7; // definir pino "7" Arduino (apelidar de ledAmarelo)

// ler um vez
void setup() {
	pinMode(ledVerde, OUTPUT); // pino(porta, saída)
  	pinMode(ledAmarelo, OUTPUT); // pino(porta, saída)
}

// loop infinito
void loop() {
 	digitalWrite(ledVerde, HIGH); // escrever (porta, ALTO)
  	digitalWrite(ledAmarelo, LOW); // escrever (porta, BAIXO)
  	delay(ESPERA); // esperar 0,5 s
  	
  	digitalWrite(ledVerde, LOW); // escrever (porta, BAIXO)
  	digitalWrite(ledAmarelo, HIGH); // escrever (porta, ALTO)
  	delay(ESPERA); // esperar 0,5 s
}