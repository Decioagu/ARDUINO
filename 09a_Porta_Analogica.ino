int sensorValue = 0; // variável 

void setup()
{
  // A0 = pino analógico
  pinMode(A0, INPUT);  // pino(porta, entrada)
  pinMode(LED_BUILTIN, OUTPUT);  // definir o pino LED= "L" embutido como uma saída.
  Serial.begin(9600); // print no monitor serial
}

void loop()
{
  /*
    A função retorna um valor inteiro entre 0 e 1023. 
    O valor 0 corresponde a uma tensão de 0 volts, e o valor 1023 corresponde a uma tensão de 5 volts
  */
  sensorValue = analogRead(A0); // ler a tensão de um sensor ou outro dispositivo analógico
  
  digitalWrite(LED_BUILTIN, HIGH); // ligar led embutido
  Serial.println(sensorValue); // print no monitor serial
  delay(sensorValue); // tempo varia conforme tensão da porta A0
 
  digitalWrite(LED_BUILTIN, LOW); // apagar led embutido
  Serial.println(sensorValue); // print no monitor serial
  delay(sensorValue); // tempo varia conforme tensão da porta A0
}