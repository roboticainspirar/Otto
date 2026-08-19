#include <Servo.h>

// Criação dos objetos para os 4 motores do Otto
Servo pernaEsquerda;
Servo pernaDireita;
Servo peEsquerdo;
Servo peDireito;

void setup() {
  // Conecte os pinos de sinal (fio laranja/amarelo) nestas portas
  pernaEsquerda.attach(2);
  pernaDireita.attach(3);
  peEsquerdo.attach(4);
  peDireito.attach(5);

  // Centraliza todos os motores em 90 graus simultaneamente
  pernaEsquerda.write(90);
  pernaDireita.write(90);
  peEsquerdo.write(90);
  peDireito.write(90);
}

void loop() {
  // O loop fica vazio. Os motores ficarão travados em 90 graus 
  // enquanto a placa estiver ligada para você encaixar as peças.
}
