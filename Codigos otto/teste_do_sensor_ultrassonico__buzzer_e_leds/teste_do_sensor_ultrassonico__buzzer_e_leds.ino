const int pinoTrig = 8;
const int pinoEcho = 9;
const int ledVerde = 10;
const int ledAmarelo = 11;
const int ledVermelho = 12;
const int buzzer = 7;

void setup() {
  Serial.begin(9600); // Para os alunos verem a distância no Monitor Serial
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // Dispara o pulso sonoro
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  // Calcula a distância em centímetros
  long duracao = pulseIn(pinoEcho, HIGH);
  int distancia = duracao * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Lógica de Decisão do Robô
  if (distancia > 50) {
    // Caminho livre
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  } 
  else if (distancia >= 15 && distancia <= 50) {
    // Atenção, obstáculo se aproximando
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    noTone(buzzer);
  } 
  else if (distancia < 15) {
    // Risco de colisão! O Otto precisaria virar
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    tone(buzzer, 1000); // Dispara o alarme
  }

  delay(100); // Pequena pausa para estabilizar a leitura
}
