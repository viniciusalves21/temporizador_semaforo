# Controle de LEDs RGB com Temporizador (Raspberry Pi Pico - BitDogLab)

Este projeto demonstra o uso de um temporizador repetitivo no Raspberry Pi Pico para controlar um LED RGB, acendendo cada cor individualmente em sequência.

## Descrição

O código configura um temporizador que chama uma função de callback a cada 3 segundos.  Dentro dessa função, os LEDs vermelho, azul (simulando amarelo) e verde são acesos individualmente em sequência.  A cada disparo do temporizador, o LED correspondente à iteração atual é aceso, enquanto os demais são desligados, criando um ciclo de cores.

## Observações

* O LED azul aceso individualmente neste código simula a cor amarela. Para obter a cor amarela real, seria necessário acender os LEDs vermelho e verde simultaneamente.  Este código demonstra o controle individual dos LEDs.
* O código inclui uma rotina de repetição que imprime "Rotina de repetição" a cada 10 segundos.  Esta parte do código é independente do controle dos LEDs e serve para demonstrar outras operações que poderiam ser realizadas em paralelo com o controle dos LEDs.
* Este código utiliza um temporizador repetitivo (`add_repeating_timer_ms`).  Isso significa que o callback será chamado continuamente a cada 3 segundos, sem necessidade de rearmar o temporizador manualmente.
