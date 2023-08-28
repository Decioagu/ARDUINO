// porta digital 13 => ligar e desligar LED (Pisca_Pisca)

// ler uma vez
void setup() {
  	Serial.begin(9600); // taxa de transmissão de dados "9600 bits por segundo (bps)"
	pinMode(13, OUTPUT); // pino(porta, saída)
	Serial.println("Iniciar Programa"); // print no monitor serial
} 

// loop infinito
void loop() {
	digitalWrite(13, HIGH); // escrever (porta, ALTO) \ HIGH = 1
	Serial.println("5V"); // print no monitor serial
  	delay(500); // esperar 0,5 s
  	digitalWrite(13, LOW); // escrever (porta, BAIXO) \ LOW = 0
	Serial.println("0V"); // print no monitor serial
  	delay(500); // esperar 0,5 s
}