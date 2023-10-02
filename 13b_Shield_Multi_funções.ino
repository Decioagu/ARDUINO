/*
    * Shield Multi-funções:
    * Buzina liga em nível logico baixo.
    * Botões aciona em nível logico baixo.

    Manipulando a frequência de pulso com PWM, altere o som da buzina
    utilizando os três botões do Shield Multi-funções.

    # digitalWrite(pino, liga/desliga);
    # analogWrite(pino, angulo de pulso PWM)
    ### (angulo de pulso PWM = 0 até 255) ###
*/

#define BUZ 3     // definir pino "3" Arduino (apelidar de BTN_CIMA)
#define BTN1 A1   // definir pino "A1" Arduino (apelidar de BTN1)
#define BTN2 A2   // definir pino "A2" Arduino (apelidar de BTN2)
#define BTN3 A3   // definir pino "A3" Arduino (apelidar de BTN3)

void setup() {
  pinMode(BUZ, OUTPUT); // pino(porta, saída)
  pinMode(BTN1, INPUT); // pino(porta, entrada)
  pinMode(BTN2, INPUT); // pino(porta, entrada)
  pinMode(BTN3, INPUT); // pino(porta, entrada)

  digitalWrite(BUZ, LOW);  // liga buzina
  delay(5000);  // espera
  digitalWrite(BUZ, HIGH);  // desliga buzina
}

void loop() {
    // acionamento de botão
    if ( digitalRead(BTN1) == 0 ) {
      analogWrite(BUZ, 50); // liga buzina
      delay(1000);  // espera
      analogWrite(BUZ, 255);// desliga buzina
    }
    
    if ( digitalRead(BTN2) == 0 ) {
      analogWrite(BUZ, 100); // liga buzina
      delay(1000);  // espera
      analogWrite(BUZ, 255);// desliga buzina
    }
    
    if ( digitalRead(BTN3) == 0 ) {
      analogWrite(BUZ, 200); // liga buzina
      delay(1000);  // espera
      analogWrite(BUZ, 255);  // desliga buzina
    }
}
