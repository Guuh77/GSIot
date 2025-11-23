# Smart Home Office: Monitor de Bem-Estar (IoT & IoB)

> **Disruptive Architectures: IoT, IoB & Generative IA** > Solução de monitoramento ambiental focada na saúde ocupacional e no futuro do trabalho.

---

## Sobre o Projeto

No cenário do **Futuro do Trabalho**, onde o Home Office se torna padrão, a fronteira entre conforto doméstico e eficiência profissional se mistura. Muitas vezes, ambientes inadequados (muito quentes ou secos) afetam silenciosamente a **saúde cognitiva** e a **produtividade**.

Este projeto propõe uma solução de **IoB (Internet of Behavior)**: um dispositivo IoT simples e acessível que monitora a temperatura e a umidade do ambiente de trabalho em tempo real, gerando dados visuais para que o colaborador possa ajustar seu ambiente, garantindo bem-estar e foco.

## Funcionalidades

* **Coleta de Dados:** Monitoramento constante de temperatura e umidade.
* **Conectividade:** Envio de dados via Wi-Fi utilizando protocolo HTTP.
* **Visualização em Nuvem:** Dashboard no ThingSpeak com gráficos históricos e medidores de nível de conforto (Gauges).
* **Alerta Visual:** Indicação clara de zonas de conforto vs. zonas de risco à saúde.

## Tecnologias Utilizadas

* **Hardware (Simulado):** ESP32 (Microcontrolador) + DHT22 (Sensor de Temperatura e Umidade).
* **Ambiente de Desenvolvimento:** [Wokwi](https://wokwi.com/) (Simulador Online).
* **Linguagem:** C++ (Arduino IDE).
* **Gateway & Dashboard:** [ThingSpeak](https://thingspeak.com/) (IoT Analytics).

## Arquitetura da Solução

1.  **Sensor DHT22** capta as condições do ambiente.
2.  **ESP32** processa as informações e conecta ao Wi-Fi.
3.  Os dados são enviados via requisição **HTTP** para a API do **ThingSpeak**.
4.  O **Dashboard** exibe os indicadores em tempo real para o usuário.

## Como Executar (Simulação)

Para rodar este projeto não é necessário hardware físico, basta utilizar o simulador Wokwi.

1.  Acesse o [Wokwi](https://wokwi.com/).
2.  Inicie um novo projeto com **ESP32**.
3.  Copie o código do arquivo `src/sketch.ino` deste repositório para o editor.
4.  Copie o conteúdo do arquivo `src/diagram.json` para a aba `diagram.json` do simulador.
5.  Adicione as bibliotecas **"ThingSpeak"** e **"DHT sensor library for ESPx"** no Library Manager.
6.  Configure a variável `myWriteAPIKey` no código com a sua chave do ThingSpeak.
7.  Clique no botão **Play**.

## Demonstração

Confira o funcionamento da solução e a explicação da proposta no vídeo abaixo:

[**Assistir Vídeo no YouTube**](https://youtu.be/ijpwxriErFE)

---

## 👨‍💻 Integrantes do Grupo

* **Ana Eliza** (RM: 559544)
* **Arthur Henrique** (RM: 560820)
* **Gustavo Ramos** (RM: 561055)
