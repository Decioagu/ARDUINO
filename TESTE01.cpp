#include <Arduino.h> 

// MOTOR 1
#define EN1 4
#define IN1 3
#define IN2 2

// MOTOR 2
#define EN2 7
#define IN3 6
#define IN4 5

void setup() {
  pinMode(EN1, OUTPUT);  // pino(porta, entrada)
  pinMode(IN1, OUTPUT);  // pino(porta, entrada)
  pinMode(A0, OUTPUT);  // pino(porta, entrada)
  pinMode(A0, OUTPUT);  // pino(porta, entrada)
  pinMode(A0, OUTPUT);  // pino(porta, entrada)
  pinMode(A0, OUTPUT);  // pino(porta, entrada) 
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