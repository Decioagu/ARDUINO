#include <Servo.h>  // blibioteca Servo Motor

/*
  Servo motor de angulo 180º. 
  Um ângulo de 180 graus para um servo motor significa que o servo 
  motor pode girar completamente até 180º em seu eixo.
*/
Servo meuservo; // nomeia servo a ser utilizado

void setup()
{
    /*
      A instrução  é uma função da biblioteca Servo do Arduino que conecta um servo motor a um pino digital do Arduino.
      servo.attach(pino, pulso mínimo, pulso máximo)
      Valores padronizados caso haja omisão dos valores:
      servo.attach(pino, 544, 2400)
    */
    meuservo.attach(2, 500, 2500); // chamar método e informar pino

    pinMode(A5, INPUT); // pino(porta, saida)
}

// loop infinito
void loop() {
   
  /*
    A função  no Arduino é uma função matemática que mapeia 
    um valor de um intervalo para outro intervalo.map()

    A função  tem quatro argumentos:
    
    map(valor, mínimo_atual, máximo_atual, mínimo_novo, máximo_novo)

    # valor: O valor a ser mapeado.
    # mínimo_atual: O limite inferior do intervalo atual.
    # máximo_atual: O limite superior do intervalo atual.
    # mínimo_novo: O limite inferior do novo intervalo.
    # máximo_novo: O limite superior do novo intervalo.
  */
  
  int pot = analogRead(A5); //ler porta do potenciômetro (0 até 1023)

  // int angulo = map(pot, valor_mín, valor_max, angulo_mín, angulo_max)
  int angulo = map(pot, 0, 1023, 0, 180);
  meuservo.write(angulo); // servo move posição 'pos'
  delay(500); // espera
  
}