/*
  Controle o RPM do motor por meio tempo de acionamento (liga, desliga)
  ou velocidade angular, utilizando um potenciômetro.
*/

#define MOTOR 3 // definir pino "3" Arduino (apelidar de MOTOR)

void setup(){
  pinMode(MOTOR, OUTPUT); // pino(porta, saída)
  pinMode(A0, INPUT); // pino(porta, entrada)
}

void loop(){
  int pot = analogRead(A0);  //ler porta do potenciômetro (0 até 1023)
  int velocidade = map(pot, 0, 1023, 0, 255); // conversão de valores
  analogWrite(MOTOR, velocidade); // saída de valor para motor de 0 até 255
}
  