#include <Servo.h>  // blibioteca Servo Motor

/*
  Servo motor de angulo 180º. 
  Um ângulo de 180 graus para um servo motor significa que o servo 
  motor pode girar completamente até 180º em seu eixo.

  Movimento de ângulos pre determinado 0, 45, 90, 135, 180.
*/

Servo meuservo; // nomeia servo a ser utilizado

void setup()
{
    /*
      A instrução  é uma função da biblioteca Servo do Arduino que conecta um servo motor a um pino digital do Arduino.
      servo.attach(pino, pulso mínimo, pulso máximo)
      Valores padronizados caso haja omissão dos valores:
      servo.attach(pino, 544, 2400)
    */
    meuservo.attach(9, 500, 2500); // chamar método e informar pino
  
}

// loop infinito
void loop() {
  meuservo.write(0); // Move o servo motor para 0 graus.
  delay(2000); // Aguarda 1 segundo.

  meuservo.write(45); // Move o servo motor para 0 graus.
  delay(1000); // Aguarda 1 segundo.

  meuservo.write(90); // Move o servo motor para 90 graus.
  delay(1000); // Aguarda 1 segundo.

  meuservo.write(135); // Move o servo motor para 0 graus.
  delay(1000); // Aguarda 1 segundo.

  meuservo.write(180); // Move o servo motor para 180 graus.
  delay(2000); // Aguarda 1 segundo.
}