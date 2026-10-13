//CODIGO Teste_PonteH_ESP32
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

// Função para movimentar o motor para FRENTE
void frente(int velocidade) { //"velocidade" recebe um valor de 0 a 255
  digitalWrite(IN1, HIGH); //indicar FRENTE.
  digitalWrite(IN2, LOW);
  analogWrite(ENA, velocidade); //valor que colocamos nele vem da variável velocidade
}

// Função para movimentar o motor para TRAS
void re(int velocidade) { // "velocidade" recebe um valor de 0 a 255
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, velocidade);
}

void parar() { //não precisamos informar uma velocidade para PARAR
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0); //MOTOR PARADO
} 


void loop() {
  frente(120);
  delay(8000); //espera 2s

  parar(); //Chama função de parada.
  delay(1000);

  re(120);
  delay(8000);

  parar();
  delay(1000);
  }
