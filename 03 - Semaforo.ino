/*
	Faça um circuito contendo 3 LEDs, um verde, um amarelo e um vermelho. 
	Estes LEDs representarão um semáforo. O LED verde deve ser controlado pelo pino 13; 
	o LED amarelo deve ser controlado pelo pino 12; 
	e o LED vermelho deve ser controlado pelo pino 11.

	Assim que a simulação começar o LED verde deve acender e permanecer aceso por 5 segundos. 
	Após esse tempo o LED verde deve apagar e o LED amarelo deve acender e ficar nesse estado 
	por 2 segundos. Por fim, o LED vermelho deve acender e se manter aceso por 5 segundos.
*/

// Semáforo

#define ledVerde 13 // definir pino "13" Arduino (apelidar de ledVerde)
#define ledAmarelo 12 // definir pino "12" Arduino (apelidar de ledAmarelo)
#define ledVermelho 11 // definir pino "11" Arduino (apelidar de ledVermelho)

// ler um vez
void setup() {
  	Serial.begin(9600); // taxa de transmissão de dados "9600 bits por segundo (bps)"
	pinMode(ledVerde, OUTPUT); // pino(porta, saída)
  	pinMode(ledAmarelo, OUTPUT); // pino(porta, saída)
    pinMode(ledVermelho, OUTPUT); // pino(porta, saída)
  	Serial.println("Iniciar Programa"); // print no monitor serial
}

// loop infinito
void loop() {
 	digitalWrite(ledVerde, HIGH); // escrever (porta, ALTO)
  	digitalWrite(ledAmarelo, LOW); // escrever (porta, BAIXO)
    digitalWrite(ledVermelho, LOW); // escrever (porta, BAIXO)
  	Serial.println("Sinal Verde"); // print no monitor serial
  	delay(5000); // esperar 5s
  
    digitalWrite(ledVerde, LOW); // escrever (porta, ALTO)
  	digitalWrite(ledAmarelo, HIGH); // escrever (porta, BAIXO)
    digitalWrite(ledVermelho, LOW); // escrever (porta, BAIXO)
  	Serial.println("Sinal Amarelo"); // print no monitor serial
  	delay(2000); // esperar 2s
  
    digitalWrite(ledVerde, LOW); // escrever (porta, ALTO)
  	digitalWrite(ledAmarelo, LOW); // escrever (porta, BAIXO)
    digitalWrite(ledVermelho, HIGH); // escrever (porta, BAIXO)
  	Serial.println("Sinal Vermelho"); // print no monitor serial
  	delay(5000); // esperar 5s
}