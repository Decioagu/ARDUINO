/*
    Display duplo de 7 seguimentos de 0 à 99.
    Com três botões de comando (iniciar / zerar), subtrair e somar contagem.
    No Arduino podemos representar os números em binário iniciando seu valor com "B".
    Exemplo (Display 7 seguimentos):
    B,PONTO,SEG_G,SEG_F,SEG_E,SEG_D,SEG_C,SEG_B,SEG_A
    B,0    ,0    ,0    ,0    ,0    ,0    ,0    ,0

    "Inicie contagem e zere contagem" do display pressionando botão no "pino digital 11" do Arduino
    "Avance contagem" do display pressionando o botão no "pino digital 1" do Arduino
    "Retorne contagem" do display pressionando o botão no "pino digital 0" do Arduino
*/

// -------------------------------------------------------------------------------------------------------- (1)

#define BOTAO_SUBTRAIR 0 // definir pino "0" Arduino (apelidar de BOTAO_SUBTRAIR)
#define BOTAO_SOMAR 1 // definir pino "1" Arduino (apelidar de BOTAO_SOMAR)

#define SEG_A 2 // definir pino "2" Arduino (apelidar de SEG_A)
#define SEG_B 3 // definir pino "3" Arduino (apelidar de SEG_B)
#define SEG_C 4 // definir pino "4" Arduino (apelidar de SEG_C)
#define SEG_D 5 // definir pino "5" Arduino (apelidar de SEG_D)
#define SEG_E 6 // definir pino "6" Arduino (apelidar de SEG_E)
#define SEG_F 7 // definir pino "7" Arduino (apelidar de SEG_F)
#define SEG_G 8 // definir pino "8" Arduino (apelidar de SEG_G)

#define DEZENA 9 // definir pino "9" Arduino (apelidar de DEZENA)
#define UNIDADE 10 // definir pino "10" Arduino (apelidar de UNIDADE)

#define BOTAO_INICIAR 11 // definir pino "11" Arduino (apelidar de BOTAO_INICIAR)

#define LED 13 // definir pino "13" Arduino (apelidar de LED)

int contagem = 0; // variável global
int espera = 0; // variável global
bool ativo = false; // variável global

// lista de números binários de 0 à 9 (tipo int)
int mapaDisplay[] = {
  B00111111, B00000110, B01011011, B01001111,
  B01100110, B01101101, B01111100, B00000111,
  B01111111, B01100111
};

// -------------------------------------------------------------------------------------------------------- (6)

