/*
    Chave seletora de duas posições.
    Acionam LED`s (Verde ou Vermelho) conforme posição de chave seletora (key switch)
*/


#define LED_VD 8 // definir pino "8" Arduino (apelidar de LED_VD)
#define LED_VM 7 // definir pino "7" Arduino (apelidar de LED_VM)
#define SW_D 3 // definir pino "3" Arduino (apelidar de SW_D)
#define SW_E 2 // definir pino "2" Arduino (apelidar de SW_E)
int ledSelecionado; // variável

// ler um vez
void setup() {
  	pinMode(LED_VM, OUTPUT); // pino(porta, saída)
  	pinMode(LED_VD, OUTPUT); // pino(porta, saída)
  	pinMode(SW_D, INPUT); // pino(porta, entrada)
  	pinMode(SW_E, INPUT); // pino(porta, entrada)
}

// loop infinito
void loop() {
  // chave posição lado direito acende LED verde
  if ( digitalRead(SW_D) == 1 ) {
     ledSelecionado = LED_VD;
  }
  // chave posição lado esquerdo acende LED vermelho
  if ( digitalRead(SW_E) == 1 ) {
     ledSelecionado = LED_VM;
  }
  
  // LED acende 0,5s
  digitalWrite(ledSelecionado, HIGH);
  delay(500);
  // LED apaga 0,5s
  digitalWrite(ledSelecionado, LOW);
  delay(500);
  
}