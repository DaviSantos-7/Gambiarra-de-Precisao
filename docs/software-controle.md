# Software e controle:
A programação do carrinho está sendo desenvolvida na Arduino IDE, utilizando o microcontrolador ESP32. O desenvolvimento é realizado por etapas, começando pelos testes individuais dos componentes e avançando para a implementação do sistema de controle do veículo.

Inicialmente, foram desenvolvidos códigos para testar o acionamento dos motores DC por meio da ponte H (L298N), responsável pelo controle dos motores. Esses testes envolvem os comandos de movimento para frente e para trás, a variação de velocidade e o acionamento do sistema de direção.

Paralelamente, estão sendo realizados testes de comunicação entre o celular e o ESP32, com o objetivo de permitir o controle remoto do carrinho. A integração entre os comandos de comunicação, tração e direção faz parte do desenvolvimento do sistema de controle do veículo.

## 1. Teste inicial da ponte H:
O primeiro código foi desenvolvido para testar o acionamento de um motor DC utilizando o driver L298N, responsável por controlar o sentido de rotação e a velocidade do motor. O programa utiliza os pinos GPIO 21 e GPIO 22 do ESP32 para definir o sentido de rotação, enquanto o GPIO 23 é utilizado para controlar a velocidade por meio do sinal PWM.

Durante a execução, o motor realiza os movimentos de avanço e ré, aumentando gradualmente a velocidade até o valor máximo configurado e, em seguida, reduzindo-a até parar. Esse procedimento permite observar o comportamento do motor nos dois sentidos de rotação.

**Arquivo:** `01_Teste_PonteH_ESP32.ino`

## 2. Teste da ponte H com funções de controle:

Após o teste inicial, foi desenvolvido um segundo código para organizar o acionamento dos motores em funções específicas. Essa estrutura facilita a reutilização dos comandos de movimento e a evolução da programação do carrinho.

O código permite organizar as ações de avanço, ré e parada, utilizando os pinos de controle do ESP32 conectados à ponte H L298N. Essa etapa contribui para tornar o programa mais organizado e facilitar a integração com outros sistemas.

**Arquivo:** `02_PonteH_Funcoes_.ino`

## 3. Desenvolvimento do sistema de direção:

O sistema de direção foi desenvolvido como uma etapa separada, com o objetivo de permitir o controle da orientação do carrinho. Nessa fase, foram organizados os comandos e as conexões necessários para controlar o mecanismo de direção por meio do ESP32.

A separação entre os testes de tração e de direção facilita a identificação de possíveis falhas antes da integração dos sistemas.

**Arquivo:** `03_Direcao_.ino`

## 4. Controle do carrinho via Bluetooth:

Após os testes individuais, foi desenvolvido um código para integrar os comandos de tração e direção com a comunicação Bluetooth. A proposta é permitir que o usuário envie comandos pelo celular, que são recebidos pelo ESP32 e interpretados pelo programa para controlar os movimentos do carrinho.

O código utiliza a biblioteca `BluetoothSerial.h` e configura o nome Bluetooth do dispositivo como `O_Rei_BT`.

Os comandos são organizados por letras, permitindo selecionar movimentos como avanço, ré, esquerda, direita e parada. O sistema também prevê comandos combinados para controlar a movimentação do veículo.

A integração permite reunir, em um único programa, a comunicação com o celular e o acionamento dos sistemas de tração e direção.

**Arquivo:** `04_Controle_Bluetooth_ESP32.ino`

## 5. Testes e validação:

O desenvolvimento foi realizado de forma progressiva, começando pelos testes de acionamento dos motores e avançando para a integração dos sistemas de controle.

Entre as etapas registradas estão os testes da ponte H, os testes do sistema de direção, a comunicação Bluetooth entre o celular e o ESP32 e o primeiro teste de movimentação do carrinho no chão, utilizando baterias.

Os testes permitem observar o funcionamento dos componentes e identificar ajustes necessários para melhorar a resposta do veículo aos comandos.

A validação completa do sistema depende da continuidade dos testes de tração, direção, comunicação e dirigibilidade.

## 6. Próximas etapas:

- Continuar os testes de movimentação e dirigibilidade do carrinho.
- Verificar a resposta dos sistemas de tração e direção aos comandos enviados pelo celular.
- Identificar e corrigir possíveis falhas de funcionamento.
- Avaliar a estabilidade da comunicação Bluetooth durante a movimentação.
- Atualizar a documentação conforme os novos testes e ajustes realizados.
