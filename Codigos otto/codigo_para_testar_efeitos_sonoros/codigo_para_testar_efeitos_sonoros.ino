const int buzzer = 7;

void setup() {
  pinMode(buzzer, OUTPUT);
  
  // Executa os sons uma vez para demonstração
  somFeliz();
  delay(1000);
  
  somTriste();
  delay(1000);
  
  somAlerta();
}

void loop() {
  // Deixamos vazio para não ficar repetindo sem parar.
  // Você pode propor que os alunos coloquem botões no loop 
  // para acionar cada som depois!
}

// --- Funções customizadas de som ---

void somFeliz() {
  // Frequências subindo rapidamente = alegria/sucesso
  tone(buzzer, 1500, 200); delay(250);
  tone(buzzer, 2000, 200); delay(250);
  tone(buzzer, 2500, 300); delay(300);
}

void somTriste() {
  // Frequências caindo e lentas = tristeza/falha
  tone(buzzer, 900, 300); delay(350);
  tone(buzzer, 700, 300); delay(350);
  tone(buzzer, 500, 500); delay(500);
}

void somAlerta() {
  // Frequências alternando rápido = sirene/perigo
  for(int i = 0; i < 3; i++) {
    tone(buzzer, 2000, 100); delay(150);
    tone(buzzer, 1000, 100); delay(150);
  }
}
