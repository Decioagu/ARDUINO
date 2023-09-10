#include <LiquidCrystal.h>

int valor = 0; // variável
float tensao = 0.0; // variável

// LiquidCrystal lcd(RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(6, 7, 8, 9, 10, 11);

void setup() {
  // lcd.begin(Colunas, Linhas)
  lcd.begin(16, 2);  // LCD.begin(coluna, linha)
  pinMode(A0, INPUT);  // pino(porta, entrada)
  Serial.begin(9600); // print no monitor serial  
}

void loop() {
  valor = analogRead(A0);  // exibi valor numérico de 0 até 1023
  tensao = (valor/1023.0) * 5.0; // calculo para exibição da tensão
  lcd.clear(); // apagar
  lcd.print(valor); 
  lcd.setCursor(6,0); // posiciona proximo carácter a ser exibido "LCD.setCursor(coluna, linha)"
  lcd.print("<= VALOR"); // print mensagem
  lcd.setCursor(6,1); // posiciona proximo carácter a ser exibido "LCD.setCursor(coluna, linha)"
  lcd.print("<= TENSAO"); // print mensagem
  lcd.setCursor(0, 1); // posiciona proximo carácter a ser exibido "LCD.setCursor(coluna, linha)"
  lcd.print(tensao);
  delay(500);
}