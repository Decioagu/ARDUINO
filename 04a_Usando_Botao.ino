/*
    Ligue o LED utilizando botão ou chave.
    * botão 1 => BNT_1 = 0,1s
    * botão 2 => BNT_2 = 1s
    
    OBS: com chave ativada LED permanece ligado permanentemente até ser desativada
*/

// #define => Constante
#define LED	1 // definir pino "7" Arduino (apelidar de LED)
#define CHAVE 2 // definir pino "2" Arduino (apelidar de CHAVE_1)
#define BTN 3 // definir pino "3" Arduino (apelidar de BTN_2)
int velocidade = 500; // variável 

// ler um vez
void setup() {
	pinMode(CHAVE, INPUT); // pino(porta, entrada)
	pinMode(BTN, INPUT); // pino(porta, entrada)
  	pinMode(LED, OUTPUT); // pino(porta, saída)
}

// loop infinito
void loop() {
    // LED pisca em 0,1s (mudança de estado do botão quando pressionado)
  if ( digitalRead(CHAVE) == 1 ) {
    digitalWrite(LED, 1);
    while (digitalRead(CHAVE) == 1){}  
  } else if ( digitalRead(BTN) == 1 ) {
    digitalWrite(LED, 1);
    while (digitalRead(BTN) == 1){}
  } else {
    digitalWrite(LED, 0);
  }
}