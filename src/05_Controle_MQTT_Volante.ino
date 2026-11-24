#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// ==========================================
// 1. CONFIGURACOES WI-FI E BROKER MQTT
const char* ssid = "A06 de Maria"; //rede
const char* password = "28282828"; //senha

const char* mqtt_server = "192.168.168.101"; //rede do lab
const int mqtt_port = 1883;

const char* topicoVolante = "dados_volante";
const int CAR_ID_ESPERADO = 1;

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long ultimaTentativaMQTT = 0;
bool mqttEstavaConectado = false;

// ==========================================
// 2. PINOS DOS MOTORES

// TRACAO - MOTOR TRASEIRO
const int IN1 = 21;
const int IN2 = 22;
const int ENA = 23;

// DIRECAO - MOTOR DIANTEIRO
const int IN3 = 25;
const int IN4 = 26;
const int ENB = 27;

const float ZONA_MORTA = 0.08;

// ==========================================
// 3. FUNCOES DE MOVIMENTO (PWM 0 a 255)
void frente(int pwm) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, pwm);
}

void re(int pwm) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, pwm);
}

void pararTracao() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);
}

void esquerda(int pwm) {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, pwm);
}

void direita(int pwm) {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, pwm);
}

void pararDirecao() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}

void pararTudo() {
  pararTracao();
  pararDirecao();
}

// ==========================================
// 4. CONVERSAO (-1 a 1) PARA COMANDOS DO CARRO
int converterParaPwm(float valorNormalizado) {
  float limitado = constrain(fabs(valorNormalizado), 0.0f, 1.0f);
  return (int)round(limitado * 255.0f);
}

void aplicarControles(float volante, float acelerador) {
  // Direcao (volante: -1 a 1)
  if (fabs(volante) < ZONA_MORTA) {
    pararDirecao();
  } else if (volante < 0) {
    esquerda(converterParaPwm(volante));
  } else {
    direita(converterParaPwm(volante));
  }

  // Tracao (acelerador: -1 a 1)
  if (fabs(acelerador) < ZONA_MORTA) {
    pararTracao();
  } else if (acelerador > 0) {
    frente(converterParaPwm(acelerador));
  } else {
    re(converterParaPwm(acelerador));
  }
}

// ==========================================
// 5. RECEBIMENTO E PARSE DO JSON MQTT
void callback(char* topic, byte* payload, unsigned int length) {
  if (String(topic) != topicoVolante) {
    return;
  }

  String mensagem = "";
  mensagem.reserve(length);
  for (unsigned int i = 0; i < length; i++) {
    mensagem += (char)payload[i];
  }

  JsonDocument doc;
  DeserializationError erro = deserializeJson(doc, mensagem);

  if (erro) {
    Serial.print("Erro ao ler JSON em dados_volante: ");
    Serial.println(erro.c_str());
    return;
  }

  int carId = doc["car_id"] | CAR_ID_ESPERADO;
  if (carId != CAR_ID_ESPERADO) {
    return;
  }

  float volante = doc["volante"] | 0.0f;
  float acelerador = doc["acelerador"] | 0.0f;

  Serial.print("Volante -> car_id: ");
  Serial.print(carId);
  Serial.print(" | volante: ");
  Serial.print(volante, 3);
  Serial.print(" | acelerador: ");
  Serial.println(acelerador, 3);

  aplicarControles(volante, acelerador);
}

// ==========================================
// 6. CONEXAO WI-FI E MQTT
void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a rede Wi-Fi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi conectado com sucesso!");
  Serial.print("Endereco IP do ESP32: ");
  Serial.println(WiFi.localIP());
}

void conectarMQTT() {
  if (client.connected()) {
    return;
  }
  if (millis() - ultimaTentativaMQTT < 5000) {
    return;
  }

  ultimaTentativaMQTT = millis();
  Serial.print("Conectando ao Broker MQTT...");

  String clientId = "ESP32-Bancada-";
  clientId += String(random(0xffff), HEX);

  if (client.connect(clientId.c_str())) {
    Serial.println(" Conectado!");
    Serial.print("ClientID gerado: ");
    Serial.println(clientId);

    client.subscribe(topicoVolante);
    Serial.print("Inscrito no topico: ");
    Serial.println(topicoVolante);
  } else {
    Serial.print(" Falha MQTT, codigo rc=");
    Serial.print(client.state());
    Serial.println(". Tentando novamente em 5 segundos...");
  }
}

// ==========================================
// 7. SETUP E LOOP
void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  pararTudo();
  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  client.setBufferSize(256);

  Serial.println("Sistema iniciado!");
}

void loop() {
  if (mqttEstavaConectado && !client.connected()) {
    pararTudo();
    Serial.println("MQTT desconectado. Motores parados!");
  }
  mqttEstavaConectado = client.connected();

  if (WiFi.status() == WL_CONNECTED) {
    conectarMQTT();
    client.loop();
  }
}
