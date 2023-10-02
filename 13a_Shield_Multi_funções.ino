/*
    * Shield Multi-funções:
    * LED liga em nível logico baixo.

    LED`s piscam conforme valor do potenciômetro na porta A0
*/

#define LED1 10  // definir pino "10" Arduino (apelidar de LED1)
#define LED2 11  // definir pino "11" Arduino (apelidar de LED2)
#define LED3 12  // definir pino "12" Arduino (apelidar de LED3)
#define LED4 13  // definir pino "13" Arduino (apelidar de LED4)

int vel;  // variável

void setup() {
  pinMode(LED1, OUTPUT);  // pino(porta, saída)
  pinMode(LED2, OUTPUT);  // pino(porta, saída)
  pinMode(LED3, OUTPUT);  // pino(porta, saída)
  pinMode(LED4, OUTPUT);  // pino(porta, saída)
  
  pinMode(A0, INPUT);  // pino(porta, entrada)

  Serial.begin(9600);  // habilitar monitor serial
}

void loop() {
  vel = analogRead(A0);  // leitura analógica no pino A0 (potenciômetro)
  Serial.println(vel);  // imprimir valor no monitor serial

  digitalWrite(LED1, LOW);  // ligar LED
  digitalWrite(LED2, HIGH); // desligar LED
  digitalWrite(LED3, LOW);  // ligar LED
  digitalWrite(LED4, HIGH); // desligar LED
  delay(vel);  // esperar
  
  digitalWrite(LED1, HIGH);  // desligar LED
  digitalWrite(LED2, LOW);   // ligar LED
  digitalWrite(LED3, HIGH);  // desligar LED
  digitalWrite(LED4, LOW);   // ligar LED
  delay(vel);  // esperar
}
