# Tarefa: Controle de Servomotor por PWM

Este projeto utiliza o módulo PWM (Pulse Width Modulation) do microcontrolador **RP2040** para controlar o ângulo de um **servomotor micro servo padrão** no simulador **Wokwi**. A implementação é feita com a ferramenta **Pico SDK** e simula o comportamento do servo em diferentes posições.

## Componentes Utilizados
- **Microcontrolador**: Raspberry Pi Pico W
- **Servomotor**: Motor micro servo padrão (simulado no Wokwi)
- **Ferramenta de Simulação**: Wokwi
- **LED RGB**: GPIO 12


## Requisitos do Projeto
 **Configuração da Frequência PWM**
   - Definir a frequência do PWM para **50 Hz** (período de **20ms**) na **GPIO 22**.

 **Posicionamento Estático do Servo**
   - **180°**: Ciclo ativo de 2.400µs (12%) e espera de 5 segundos.
   - **90°**: Ciclo ativo de 1.470µs (0,0735%) e espera de 5 segundos.
   - **0°**: Ciclo ativo de 500µs (0,025%) e espera de 5 segundos.

 **Movimentação Contínua Suave**
   - Criar uma rotina para movimentar o servomotor de **0° a 180°** suavemente.
   - O ciclo ativo deve ser ajustado em incrementos de **±5µs** a cada **10ms**.

 **Experimento com a Ferramenta Educacional BitDogLab**
   - Utilizar o LED RGB na **GPIO 12**.

## Execução no Wokwi
Este projeto pode ser executado no **simulador Wokwi** sem a necessidade de um circuito de interface físico entre o **Raspberry Pi Pico W** e o **servomotor**.

