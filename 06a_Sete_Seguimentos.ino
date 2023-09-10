/*
    Display 7 seguimentos, contagem regressiva de 0 à 9.
*/

// #define => Constante
#define SEG_A 2 // definir pino "2" Arduino (apelidar de SEG_A)
#define SEG_B 3 // definir pino "3" Arduino (apelidar de SEG_B)
#define SEG_C 4 // definir pino "4" Arduino (apelidar de SEG_C)
#define SEG_D 5 // definir pino "5" Arduino (apelidar de SEG_D)
#define SEG_E 6 // definir pino "6" Arduino (apelidar de SEG_E)
#define SEG_F 7 // definir pino "7" Arduino (apelidar de SEG_F)
#define SEG_G 8 // definir pino "8" Arduino (apelidar de SEG_G)

// função para digito 0
void mostrarZero() {
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, HIGH);  
  digitalWrite(SEG_F, HIGH);  
  digitalWrite(SEG_G, LOW);
}

// função para digito 1
void mostrarUm() {
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);  
  digitalWrite(SEG_F, LOW);  
  digitalWrite(SEG_G, LOW);
}

// função para digito 2
void mostrarDois() {
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, LOW);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, HIGH); 
  digitalWrite(SEG_F, LOW); 
  digitalWrite(SEG_G, HIGH);
}

// função para digito 3
void mostrarTres() {
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, LOW); 
  digitalWrite(SEG_F, LOW); 
  digitalWrite(SEG_G, HIGH);
}

// função para digito 4
void mostrarQuatro() {
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW); 
  digitalWrite(SEG_F, HIGH); 
  digitalWrite(SEG_G, HIGH);
}

// função para digito 5
void mostrarCinco() {
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, LOW); 
  digitalWrite(SEG_F, HIGH); 
  digitalWrite(SEG_G, HIGH);
}

// função para digito 6
void mostrarSeis() {
  digitalWrite(SEG_A, LOW);
  digitalWrite(SEG_B, LOW);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, HIGH); 
  digitalWrite(SEG_F, HIGH); 
  digitalWrite(SEG_G, HIGH);
}

// função para digito 7
void mostrarSete() {
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);  
  digitalWrite(SEG_F, LOW);  
  digitalWrite(SEG_G, LOW);
}

// função para digito 8
void mostrarOito() {
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, HIGH);
  digitalWrite(SEG_E, HIGH);  
  digitalWrite(SEG_F, HIGH);  
  digitalWrite(SEG_G, HIGH);
}

// função para digito 9
void mostrarNove() {
  digitalWrite(SEG_A, HIGH);
  digitalWrite(SEG_B, HIGH);
  digitalWrite(SEG_C, HIGH);
  digitalWrite(SEG_D, LOW);
  digitalWrite(SEG_E, LOW);  
  digitalWrite(SEG_F, HIGH);  
  digitalWrite(SEG_G, HIGH);
}

// ler um vez (definir condição de pino)
void setup(){
  pinMode(SEG_B, OUTPUT); // pino(porta, saída)
  pinMode(SEG_A, OUTPUT); // pino(porta, saída)
  pinMode(SEG_C, OUTPUT); // pino(porta, saída)
  pinMode(SEG_D, OUTPUT); // pino(porta, saída)
  pinMode(SEG_E, OUTPUT); // pino(porta, saída)
  pinMode(SEG_F, OUTPUT); // pino(porta, saída)
  pinMode(SEG_G, OUTPUT); // pino(porta, saída)
}

// loop infinito
void loop(){
  mostrarZero(); // chama função digito 0
  delay(1000); // esperar 1s
  mostrarUm(); // chama função digito 1
  delay(1000); // esperar 1s
  mostrarDois(); // chama função digito 2
  delay(1000); // esperar 1s
  mostrarTres(); // chama função digito 3
  delay(1000); // esperar 1s
  mostrarQuatro(); // chama função digito 4
  delay(1000); // esperar 1s
  mostrarCinco(); // chama função digito 5
  delay(1000); // esperar 1s
  mostrarSeis(); // chama função digito 6
  delay(1000); // esperar 1s
  mostrarSete(); // chama função digito 7
  delay(1000); // esperar 1s
  mostrarOito(); // chama função digito 8
  delay(1000); // esperar 1s
  mostrarNove(); // chama função digito 9
  delay(1000); // esperar 1s
}
