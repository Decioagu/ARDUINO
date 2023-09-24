/*
  Funcionamento da ponte H
  EN1 | NE2 => LIGAR MOTOR
  IN1 | IN3 => ROTAÇÃO HORARIA
  IN2 | IN4 => ROTAÇÃO ANTE-HORARIA
*/

// MOTOR 1
#define EN1 4
#define IN1 3
#define IN2 2

// MOTOR 2
#define EN2 7
#define IN3 6
#define IN4 5

void setup() {
  // MOTOR 1
  pinMode(EN1, OUTPUT);  // pino(porta, entrada)
  pinMode(IN1, OUTPUT);  // pino(porta, entrada)
  pinMode(IN2, OUTPUT);  // pino(porta, entrada)

  // MOTOR 2
  pinMode(EN2, OUTPUT);  // pino(porta, entrada)
  pinMode(IN3, OUTPUT);  // pino(porta, entrada)
  pinMode(IN4, OUTPUT);  // pino(porta, entrada) 
}

void motor1_horario(){
  digitalWrite(EN1, 1);
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
}

void motor1_ante_horario(){
  digitalWrite(EN1, 1);
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
}

void motor2_horario(){
  digitalWrite(EN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
}

void motor2_ante_horario(){
  digitalWrite(EN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
}

void loop() {
  motor1_horario();
  motor2_horario();
  delay(3000);
  motor1_ante_horario();
  motor2_ante_horario();
  delay(3000);
  motor1_horario();
  motor2_ante_horario();
  delay(3000);
  motor1_ante_horario();
  motor2_horario();
  delay(3000);
}