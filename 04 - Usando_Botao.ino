/*
    LED pisca em intensidade diferente precintando o botão 1 ou botão 2.
    * botão 1 => BNT_1 = 0,1s
    * botão 2 => BNT_2 = 1s
*/

#define LED	7 // definir pino "7" Arduino (apelidar de LED)
#define BTN_1 2 // definir pino "2" Arduino (apelidar de BTN_1)
#define BTN_2 3 // definir pino "3" Arduino (apelidar de BTN_2)2
int velocidade = 500; // variável 

// ler um vez
void setup() {
	pinMode(BTN_1, INPUT); // pino(porta, entrada)
	pinMode(BTN_2, INPUT); // pino(porta, entrada)
  	pinMode(LED, OUTPUT); // pino(porta, saída)
  
  	Serial.begin(9600); // taxa de transmissão de dados "9600 bits por segundo (bps)"
  	Serial.println("Iniciar Programa"); // print no monitor serial
}

// loop infinito
void loop() {
    // LED pisca em 0,1s (mudança de estado do botão quando pressionado)
  if ( digitalRead(BTN_1) == 1 ) {
    velocidade = 250;
    Serial.println("BTN_1");
  }
    
    // LED pisca em 1s (mudança de estado do botão quando pressionado)
  if ( digitalRead(BTN_2) == 1 ) {
   	velocidade = 1000; 
    Serial.println("BTN_2");
  }
  
  // velocidade muda conforme botão pressionado e permanece até outra mudança 
  digitalWrite(LED, HIGH); // ACENDER
  delay(velocidade); // tempo de espera
  
  digitalWrite(LED, LOW); // APAGAR
  delay(velocidade); // tempo de espera
}