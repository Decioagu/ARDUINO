/*
        A função millis() retorna o número de milissegundos que se passaram 
    desde que a placa Arduino começou a executar o programa atual.
        A função millis() é útil para medir intervalos de tempo curtos, 
    como a duração de um evento ou o tempo que um sensor leva para detectar uma mudança. 
        Também pode ser usada para gerar intervalos de tempo regulares, 
    como um temporizador de 1 segundo.
    
*/
#define LED1 1 // definir pino "1" Arduino (apelidar de LED1)
#define LED2 2 // definir pino "2" Arduino (apelidar de LED2)
#define LED3 3 // definir pino "3" Arduino (apelidar de LED1)
#define BTN 4  // definir pino "4" Arduino (apelidar de BTN)

// estado atual
int led1Estado = 0;  // variável
int led2Estado = 0;  // variável
int led3Estado = 0;  // variável
int estadoBtn = 0;  // variável

// funciona como contador
int led1TempoAnterior = 0;  // variável
int led2TempoAnterior = 0;  // variável

void setup() {
  pinMode(LED1, OUTPUT);  // pino(porta, saída)
  pinMode(LED2, OUTPUT);  // pino(porta, saída)
  pinMode(LED3, OUTPUT);  // pino(porta, saída)
  /*  INPUT_PULLUP é um modo de pino digital no Arduino que usa um resistor interno para puxar o pino 
      para a tensão de alimentação alto (HIGH) quando não está conectado a nada. Isso permite que você use um botão 
      para nível logico baixo (LOW) e controlar alguma condição.
  */
  pinMode(BTN, INPUT_PULLUP);  // pino(porta, entrada)
  
  Serial.begin(9600);  // ativa monitor serial
}

void loop() {
  
  if ( millis() - led1TempoAnterior >= 250 ) {
    // monitor serial
    Serial.print("Tempo atual LDE 1: ");
    Serial.println(led1TempoAnterior);

    led1TempoAnterior = millis();  // atualiza temporizador

    // monitor serial
    Serial.print("Tempo corrigido LDE 1: ");
    Serial.println(led1TempoAnterior);
    Serial.println("--------------------");

    led1Estado = !led1Estado;  // mudança de estado do LED
    digitalWrite(LED1, led1Estado);  // escreve no LED
    
  }
  
  if ( millis() - led2TempoAnterior >= 1000 ) {
    // monitor serial
    Serial.print("Tempo atual LDE 2: ");
    Serial.println(led2TempoAnterior);

    led2TempoAnterior = millis(); // atualiza temporizador

    // monitor serial
    Serial.print("Tempo corrigido LDE 2: ");
    Serial.println(led2TempoAnterior);
    Serial.println("==================");

    led2Estado = !led2Estado; // mudança de estado do LED
    digitalWrite(LED2, led2Estado); // escreve no LED
      
  }
  
  // quando BRN == 1, LED acende
  if ( digitalRead(BTN) != estadoBtn && estadoBtn == 1 ) {
    led3Estado = !led3Estado;  // mudança de estado do LED
    digitalWrite(LED3, led3Estado);  // escreve no LED
  } 
  estadoBtn = digitalRead(BTN); // ler estado do botão
  
  delay(1); // espera
  
}







