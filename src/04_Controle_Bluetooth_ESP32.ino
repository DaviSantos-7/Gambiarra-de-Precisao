#include "BluetoothSerial.h"

// Verifica se o Bluetooth está habilitado no ESP32
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth não está habilitado!
#endif

BluetoothSerial SerialBT;

// Pinos da TRAÇÃO (Motor traseiro)
const int IN1 = 21;
const int IN2 = 22;
const int ENA = 23;

// Pinos da DIREÇÃO (Motor dianteiro com sistema de molas)
const int IN3 = 25;
const int IN4 = 26;
const int ENB = 27;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("O_Rei_BT"); 
  Serial.println("Bluetooth iniciado! O dispositivo 'O_Rei_BT' está pronto.");

  // Configuração dos pinos
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Inicia tudo desligado
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

// ==========================================
// FUNÇÕES DE MOVIMENTO (POTÊNCIA MÁXIMA FIXA)
// ==========================================
void frente() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255); // 100% de potência
}

void re() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 255); // 100% de potência
}

void pararTracao() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

void esquerda() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255); // 100% de força para virar
}

void direita() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, 255); // 100% de força para virar
}

void pararDirecao() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

// ==========================================
// LOOP PRINCIPAL (CONTROLE BLUETOOTH)
// ==========================================
void loop() {
  while (SerialBT.available() > 0) {
    char comando = SerialBT.read(); 

    // Movimentos Retos
    if (comando == 'F') { 
      frente();
      pararDirecao(); // Garante que a roda fique reta se for só pra frente
    } 
    else if (comando == 'B') { 
      re();
      pararDirecao();
    } 
    else if (comando == 'L') { 
      esquerda(); 
    } 
    else if (comando == 'R') { 
      direita();
    } 

    // Movimentos Diagonais (Essenciais para o Joystick do app)
    else if (comando == 'G') { // Frente + Esquerda
      frente();
      esquerda();
    }
    else if (comando == 'H') { // Frente + Direita
      frente();
      direita();
    }
    else if (comando == 'I') { // Ré + Esquerda
      re();
      esquerda();
    }
    else if (comando == 'J') { // Ré + Direita
      re();
      direita();
    }

    // Parada Geral
    else if (comando == 'S') { // Soltou a tela do app
      pararTracao();
      pararDirecao();
    }
  }
}
