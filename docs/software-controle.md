# Software e controle:
A programação do carrinho está sendo desenvolvida na Arduino IDE, utilizando o microcontrolador ESP32. O desenvolvimento é realizado por etapas, começando pelos testes individuais dos componentes e avançando para a implementação do sistema de controle do veículo.

Inicialmente, foram desenvolvidos códigos para testar o acionamento dos motores DC por meio da ponte H (L298N), responsável pelo controle dos motores. Esses testes envolvem os comandos de movimento para frente e para trás, a variação de velocidade e o acionamento do sistema de direção.

Paralelamente, estão sendo realizados testes de comunicação entre o celular e o ESP32, com o objetivo de permitir o controle remoto do carrinho. A integração entre os comandos de comunicação, tração e direção faz parte do desenvolvimento do sistema de controle do veículo.

## 1. Teste inicial da ponte H:
O primeiro código foi desenvolvido para testar o acionamento de um motor DC utilizando o driver L298N, responsável por controlar o sentido de rotação e a velocidade do motor. O programa utiliza os pinos GPIO 21 e GPIO 22 do ESP32 para definir o sentido de rotação, enquanto o GPIO 23 é utilizado para controlar a velocidade por meio do sinal PWM.

Durante a execução, o motor realiza os movimentos de avanço e ré, aumentando gradualmente a velocidade até o valor máximo configurado e, em seguida, reduzindo-a até parar. Esse procedimento permite observar o comportamento do motor nos dois sentidos de rotação.

**Arquivo:** `01_Teste_PonteH_ESP32.ino`
