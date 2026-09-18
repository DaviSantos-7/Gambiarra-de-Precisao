# Gambiarra-de-Precisao

# Projeto Integrador — Competição de Carrinhos

## Equipe

**Nome da equipe:** Gambiarra de Precisão
**Veículo:** O Rei
**Turma:** Mecatrônica - IFRN Parnamirim
**Professor / Orientador:** Breno Moura

### Integrantes e áreas de atuação:

| Integrante    | Área principal | Responsabilidades                                             |
| ------------- | -------------- | ------------------------------------------------------------- |
| Davi Lucas    | Piloto         | Testes de dirigibilidade, calibração e operação               |
| José Douglas  | Mecânica       | Chassi, direção, transmissão e montagem física                |
| Lucas Gabriel | Projetista     | Arquitetura, desenhos, organização da documentação            |
| Maria Vitória | Eletricista    | Alimentação, drivers, motores, diagramas elétricos e conexões |
| Lilian Anny   | Programadora   | Código do ESP32, controle PWM soft-start e telemetria UDP     |

---

## 1. Objetivo do projeto:

Desenvolver o veículo "O Rei" para participação na Competição de Carrinhos do Projeto Integrador, percorrendo a pista conforme o regulamento e respondendo aos comandos de controle remoto.

## 2. Conceito da solução:

O veículo utiliza uma arquitetura de tração baseada em dois motores CC com acionamento diferencial, permitindo o deslocamento e o controle da direção por meio do controle independente dos motores. O ESP32 atua como controlador principal, recebendo os comandos do sistema da organização e acionando os motores conforme os comandos recebidos.

- **Arquitetura de tração:** diferencial com dois motores CC;

- **Direção:** diferencial, por controle independente dos motores;

- **Controlador principal:** ESP32;

- **Driver de motores:** módulo ponte H;

- **Câmera embarcada:** sistema de câmera instalado no veículo;

- **Estratégia de alimentação:** bateria utilizada para alimentação dos sistemas;

- **Sensores adicionais:** conforme necessidade do projeto;

- **Comunicação:** comunicação sem fio com o sistema de controle da organização;

- **Recursos de automação:** controle eletrônico dos motores e processamento dos comandos pelo ESP32.
  
  ---

## 3. Arquitetura geral:

É composta pelos seguintes elementos:

```text
                 Volante da organização
                          |
                          | UDP
                          v
                        ESP32
                          |
          +---------------+---------------+
          |               |               |
          v               v               v
   Controle dos       Sensores        Atuadores
      motores
          |
          +--> Motor esquerdo
          |
          +--> Motor direito
          
                        ESP32
                          |
                          | MQTT
                          v
                     Telemetria

              Celular embarcado
                       |
                       v
                Transmissão de vídeo

### Subsistemas:

- **Mecânica:** chassi, rodas, motores e elementos de fixação;
- **Eletrônica:** ESP32, driver de motores, alimentação e conexões;
- **Software:** Processamento dos comandos e controle dos motores;
- **Comunicação:** UDP para recebimento dos comandos e MQTT para telemetria;
- **Vídeo:** Celular embarcado utilizado para transmissão de imagem ao piloto.

---

## 4. Estado atual do desenvolvimento

Atualizar esta seção ao longo do projeto.

### Concluído:

- [ ] Definição da arquitetura geral
- [ ] Projeto mecânico inicial
- [ ] Diagrama elétrico inicial
- [ ] Comunicação com o sistema da organização
- [ ] Controle dos motores em bancada
- [ ] Integração mecânica
- [ ] Integração eletroeletrônica
- [ ] Teste do veículo em movimento
- [ ] Integração da câmera
- [ ] Outros: ____________________

### Em desenvolvimento:

- Atividades em andamento:

### Pendências principais:

- Finalizar a integração dos componentes mecânicos e eletrônicos do veículo;
- Ajustar o controle dos motores e a resposta aos comandos do volante;
- Realizar e aprimorar os testes de deslocamento e dirigibilidade;
- Finalizar a integração e os testes da câmera embarcada;
- Validar a comunicação entre o veículo e o sistema da organização;
- Realizar testes integrados para identificar e corrigir falhas;
- Registrar os resultados dos testes e atualizar a documentação técnica.
---

## 5. Planejamento e acompanhamento:

- [Planejamento do projeto](PLANEJAMENTO.md)
- [Registro de progresso](PROGRESSO.md)
- [Cronograma detalhado](https://drive.google.com/file/d/17hfmQDEQwMn1P48ckapg5prJT3HRXAut/view?usp=sharing)

---

## 6. Documentação técnica:

Organizar a documentação técnica, preferencialmente, nas seguintes pastas:

```text
docs/
├── arquitetura/
├── mecanica/
├── eletronica/
├── software/
└── testes/
```

### Documentos disponíveis:

- Arquitetura geral: ____________________
- Projeto mecânico: ____________________
- Diagrama elétrico: ____________________
- Documentação do software: ____________________
- Lista de materiais: ____________________
- Registros de testes: ____________________

---

## 7. Materiais e componentes:

| Item                 | Quantidade | Origem               | Situação             |
| -------------------- | ----------:| -------------------- | -------------------- |
| ESP32                | 1          | Kit da organização   | Disponível           |
| Motor DC             | 2          | Kit da organização   | Disponível           |
| Driver de motor      | 1          | Kit da organização   | Disponível           |
| ____________________ | ___        | Equipe / organização | ____________________ |

---

## 8. Comunicação com a organização:

### Comandos:

- Protocolo: UDP unicast
- Porta: 5000
- Formato: JSON em UTF-8
- Frequência nominal: 60 Hz

Formato esperado:

```json
{
  "sequencia": 123,
  "volante": 0,
  "aceleracao": 0,
  "habilitado": true
}
```

### Telemetria:

- Protocolo: MQTT 3.1.1 sobre TCP
- Porta: 1883
- Tópico previsto: `carrinhos/<equipe>/telemetria`

Os campos definitivos de telemetria serão definidos pela equipe em conjunto com os professores.

---

## 9. Testes realizados:

Registrar os testes relevantes do projeto. Para registros mais detalhados, utilizaremos `docs/testes/`.

| Data       | Teste                | Resultado            | Próxima ação         |
| ---------- | -------------------- | -------------------- | -------------------- |
| __/__/2026 | ____________________ | ____________________ | ____________________ |

---

## 10. Observações:

- O projeto encontra-se em desenvolvimento e poderá sofrer alterações durante as etapas de montagem, integração e testes.
- As decisões técnicas e alterações realizadas ao longo do desenvolvimento serão registradas no repositório.
- Os resultados dos testes serão utilizados para orientar os ajustes no veículo e atualizar a documentação.
- O planejamento poderá ser atualizado conforme o andamento do projeto, com as alterações devidamente registradas no `PROGRESSO.md`.
- A equipe priorizará a validação gradual dos subsistemas antes dos testes integrados e da preparação final para a competição.
