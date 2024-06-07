const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledGreen = 12;
const int ledRed = 13;

long duration;
float distance;
float previousDistance = -1; // Valor inicial impossível para garantir detecção na primeira leitura
const float threshold = 10.0; // Threshold de variação em cm
unsigned long lastMeasure = 0;
const unsigned long measureInterval = 1000L * 30; // 30 segundos em milissegundos

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  
  // Inicializar LEDs e buzzer como desligados
  digitalWrite(buzzer, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);

  Serial.println("Setup completo.");
}

void loop() {
  if (millis() - lastMeasure >= measureInterval) {
    lastMeasure = millis();
    measureWaterLevel();
  }
}

void measureWaterLevel() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; // Distância em cm

  Serial.print("Distância: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (previousDistance != -1) {
    float change = abs(distance - previousDistance);
    Serial.print("Mudança: ");
    Serial.print(change);
    Serial.println(" cm");

    if (change >= threshold) {
      Serial.println("Variação brusca detectada!");
      alert();
    } else {
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledRed, LOW);
    }
  } else {
    // Primeiro ciclo de medição
    digitalWrite(ledGreen, HIGH);
  }
  previousDistance = distance;
}

void alert() {
  for (int i = 0; i < 5; i++) { // Beep 5 vezes
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledRed, HIGH);
    delay(500);
    digitalWrite(buzzer, LOW);
    digitalWrite(ledRed, LOW);
    delay(500);
  }
}
