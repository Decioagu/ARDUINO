/*
  Controle o a intensidade do brilho do LED por meio tempo de acionamento (liga, desliga)
  ou velocidade angular, utilizando um potenciômetro.
*/

#define LED_VERMELHO 3 // definir pino "3" Arduino (apelidar de LED_VERMELHO)

int valor_atual = 0; // variável
int valor_max = 500; // variável

void setup(){
  pinMode(LED_VERMELHO, OUTPUT); // pino(porta, saída)
  pinMode(A0, INPUT); // pino(porta, entrada)
}

void loop(){
  int pot = analogRead(A0); //ler porta do potenciômetro (0 até 1023)

  valor_atual = map(pot, 0, 1023, 0, valor_max); // conversão de valores

  digitalWrite(LED_VERMELHO, 1); // LED ligado
  delay(valor_atual); // espera
  digitalWrite(LED_VERMELHO, 0); // LED desligado
  delay(valor_max - valor_atual);   // espera
}