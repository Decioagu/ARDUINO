/*
  Biblioteca LiquidCrystal

  Demonstra o uso de um display LCD 16x2.
  Digite qualquer letra em qualquer posição do display LCD 16x2
  utilizando os botões CIMA, BAIXO, ESQUERDA, DIREITA, ESPAÇO.
*/

#include <LiquidCrystal.h>  // blibioteca LCD
#define BTN_CIMA 4 // definir pino "4" Arduino (apelidar de BTN_CIMA)
#define BTN_BAIXO 3 // definir pino "3" Arduino (apelidar de BTN_BAIXO)
#define BTN_DIREITA 2 // definir pino "5" Arduino (apelidar de BTN_DIREITA)
#define BTN_ESQUERDA 5 // definir pino "2" Arduino (apelidar de BTN_ESQUERDA)
#define BTN_ESPACO 1 // definir pino "1" Arduino (apelidar de BTN_ESPACO)

int letra = 64;  // variável (contador)
int coluna = 0;  // variável (marca valor posição coluna)
int linha = 0;   // variável (marca valor posição linha)

/*
  biblioteca variável(parâmetros)
  LiquidCrystal lcd(6, 7, 8, 9, 10, 11);
  LiquidCrystal LCD(RS,  E, Dado, Dado, Dado, Dado);
*/
LiquidCrystal lcd(6, 7, 8, 9, 10, 11); // nomeia e instanciar LCD a ser utilizado

void setup()
{
  lcd.begin(16, 2); // LCD.begin(coluna, linha)

  pinMode(BTN_CIMA, INPUT_PULLUP); // pino(porta, entrada)
  pinMode(BTN_BAIXO, INPUT_PULLUP); // pino(porta, entrada)
  pinMode(BTN_DIREITA, INPUT_PULLUP); // pino(porta, entrada)
  pinMode(BTN_ESQUERDA, INPUT_PULLUP); // pino(porta, entrada)
  pinMode(BTN_ESPACO, INPUT_PULLUP); // pino(porta, entrada)

  lcd.blink(); // pisca cursor na posição atual
  
  lcd.setCursor(coluna, linha); // inicio de posição do cursor ao iniciar loop
}

// função paraCima() inicia pela letra alfabética 'A'
void paraCima() {
  letra++; // soma do valor numérico (contador)

 // ultrapassando limite máximo desejado da tabela ASCII
  if (letra > 90) {
    letra = 65; // retorna para 65 = 'A'
  }
  lcd.write(letra);  // converte valor numérico na tabela SACII
  posicao();  // função posição   
}

// função paraBaixo() retorna letra alfabética a partir da atual
void paraBaixo() { 
  letra--; // subtração do valor numérico (contador)

  // ultrapassando limite mínimo desejado da tabela ASCII
  if (letra < 65) {
    letra = 90; // retorna para 90 = 'Z'
  }
  lcd.write(letra); // converte valor numérico na tabela SACII
  posicao(); // função posição   
}

// função posição() ajusta (coluna e linha) conforme valores numérico
void posicao() {
  lcd.setCursor(coluna, linha); 
}

void loop() {

  // acionamento dos botões BTN_CIMA / BTN_BAIXO / BTN_DIREITA / BTN_ESQUERDA / BTN_ESPACO
  if (digitalRead(BTN_CIMA) == 0) {
    paraCima(); // função paraCima
    while (digitalRead(BTN_CIMA) == 0){}  // loop vazio enquanto botão estiver pressionado

  } else if ( digitalRead(BTN_BAIXO) == 0 ) {
    paraBaixo(); // função paraBaixo
    while (digitalRead(BTN_BAIXO) == 0){}  // loop vazio enquanto botão estiver pressionado

  } else if (digitalRead(BTN_DIREITA) == 0) {   
    coluna++; // (marcador) soma valor da coluna para deslocar a direita

    // ao atingir limite do mostrador posiciona cursor em posição predeterminado 
    if (coluna == 16 && linha == 0) {
      coluna = 0;
      linha = 1;
    } else  if (coluna == 16 && linha == 1) {
      coluna = 0;  
      linha = 0;
    }
    posicao(); // função posição
    while (digitalRead(BTN_DIREITA) == 0){}  // loop vazio enquanto botão estiver pressionado

  } else if (digitalRead(BTN_ESQUERDA) == 0) {
    coluna--; // (marcador) subtrai valor da coluna para deslocar a esquerda

    // ao atingir limite do mostrador posiciona cursor em posição predeterminado 
    if (coluna < 0 && linha == 0) {
      coluna = 15;  
      linha = 1;
    } else  if (coluna < 0 && linha == 1) {
      coluna = 15;  
      linha = 0;
    }
    posicao(); // função posição
    while (digitalRead(BTN_ESQUERDA) == 0){}  // loop vazio enquanto botão estiver pressionado

  } else if ( digitalRead(BTN_ESPACO) == 0 ) {
    lcd.write(' ');  // adiciona espaço na posição atual do cursor
    while (digitalRead(BTN_ESPACO) == 0){}  // loop vazio enquanto botão estiver pressionado
    posicao(); // função posição
  }
}