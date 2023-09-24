/*
  Funcionamento da ponte H
  EN1 | NE2 => LIGAR MOTOR
  IN1 | IN3 => ROTAÇÃO HORARIA
  IN2 | IN4 => ROTAÇÃO ANTE-HORARIA

  Controle por meio de botões rotação dos motores:
  * FRENTE
  * TRÁS
  * ESQUERDA
  * DIREITA
  * PARAR
*/

// MOTOR 1
#define EN1 4 // definir pino "4" Arduino (apelidar de EN4)
#define IN1 3 // definir pino "3" Arduino (apelidar de IN3)
#define IN2 2 // definir pino "2" Arduino (apelidar de IN2)

// MOTOR 2
#define EN2 7 // definir pino "7" Arduino (apelidar de EN2)
#define IN3 6 // definir pino "6" Arduino (apelidar de IN3)
#define IN4 5 // definir pino "5" Arduino (apelidar de IN4)

// MOVIMENTO
#define FRENTE 9    // definir pino "9" Arduino (apelidar de FRENTE)
#define TRAS 10     // definir pino "10" Arduino (apelidar de TRAS)
#define ESQUERDA 8  // definir pino "8" Arduino (apelidar de ESQUERDA)
#define DIREITA 11  // definir pino "11" Arduino (apelidar de DIREITA)
#define PARAR 12    // definir pino "12" Arduino (apelidar de PARAR)


void setup() {
  // MOTOR 1
  pinMode(EN1, OUTPUT);  // pino(porta, entrada)
  pinMode(IN1, OUTPUT);  // pino(porta, entrada)
  pinMode(IN2, OUTPUT);  // pino(porta, entrada)

  // MOTOR 2
  pinMode(EN2, OUTPUT);  // pino(porta, entrada)
  pinMode(IN3, OUTPUT);  // pino(porta, entrada)
  pinMode(IN4, OUTPUT);  // pino(porta, entrada) 

  /*  INPUT_PULLUP é um modo de pino digital no Arduino que usa um resistor interno para puxar o pino 
      para a tensão de alimentação alto (HIGH) quando não está conectado a nada. Isso permite que você use um botão 
      para nível logico baixo (LOW) e controlar alguma condição.
  */
  //MOVIMENTO
  pinMode(FRENTE, INPUT_PULLUP);    // pino(porta, entrada)
  pinMode(TRAS, INPUT_PULLUP);      // pino(porta, entrada)
  pinMode(ESQUERDA, INPUT_PULLUP);  // pino(porta, entrada)
  pinMode(DIREITA, INPUT_PULLUP);   // pino(porta, entrada)
  pinMode(PARAR, INPUT_PULLUP);     // pino(porta, entrada)
  
}

// rotação do motor 1 sentido horário
void motor1_horario(){
  digitalWrite(EN1, 1);
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
}

// rotação do motor 1 sentido ante-horário
void motor1_ante_horario(){
  digitalWrite(EN1, 1);
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
}

// rotação do motor 2 sentido horário
void motor2_horario(){
  digitalWrite(EN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

// rotação do motor 2 sentido ante-horário
void motor2_ante_horario(){
  digitalWrite(EN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

// para a rotação de ambos os motores
void motor_parar(){
  digitalWrite(EN1, 0);
  digitalWrite(EN2, 0);
}

void loop() {
  // aciona um botão por vez
  if (digitalRead(FRENTE) == 0){
    motor1_horario();
    motor2_horario();
    while (digitalRead(FRENTE) == 0){} 
  } else if (digitalRead(TRAS) == 0){
    motor1_ante_horario();
    motor2_ante_horario();
    while (digitalRead(TRAS) == 0){}
  } else if (digitalRead(ESQUERDA) == 0){
    motor1_ante_horario();
    motor2_horario();
    while (digitalRead(ESQUERDA) == 0){}
  } else if (digitalRead(DIREITA) == 0){
    motor1_horario();
    motor2_ante_horario();
    while (digitalRead(DIREITA) == 0){}
  } else if (digitalRead(PARAR) == 0){
    motor_parar();
    while (digitalRead(PARAR) == 0){}
  }
}