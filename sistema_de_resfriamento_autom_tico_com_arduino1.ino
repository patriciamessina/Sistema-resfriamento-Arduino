#define LM35PIN A0       // Pino analógico conectado ao LM35
#define POTPIN A1        // Pino analógico conectado ao potenciômetro
#define LEDPIN 8         // Pino digital conectado ao LED

void setup() {
  Serial.begin(9600);
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(LM35PIN); // Lê o valor do LM35
  float temperature = (sensorValue * 5.0 * 100.0) / 1024.0; // Converte o valor para temperatura em Celsius
  
  int potValue = analogRead(POTPIN); // Lê o valor do potenciômetro
  float targetTemp = map(potValue, 0, 1023, 25, 30); // Mapeia o valor do potenciômetro para um intervalo entre 20°C e 30°C

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.print(" °C, Temperatura alvo: ");
  Serial.print(targetTemp);
  Serial.println(" °C");

  if (temperature > targetTemp) {
    digitalWrite(LEDPIN, HIGH); // Aciona o LED
    Serial.println("LED aceso. Temperatura acima da temperatura alvo.");
  } else {
    digitalWrite(LEDPIN, LOW);  // Desliga o LED
    Serial.println("LED apagado. Temperatura abaixo da temperatura alvo.");
  }

  delay(2000); // Aguarda 2 segundos antes de fazer uma nova leitura
}
