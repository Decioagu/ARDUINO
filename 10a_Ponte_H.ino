/*
  Funcionamento da ponte H
  EN1 | NE2 => LIGAR MOTOR
  IN1 | IN3 => ROTAÇÃO HORARIA
  IN2 | IN4 => ROTAÇÃO ANTE-HORARIA
*/


// MOTOR 1
#define EN1 4 // definir pino "4" Arduino (apelidar de EN4)
#define IN1 3 // definir pino "3" Arduino (apelidar de IN3)
#define IN2 2 // definir pino "2" Arduino (apelidar de IN2)

// MOTOR 2
#define EN2 7 // definir pino "7" Arduino (apelidar de EN2)
#define IN3 6 // definir pino "6" Arduino (apelidar de IN3)
#define IN4 5 // definir pino "5" Arduino (apelidar de IN4)

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

void loop() {
  // movimento dos motores
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