# Arquitetura geral:

Documentação da arquitetura geral do veículo, seus principais subsistemas e interfaces


## 1. Visão geral do Projeto:
O projeto consiste no desenvolvimento de um carrinho controlado remotamente, utilizando a estrutura física de um carrinho de controle remoto como base.
O sistema utiliza um microcontrolador ESP32, uma ponte H L298N, motores elétricos, baterias e uma câmera para captura e transmissão de imagens.

O controle do carrinho será realizado por meio de um volante, que permitirá ao operador comandar os movimentos do veículo. A comunicação entre a interface de controle e o carrinho acontecerá utilizando o protocolo MQTT, permitindo o envio e recebimento de informações pela rede.

A câmera será responsável por transmitir imagens do ambiente, possibilitando que o operador acompanhe visualmente o percurso do carrinho.

## 2. Principais Subsistemas

### 2.1. Subsistema de Controle
- **ESP32:** responsável pelo processamento dos comandos e pelo controle geral do carrinho.
- **Volante:** utilizado como dispositivo de entrada para controlar a direção e a movimentação do veículo.
- Recebe os comandos enviados pela interface de controle por meio da comunicação MQTT.

### 2.2. Subsistema de Comunicação
- **MQTT:** protocolo utilizado para estabelecer a comunicação entre a interface de controle e o carrinho.
- Permite o envio dos comandos de movimentação e o recebimento de informações do sistema.
- Utiliza um sistema de publicação e inscrição em tópicos (Publish/Subscribe).

### 2.3. Subsistema de Visão
- **Câmera:** responsável pela captura de imagens do ambiente ao redor do carrinho.
- Permite que o operador acompanhe visualmente o deslocamento do veículo por meio da transmissão das imagens.

### 2.4. Subsistema de Potência
- **Baterias de 3 V:** responsáveis pelo fornecimento de energia ao sistema.
- **Ponte H L298N:** responsável pelo acionamento dos motores, permitindo controlar seus sentidos de rotação.

### 2.5. Subsistema Mecânico
- **Chassi:** estrutura física reaproveitada de um carrinho de controle remoto.
- **Motores elétricos:** responsáveis pela movimentação do veículo.
- **Rodas:** permitem o deslocamento do carrinho.

## 3. Arquitetura de Funcionamento
O funcionamento geral do sistema ocorre da
- `software-controle.md`: programação e lógica de funcionamento.
- `materiais.md`: lista de materiais utilizados.
- `testes.md`: procedimentos e resultados dos testes.
