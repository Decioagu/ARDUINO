/*
    * Shield Multi-funções:

    Neste projeto esta se utilizando duas biblioteca:
    # <TimerOne.h> : biblioteca que permite controlar o temporizador de placa 
    # <MultiFuncShield.h> : biblioteca especifica para manipular a Shield Multi-funções
*/

#include <TimerOne.h>  // biblioteca 
#include <MultiFuncShield.h> // biblioteca

#define AUMENTA A1  // definir pino "A1" Arduino (botão da placa Shield Multi-funções)
#define DIMINUI A2  // definir pino "A2" Arduino (botão da placa Shield Multi-funções)
#define INICIAR A3  // definir pino "A3" Arduino (botão da placa Shield Multi-funções)

int tempo = 0;  // variável (contador)

void setup() {
  Timer1.initialize();  // iniciar biblioteca <TimerOne.h>
  MFS.initialize(&Timer1);  // pre requisito para uso da biblioteca  <MultiFuncShield.h>

  pinMode(AUMENTA, INPUT); // pino(porta, entrada)
  pinMode(DIMINUI, INPUT); // pino(porta, entrada)
  pinMode(INICIAR, INPUT); // pino(porta, entrada)

  MFS.beep();  // aciona a buzina da placa Shield Multi-funções por breve período pre-determinado
  MFS.write(tempo);  // escreve valor de tempo no mostrador da placa Shield Multi-funções
}

void loop() {

  // botão INICIAR
  if ( digitalRead(INICIAR) == 0 ) {
    // regra: tempo maior que 0
    while( tempo > 0 ) {
      
      tempo -= 1;  // subtrai uma unidade por vez
      MFS.write(tempo); // escreve valor de tempo no mostrador da placa Shield Multi-funções
      delay(1000); // esperar
    }
    MFS.beep(100); // aciona a buzina ao final do laço "while( tempo > 0 )"
  }

  // botão AUMENTA
  while ( digitalRead(AUMENTA) == 0 ) {
    // regra: tempo menor que 1000
    if (tempo < 1000) {
      tempo += 10; // soma no contador
      MFS.write(tempo); // escreve valor de tempo no mostrador da placa Shield Multi-funções
      delay(100); // esperar
    }
  }

  // botão DIMINUI
  while( digitalRead(DIMINUI) == 0) {
    // regra: tempo maior ou igual a 10
    if (tempo >= 10) {
      tempo -= 10; // subtrai do contador
      MFS.write(tempo); // escreve valor de tempo no mostrador da placa Shield Multi-funções
      delay(100); // esperar
    }
  }
  
}
/*
  O uso do "while" impossibilita o uso de mais de um botão ao mesmo tempo,
  pois enquanto pressionado ou preso a regra, "while" sempre se repetira
*/