/*
    Display 7 seguimentos, contagem regressiva de 0 à 9.
    No Arduino podemos representar os números em binário iniciando seu valor com B
    Exemplo (Display 7 seguimentos):
    B,PONTO,SEG_G,SEG_F,SEG_E,SEG_D,SEG_C,SEG_B,SEG_A
    B   0     0     0     0     0     0     0     0
*/

// #define => Constante
#define SEG_A 2 // definir pino "2" Arduino (apelidar de SEG_A)
#define SEG_B 3 // definir pino "3" Arduino (apelidar de SEG_B)
#define SEG_C 4 // definir pino "4" Arduino (apelidar de SEG_C)
#define SEG_D 5 // definir pino "5" Arduino (apelidar de SEG_D)
#define SEG_E 6 // definir pino "6" Arduino (apelidar de SEG_E)
#define SEG_F 7 // definir pino "7" Arduino (apelidar de SEG_F)
#define SEG_G 8 // definir pino "8" Arduino (apelidar de SEG_G)
#define PONTO 9 // definir pino "9" Arduino (apelidar de PONTO)

// lista de números binários de 0 à 9 (tipo int)
int mapaDisplay[] = {
  B00111111, B00000110, B01011011, B01001111,
  B01100110, B01101101, B01111100, B00000111,
  B01111111, B01100111
};

// função mostra número
void mostrarNumero(int numero) {
  
  int mapa = mapaDisplay[numero];
  int bitAtual = B00000001;
  
  // Testa e (acender pino 2 à 8 Arduino)
  for (int i = 2; i <= 8; i++) {
    int acender = mapa & bitAtual; //(CALCULO PARA TESTE)
    digitalWrite(i, acender); // acender pino (SIM ou NÃO)
    bitAtual = bitAtual << 1; // desloca digito "1" para esquerda (NOVO TESTE)
  }

  /*
    (CALCULO PARA TESTE)
    B00000110 <= mapa
  & B00000001 <= bitAtual
    ---------
    B00000000 = 0 em decimal

  	(NOVO TESTE)
    B00000110 <= mapa
  & B00000010 <= bitAtual
    ---------
    B00000010 = 1 em decimal
  */ 
}

void setup(){
  pinMode(SEG_A, OUTPUT); // pino(porta, saída)
  pinMode(SEG_B, OUTPUT); // pino(porta, saída)
  pinMode(SEG_C, OUTPUT); // pino(porta, saída)
  pinMode(SEG_D, OUTPUT); // pino(porta, saída)
  pinMode(SEG_E, OUTPUT); // pino(porta, saída)
  pinMode(SEG_F, OUTPUT); // pino(porta, saída)
  pinMode(SEG_G, OUTPUT); // pino(porta, saída)
  // mostrarNumero(7); // (teste direto) 
}

void loop(){  
  for (int i = 0; i <= 9; i++) {
  	mostrarNumero(i);
  	delay(1000);
  }
}
