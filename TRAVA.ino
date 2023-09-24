#include <LiquidCrystal.h>  // blibioteca LCD

#define RELER_TRAVA A0	// definir pino "A0" Arduino (apelidar de RELER_TRAVA)
#define BT_BALANCA A1   // definir pino "A1" Arduino (apelidar de BTN_CIMA)
#define BT_CHAVE A2     // definir pino "A2" Arduino (apelidar de BTN_BAIXO)

#define LED_VERDE 3     // definir pino "3" Arduino (apelidar de BTN_BAIXO)
#define LED_AMARELO 2   // definir pino "2" Arduino (apelidar de BTN_BAIXO)
#define LED_VERMELHO 1  // definir pino "1" Arduino (apelidar de BTN_BAIXO)

int contador = 5;  // variável
bool trava_ativa = false; // variável (trava desligada)

/*
  biblioteca variável(parâmetros)
  LiquidCrystal lcd(6, 7, 8, 9, 10, 11);
  LiquidCrystal LCD(RS,  E, Dado, Dado, Dado, Dado);
*/
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

void setup()
{
    lcd.begin(16, 2); // LCD.begin(coluna, linha)

    pinMode(BT_BALANCA, INPUT); // pino(porta, entrada)
    pinMode(BT_CHAVE, INPUT);   // pino(porta, entrada)

    pinMode(LED_VERDE, OUTPUT);     // pino(porta, entrada)
    pinMode(LED_AMARELO, OUTPUT);   // pino(porta, entrada)
    pinMode(LED_VERMELHO, OUTPUT);  // pino(porta, entrada)

    // condição inicial dos LED`s
    digitalWrite(LED_VERDE, 1);     // LED VERDE aceso
    digitalWrite(LED_AMARELO, 0);   // LED AMARELO apagado
    digitalWrite(LED_VERMELHO, 0);  // LED VERMELHO apagado
  
}

// função trava() regra de acionamento
void trava() {
  // contagem de acionamento
  while (digitalRead(BT_BALANCA) == 1 && digitalRead(BT_CHAVE) == 1)
  {
      lcd.clear(); // limpara mostrador
      lcd.setCursor(5,0); // posição do cursor
      lcd.print("CUIDADO!!!"); // print mensagem
      lcd.setCursor(0, 1); // posição do cursor
      lcd.print(contador); // print mensagem
      lcd.setCursor(5,1); // posição do cursor
      lcd.print("<=CONTAGEM"); // print mensagem    
      digitalWrite(LED_VERDE, 0);     // LED VERDE apagado
      digitalWrite(LED_AMARELO, 1);   // LED AMARELO aceso
      digitalWrite(LED_VERMELHO, 0);  // LED VERMELHO apagado
      delay(500); // espera
      digitalWrite(LED_AMARELO, 0); // LED AMARELO apagado
      delay(500); // espera
      contador--; // subtração contador (contagem regraciava)

      // quando contador igual a zero
      if (contador == 0){
        trava_ativa = true; // variável (trava ligada)
      }
    
      // acionamento da trava
      while (trava_ativa)
      {
          lcd.clear(); // limpar LCD
          lcd.setCursor(3,0); 
          lcd.print("TRAVA ATIVADA!"); // print mensagem
          lcd.setCursor(0, 1); // LCD.setCursor(coluna, linha)
          lcd.print(contador); // contador
          lcd.setCursor(5,1); // posiciona proximo carácter a ser exibido "LCD.setCursor(coluna, linha)"
          lcd.print("<=CONTAGEM"); // print mensagem
          digitalWrite(LED_VERDE, 0);     // LED VERDE apagado
          digitalWrite(LED_AMARELO, 0);   // LED AMARELO aceso
          digitalWrite(LED_VERMELHO, 1);  // LED VERMELHO apagado
          delay(1000); // espera

          // quado chave estiver proxima
          if(digitalRead(BT_CHAVE) == 0){
            trava_ativa = false; // variável (trava desligada)
          }

      }
 	}
 }
  
// loop infinito
void loop() {
    digitalWrite(LED_VERDE, 1);     // LED VERDE aceso
    digitalWrite(LED_AMARELO, 0);   // LED AMARELO apagado
    digitalWrite(LED_VERMELHO, 0);  // LED VERMELHO apagado
    lcd.clear(); // limpar LCD
    lcd.setCursor(5,0); // posição do cursor
    lcd.print("ALARME"); // print mensagem
    lcd.setCursor(5,1); // posição do cursor
    lcd.print("LIGADO"); // print mensagem
  	delay(1000); // espara
    trava(); // função trava()
  	contador = 5; // contador volta ter valor 5
}