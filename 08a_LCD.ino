/*
  Biblioteca LiquidCrystal

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

#include <LiquidCrystal.h>  // blibioteca LCD

int contador = 0;

/*
  biblioteca variável(parâmetros)
  LiquidCrystal LCD(12, 11, 5, 4, 3, 2);
  LiquidCrystal LCD(RS,  E, Dado, Dado, Dado, Dado);
*/
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // nomeia e instanciar LCD a ser utilizado

void setup()
{
  // definição do LCD: inicializará um LCD de 16x2
  lcd.begin(16, 2); // LCD.begin(coluna, linha)

  // será exibido na primeira linha
  lcd.write('T');
  delay(500);
  lcd.write('E');
  delay(500);
  lcd.write('S');
  delay(500);
  lcd.write('T');
  delay(500);
  lcd.write('E');
  delay(2000);
  lcd.setCursor(4,0);
  lcd.clear(); // apagar

  lcd.print("Codigo ASCII=>"); // printa texto
   delay(2000);
  lcd.setCursor(15,0); // posiciona proximo carácter a ser exibido "LCD.setCursor(coluna, linha)"
  lcd.write(65); // utilizando LCD.write(65) = 'A' no código ASCII
   delay(2000);
  lcd.clear(); // apagar


  lcd.print("Seja bem vindo!!!");
  delay(3000);
  lcd.clear();
  lcd.print("Ola mundo!"); // print mensagem
  lcd.setCursor(6,1); // posiciona proximo carácter a ser exibido "LCD.setCursor(coluna, linha)"
  lcd.print("<=CONTAGEM"); // print mensagem
  
}

void loop()
{
/*
  Em um display de cristal líquido (LCD), setCursor é uma função que é usada para posicionar o 
  cursor na tela. O cursor é um indicador que mostra onde o próximo caractere será exibido.
*/
  lcd.setCursor(0, 1); // LCD.setCursor(coluna, linha)
  
  lcd.print(contador); // contador
  delay(1000); // espera
  contador += 1; // soma contador
}