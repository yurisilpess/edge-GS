<div align="center">
            <h1>Projeto Arduino - Monitor de Nível de Água</h1>  
</div>

# Créditos / Autores 🖋️
Este projeto foi desenvolvido por:
* [Igor Soos](https://github.com/igor-soos)
* [Yuri Pessoa](https://github.com/yurisilpess)

------------

<div align="center">
            <h1>Projeto Monitor de Nível de Água</h1>  
</div>

📌 - Este é um projeto que utiliza um sensor de distância ultrassônico para monitorar o nível de água em um reservatório. O sistema emite alertas sonoros e visuais caso ocorra uma variação brusca no nível da água.

## Materiais Necessários 📚

- 🔌 - Arduino Uno
- 📏 - Sensor de Distância Ultrassônico HC-SR04
- 🕒 - Módulo RTC (Real-Time Clock)
- 🔊 - Buzzer
- 💡 - LEDs
- 🔧 - Protoboard e Jumpers
- 🧯 - Resistores 110 kΩ

## Montagem do Circuito 📐

🔎 - Circuito realizado no Wokwi:

<img width="664" alt="Screenshot 2024-06-07 at 20 41 35" src="https://github.com/yurisilpess/edge-GS/assets/99032447/9a522cce-e569-46c1-b498-93535836fe5d">

-----------
🎥 Vídeo de explicação:

https://github.com/yurisilpess/edge-GS/assets/99032447/0605d8a2-6b5a-48a3-97d7-08e0119a0f73


### Conectando o Sensor Ultrassônico HC-SR04:
- VCC -> 5V no Arduino
- GND -> GND no Arduino
- Trig -> Pino digital 9 no Arduino
- Echo -> Pino digital 10 no Arduino

### Conectando o RTC:
- VCC -> 5V no Arduino
- GND -> GND no Arduino
- SDA -> Pino A4 no Arduino
- SCL -> Pino A5 no Arduino

### Conectando o Buzzer:
- Terminal positivo do buzzer -> Pino digital 11 no Arduino
- Terminal negativo do buzzer -> GND no Arduino

### Conectando LEDs:
- Anodo (+) de cada LED -> Pinos digitais 12 e 13 no Arduino
- Catodo (-) de cada LED -> GND (através de resistores, geralmente 220Ω)

## Explicação do Código 📝

- **Setup:** Inicializa os pinos e módulos (RTC e SD).
- **Loop:** Verifica se é hora de medir o nível de água. A cada medida, calcula a distância e compara com a medida anterior.
- **Alertas:** Se houver uma variação maior que o threshold, ativa o buzzer e o LED vermelho.

O funcionamento é o seguinte: O LED verde fica aceso quando o sistema está ativado e o dispositivo verifica o nível da água a cada 30 segundos. Quando há uma variação brusca (valor superior ao threshold), o buzzer será ativado e o LED vermelho também acenderá.

## Links 🔗
- [Wokwi Simulation](https://wokwi.com/projects/400076234802302977)

🔚
