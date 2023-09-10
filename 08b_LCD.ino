/*
Biblioteca LiquidCrystal - Olá Mundo

    Demonstra o uso de um display LCD 16x2.
   A biblioteca LiquidCrystal funciona com todos os LCD
   monitores compatíveis com o Hitachi
   Interface de 16 pinos.

   Este esboço imprime "Hello World!" para o LCD
   e mostra a hora.

  O circuito:
   * LCD RS pino para pino digital 12 (Arduino)
   * LCD E (habilita) pino para pino digital 11 (Arduino)
   * LCD D4 pino para pino digital 5 (Arduino)
   * LCD D5 pino para pino digital 4 (Arduino)
   * LCD D6 pino para pino digital 3 (Arduino)
   * LCD D7 pino para pino digital 2 (Arduino)
   * Pino R/W do LCD ao GND (Arduino)
   * LCD VSS pino para GND (Arduino)
   * Pino VCC LCD para 5V
   * limpador no pino VO do LCD (pino 3)
*/

#include <LiquidCrystal.h>

/*
  biblioteca variável(parâmetros)
  LiquidCrystal LCD(12, 11, 5, 4, 3, 2);
  LiquidCrystal LCD(RS,  E, Dado, Dado, Dado, Dado);
*/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // definição do LCD: inicializará um LCD de 16x2
  LCD.begin(16, 2); // LCD.begin(coluna, linha)
  
  lcd.print("Decio Santana de Aguiar"); // mensagem
}

void loop() {
  /*
    i = 7
    Display com 16 carácter.
    Nome "Decio Santana de Aguiar" = 23 carácter
    movimentar 7 carácter com delay de 0,5s
  */
  delay(1000);
  for(int i=0; i < 7; i++){
    lcd.scrollDisplayLeft(); // movimenta texto para esquerda
    delay(500);
  }
  delay(1000);
  for(int i=0; i < 7; i++){
    lcd.scrollDisplayRight(); // movimenta texto para direita
    delay(500);
  }
}