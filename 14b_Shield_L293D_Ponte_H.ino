/*
    * Adafruit Motor Shield L293D (Ponte H)

    Com o auxílio de um joystick manipule uma plataforma com dois motores
    utilizando "Adafruit Motor Shield L293D (Ponte H)" e sua biblioteca "<AFMotor.h>",
    com velocidade variável no joystick.
*/

#include <AFMotor.h>  // biblioteca

AF_DCMotor motorEsq(1);  // acionamento da biblioteca
AF_DCMotor motorDir(2);  // acionamento da biblioteca


// joystick           |****** EIXO ******|
#define EIXO_X A8  // |direita | esquerda|
#define EIXO_Y A9  // |   cima | baixo   |

int velocidade = 0;

void setup(){
  // joystick
  pinMode(EIXO_X, INPUT);  // pino(porta, entrada)
  pinMode(EIXO_Y, INPUT);  // pino(porta, entrada)

  Serial.begin(9600);

  motorEsq.setSpeed(0); // velocidade (0 até 255)
  motorDir.setSpeed(0); // velocidade (0 até 255)

  motorEsq.rum(RELEASE);  // parar motor (RELEASE = LIBERAR)
  motorDir.rum(RELEASE);  // parar motor (RELEASE = LIBERAR)
}

void loop(){
  // joystick
  x = analogRead(EIXO_X);  // ler joystick
  y = analogRead(EIXO_Y);  // ler joystick

  // ver valores no monitor serial
  Serial.print("EIXO_X: ");
  Serial.println(x);
  Serial.print("EIXO_Y: ");
  Serial.println(y);
  Serial.println("---------------");
  /*
    OBS: Analisar valores EIXO_X e EIXO_Y para identificar ponto x = 0 e y = 0 do joystick
  */

  // interpreta valores conforme joystick
  if (x < 500) {
    // DIREITA
    velocidade = map(x, 500, 0, 0, 255);
    motorEsq.setSpeed(velocidade); // velocidade (0 até 255)
    motorDir.setSpeed(velocidade); // velocidade (0 até 255)
    motorEsq.rum(BACKWARD);  // motor (BACKWARD = PARA TRÁS)
    motorDir.rum(FORWARD);  // motor (FORWARD = PARA FRENTE)
  } else if (x > 520){
    // ESQUERDA
    velocidade = map(x, 520, 1023, 0, 255);
    motorEsq.setSpeed(velocidade); // velocidade (0 até 255)
    motorDir.setSpeed(velocidade); // velocidade (0 até 255)
    motorEsq.rum(FORWARD);  // motor (BACKWARD = PARA FRENTE)
    motorDir.rum(BACKWARD);  // motor (FORWARD = PARA TRÁS)
  } else if (y < 500){
    // FRENTE
      velocidade = map(y, 500, 0, 0, 255);
    motorEsq.setSpeed(velocidade); // velocidade (0 até 255)
    motorDir.setSpeed(velocidade); // velocidade (0 até 255)
    motorEsq.rum(FORWARD);  // motor (BACKWARD = PARA FRENTE)
    motorDir.rum(FORWARD);  // motor (FORWARD = PARA FRENTE)
  } else if (x > 520){
    // TRÁS
    velocidade = map(y, 520, 1023, 0, 255);
    motorEsq.setSpeed(velocidade); // velocidade (0 até 255)
    motorDir.setSpeed(velocidade); // velocidade (0 até 255)
    motorEsq.rum(BACKWARD);  // motor (BACKWARD = PARA TRÁS)
    motorDir.rum(BACKWARD);  // motor (FORWARD = PARA TRÁS)
  } else {
    // PARAR
    motorEsq.setSpeed(0);  // velocidade (0 até 255)
    motorDir.setSpeed(0);  // velocidade (0 até 255)
  }
  
  delay(1000);
}
