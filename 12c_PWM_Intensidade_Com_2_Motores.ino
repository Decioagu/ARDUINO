/*
  Controle o RPM de dois motores por meio tempo de acionamento (liga, desliga)
  ou velocidade angular, utilizando um potenciômetros individualmente.
*/

#define EN1 3 // nomear pino
#define IN1 2 // nomear pino
#define IN2 4 // nomear pino

#define EN2 5 // nomear pino
#define IN3 6 // nomear pino
#define IN4 7 // nomear pino

void setup() {

  /*
      Funcionamento da ponte H
      EN1 | NE2 => LIGAR MOTOR
      IN1 | IN3 => ROTAÇÃO HORARIA
      IN2 | IN4 => ROTAÇÃO ANTE-HORARIA
  */
  
  // MOTOR 1
  pinMode(EN1, OUTPUT); // pino(porta, saída)
  pinMode(IN1, OUTPUT); // pino(porta, saída)
  pinMode(IN2, OUTPUT); // pino(porta, saída)

  // MOTOR 2
  pinMode(EN2, OUTPUT); // pino(porta, saída)
  pinMode(IN3, OUTPUT); // pino(porta, saída)
  pinMode(IN4, OUTPUT); // pino(porta, saída)

  pinMode(A0, INPUT); // pino(porta, entrada)
  pinMode(A1, INPUT); // pino(porta, entrada)
  
  // acionamento MOTOR 1
  digitalWrite(EN1, 1); 
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);

  // acionamento MOTOR 2
  digitalWrite(EN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void loop() {
  // MOTOR 1
  int pot1 = analogRead(A0);  //ler porta do potenciômetro (0 até 1023)
  int velocidade1 = map(pot1, 0, 1023, 0, 255); // conversão de valores
  analogWrite(EN1, velocidade1); // saída de valor para motor de 0 até 255

  // MOTOR 2
  int pot2 = analogRead(A1); //ler porta do potenciômetro (0 até 1023)
  int velocidade2 = map(pot2, 0, 1023, 0, 255); // conversão de valores
  analogWrite(EN2, velocidade2); // saída de valor para motor de 0 até 255
}