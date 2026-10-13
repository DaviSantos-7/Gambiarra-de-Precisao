// 04_Teste_Direcao_ESP32
//Motor da direção gira para um lado e outro

// TRAÇÃO
const int IN1 = 21;
const int IN2 = 22;
const int ENA = 23;

// DIREÇÃO
const int IN3 = 25;
const int IN4 = 26;
const int ENB = 27;

void setup() {
  // Pinos da TRAÇÃO
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Pinos da DIREÇÃO
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Tudo começa parado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

// DIREÇÃO PARA UM LADO
void esquerda(int velocidade) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, velocidade);
}

// DIREÇÃO PARA O OUTRO LADO
void direita(int velocidade) {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, velocidade);
}

// PARA O MOTOR DA DIREÇÃO
void pararDirecao() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}


void loop() {
  // Teste para um lado
  esquerda(100);
  delay(1000);

  pararDirecao();
  delay(1000);

  // Teste para o outro lado
  direita(100);
  delay(1000);

  pararDirecao();
  delay(2000);
}
