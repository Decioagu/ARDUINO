#include <Servo.h>

/*
  Servo motor de angulo 180º. 
  Um ângulo de 180 graus para um servo motor significa que o servo 
  motor pode girar completamente até 180º em seu eixo.

  Movimento de ângulos linear de 0 até 180 e 180 até 0.
*/
Servo servo_9; // nomeia servo a ser utilizado

int pos = 0; // variável

void setup()
{
  /*
      A instrução  é uma função da biblioteca Servo do Arduino que conecta um servo motor a um pino digital do Arduino.
      servo.attach(pino, pulso mínimo, pulso máximo)
      Valores padronizados caso haja omissão dos valores:
      servo.attach(pino, 544, 2400)
  */
  servo_9.attach(9, 500, 2500);
}

void loop()
{
  // varre o servo de 0 a 180 graus em etapas 
  for (pos = 0; pos <= 180; pos += 1) {
    servo_9.write(pos); // servo move posição 'pos'
    delay(20); //Aguarde 20 milissegundo(s) para proxima posição 
  }
  delay(1000);
  // varre o servo de 180 a 0 graus em etapas
  for (pos = 180; pos >= 0; pos -= 1) {
    // tell servo to go to position in variable 'pos'
    servo_9.write(pos); // servo move posição 'pos'
    delay(20); //Aguarde 20 milissegundo(s) para proxima posição)
  }
  delay(1000);
}