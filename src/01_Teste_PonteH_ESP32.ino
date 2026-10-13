//CODIGO TESTE DA PONTE H
//IN1 e IN2 determinam o SENTIDO DE ROTACAO
const int IN1 = 21;
const int IN2 = 22;
const int ENA = 23; // CONTROLE DE VELOCIDADE DO PWM (0 é o motor parado e 255 max)

void setup() {
//ajuda a definir o sentido do motor.
  pinMode(IN1, OUTPUT); //saidas digitais
  pinMode(IN2, OUTPUT); //define o outro sentido.
  pinMode(ENA, OUTPUT); //controla a velocidade através do PWM.

  // Começa parado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

void loop() {
  // FRENTE
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

//acelera gradualmente
  for (int i = 0; i <= 255; i++) { 
    analogWrite(ENA, i);
    delay(30);
  }

  // =========================
  // DIMINUI A VELOCIDADE
  for (int i = 255; i >= 0; i--) {
    analogWrite(ENA, i);
    delay(30);
  }

  // Motor totalmente parado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  delay(100);

  // =========================
  // RÉ para INVERTER  o SENTIDO

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  for (int i = 0; i <= 255; i++) {
    analogWrite(ENA, i);
    delay(30);
  }

  // =========================
  // DIMINUI A VELOCIDADE
  for (int i = 255; i >= 0; i--) {
    analogWrite(ENA, i);
    delay(30);
  }

  // Motor parado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  delay(100);
}