// função mostra número
void mostrarNumero(int numero) {
  
  // variáveis para controle
  int mapa = mapaDisplay[numero]; // (variável local)
  int bitAtual = B00000001; // (variável local)
   
  // Testa e (acender pino 2 à 8 Arduino)
  for (int i = 2; i <= 8; i++) {
    int acender = mapa & bitAtual; //(CALCULO PARA TESTE)
    digitalWrite(i, acender); // acender pino (SIM ou NÃO)
    bitAtual = bitAtual << 1; // desloca digito "1" para esquerda (para novo teste)
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

// -------------------------------------------------------------------------------------------------------- (5)

// função "mostrarDigito()" ocorre a cada 0,2s
void mostrarDigitos(int dezena, int unidade) { // dezena e unidade variável local
  // habilita display "UNIDADE" em envia número para função "mostrarNumero()"
  digitalWrite(UNIDADE, HIGH); // habilita
  digitalWrite(DEZENA, LOW); // desabilita
  mostrarNumero(unidade); // envia valor numérico a função
  delay(100); // "espera"
  
  digitalWrite(UNIDADE, LOW); // desabilita
  digitalWrite(DEZENA, HIGH); // habilita
  mostrarNumero(dezena); // envia valor numérico a função
  delay(100); // "espara"
  
}

// -------------------------------------------------------------------------------------------------------- (4)

void contar(){
    /*
      A função "mostrarDigitos()" demora 0,2s para ocorrer.
      A variável espera incrementa variável "contagem" após 5 incremento.
      Resumindo matematicamente 0,2 * 5 = 1s
      Após 1s ocorre incremento "contagem"
    */
    if (espera == 5) {
      contagem++;
      espera = 0;
    }
   
    espera++;// artificio "delay" para função "mostrarDigitos()"

    int div_inteiro = contagem / 10; // extrai dezena do número inteiro (variável local)
    int div_resto = contagem % 10; // extrai unidade do número inteiro (variável local)
  
    mostrarDigitos(div_inteiro, div_resto); // (div_inteira = dezena , div_resto = unidade)
    
    // quando contado atinge 99, retorna a 0, pois projeto possui apenas 2 display
    if (contagem == 99 || contagem < 0) {
      digitalWrite(UNIDADE, LOW); // display apaga
      digitalWrite(DEZENA, LOW); // display apaga
      contagem = 0; // zera contagem
      digitalWrite(LED, HIGH); // liga LED
      delay(3000); // delay 3s
      digitalWrite(LED, LOW); // apaga LED
    }
}

// -------------------------------------------------------------------------------------------------------- (2)

void setup(){
  /*  INPUT_PULLUP é um modo de pino digital no Arduino que usa um resistor interno para puxar o pino 
      para a tensão de alimentação alto (HIGH) quando não está conectado a nada. Isso permite que você use um botão 
      para nível logico baixo (LOW) e controlar alguma condição.
  */
  pinMode(BOTAO_SUBTRAIR, INPUT_PULLUP);  // pino(porta, entrada)
  pinMode(BOTAO_SOMAR, INPUT_PULLUP);     // pino(porta, entrada)
  pinMode(BOTAO_INICIAR, INPUT_PULLUP);   // pino(porta, entrada)

  pinMode(SEG_A, OUTPUT); // pino(porta, saída)
  pinMode(SEG_B, OUTPUT); // pino(porta, saída)
  pinMode(SEG_C, OUTPUT); // pino(porta, saída)
  pinMode(SEG_D, OUTPUT); // pino(porta, saída)
  pinMode(SEG_E, OUTPUT); // pino(porta, saída)
  pinMode(SEG_F, OUTPUT); // pino(porta, saída)
  pinMode(SEG_G, OUTPUT); // pino(porta, saída)

  pinMode(DEZENA, OUTPUT); // pino(porta, saída)
  pinMode(UNIDADE, OUTPUT); // pino(porta, saída) 
  pinMode(LED, OUTPUT); // pino(porta, saída) 
}

// -------------------------------------------------------------------------------------------------------- (3)

void loop(){
  // aciona um botão por vez
  if (digitalRead(BOTAO_SUBTRAIR) == 0){ // subtrai contagem ao pressionar botão
      contagem--; // subtrai 1 da contagem
      // trava estado do botão quando pressionado
      while (digitalRead(BOTAO_SUBTRAIR) == 0){} // não faz nada
  } else if (digitalRead(BOTAO_SOMAR) == 0){ // soma contagem ao pressionar botão
      contagem++; // soma 1 da contagem
      // trava estado do botão quando pressionado
      while (digitalRead(BOTAO_SOMAR) == 0){} // não faz nada
  } else if (digitalRead(BOTAO_INICIAR) == 0){ // zera contagem e inicia programação toda vez que botão é pressionado
      contagem = 0; // inicio da contagem
      ativo = !ativo; // altera condição verdadeiro e falso com botão apertado

  // trava estado do botão quando pressionado
  while (digitalRead(BOTAO_INICIAR) == 0){} // não faz nada

  digitalWrite(UNIDADE, LOW); // display apaga
  digitalWrite(DEZENA, LOW); // display apaga
}

  // quando variável ("ativo" = verdade) inicia contagem 
  if (ativo){
    contar(); // inicia contagem
  }
}
