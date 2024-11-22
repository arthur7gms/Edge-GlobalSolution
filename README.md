# Sistema de Bloqueio e Desbloqueio *BikEnergy* - EDGE Global Solution

Este projeto implementa um sistema de bloqueio e desbloqueio de bicicletas utilizando um sensor ultrassônico, LEDs e um servo motor. Ele foi desenvolvido para simular o controle de acesso a uma bicicleta tecnologica de maneira prática e eficiente.

## 📋 Descrição do Projeto

O sistema funciona da seguinte forma:
- Quando um objeto (como a mão do usuário) é detectado dentro de uma distância específica (entre 5 cm e 50 cm) pelo sensor ultrassônico, o sistema **desbloqueia a bicicleta**:
  - O LED verde acende.
  - O servo motor move-se para a posição de abertura (90 graus).
  - Uma mensagem de "Bike Liberada" é exibida no monitor serial.
  
- Quando não há objetos próximos ou a distância é maior que 50 cm, o sistema **bloqueia novamente a bicicleta**:
  - O LED vermelho acende.
  - O servo motor retorna à posição de bloqueio (0 graus).
  - Uma mensagem de "Bike Bloqueada" é exibida no monitor serial.

## 🛠️ Componentes e Dependências

### Hardware Necessário
- 1 Arduino Uno (ou equivalente).
- 1 sensor ultrassônico (HC-SR04).
- 1 servo motor.
- 2 LEDs (vermelho e verde).
- Resistores para os LEDs.
- Jumpers e protoboard.

### Software Necessário
- Arduino IDE (versão 1.8.0 ou superior).
- Biblioteca **Servo** (já incluída por padrão na IDE).

## 📦 Estrutura do Sistema

- **LED Vermelho:** Indica que a bicicleta está bloqueada.
- **LED Verde:** Indica que a bicicleta está liberada.
- **Servo Motor:** Controla o mecanismo de bloqueio/desbloqueio.
- **Sensor Ultrassônico:** Detecta a proximidade do usuário.

## 💡 Funcionamento Básico do Código

1. **Configuração Inicial (`setup`)**:
   - Define os pinos dos LEDs e do sensor.
   - Inicia o servo motor na posição de bloqueio.
   - Acende o LED vermelho para indicar que a bicicleta está bloqueada.

2. **Loop Principal (`loop`)**:
   - Calcula a distância medida pelo sensor ultrassônico.
   - Verifica se o objeto está dentro do alcance para desbloquear ou bloquear a bicicleta.
   - Atualiza o estado dos LEDs e a posição do servo motor conforme necessário.
  
Link para o modelo criado no Tinkercad: https://www.tinkercad.com/things/jSUBG5BIkk0-bikenergy-gs

Todo o código está disponivel no arquivo BikEnergy.cpp

# Membros do Grupo:
*Arthur Gomes* - RM: 560771
*Matheus Siroma* - RM: 560248
*Pedro Estevam* - RM: 560642
