#include <Servo.h>

// Pinos dos motores
Servo pernaEsquerda; // Pino 2
Servo pernaDireita;  // Pino 3
Servo peEsquerdo;    // Pino 4
Servo peDireito;     // Pino 5

// Pino do som
const int buzzer = 7;

// Frequências para o ritmo e melodia
#define BUM 150       // Som grave simulando a batida do pé no chão
#define CLAP 600      // Som agudo simulando a palma
#define NOTA_MI 330
#define NOTA_RE 294
#define NOTA_DO 261

void setup() {
  pernaEsquerda.attach(2);
  pernaDireita.attach(3);
  peEsquerdo.attach(4);
  peDireito.attach(5);
  pinMode(buzzer, OUTPUT);

  // Centraliza o robô antes de começar o show
  centralizar();
  delay(2000); 
}

void loop() {
  // Faz o ritmo famoso: Tum, Tum, Pá! (Repete 2 vezes)
  batidaRock();
  batidaRock();
  
  // Toca o refrão enquanto mexe o corpo
  tocarMelodia();
  
  delay(1500); // Pausa para os aplausos antes de repetir
}

// --- FUNÇÕES DE MOVIMENTO E SOM ---

void centralizar() {
  pernaEsquerda.write(90);
  pernaDireita.write(90);
  peEsquerdo.write(90);
  peDireito.write(90);
}

void batidaRock() {
  // PISA O PÉ ESQUERDO (BUM)
  peEsquerdo.write(120); // Levanta
  tone(buzzer, BUM, 150);
  delay(200);
  peEsquerdo.write(90);  // Pisa
  delay(200);

  // PISA O PÉ DIREITO (BUM)
  peDireito.write(60);   // Levanta
  tone(buzzer, BUM, 150);
  delay(200);
  peDireito.write(90);   // Pisa
  delay(200);

  // PALMA (CLAP) - O robô abre e fecha as pernas
  pernaEsquerda.write(110);
  pernaDireita.write(70);
  tone(buzzer, CLAP, 200);
  delay(300);
  
  // Volta ao centro
  centralizar();
  delay(300);
}

void tocarMelodia() {
  // "We will, we will..."
  peEsquerdo.write(110);
  tone(buzzer, NOTA_MI, 300);
  delay(400);
  
  peDireito.write(70);
  tone(buzzer, NOTA_MI, 300);
  delay(400);
  
  peEsquerdo.write(90);
  tone(buzzer, NOTA_MI, 300);
  delay(400);
  
  peDireito.write(90);
  tone(buzzer, NOTA_MI, 300);
  delay(400);
  
  // "Rock..." (Robô balança)
  pernaEsquerda.write(110);
  pernaDireita.write(70);
  tone(buzzer, NOTA_RE, 300);
  delay(400);
  
  // "...You!" (Robô volta ao centro)
  centralizar();
  tone(buzzer, NOTA_DO, 500);
  delay(600);
}
