🎮 Desafio das Cores (Color Challenge)
📌 Descrição do Projeto
O Desafio das Cores (Color Challenge) é um jogo interativo desenvolvido para um microcontrolador baseado no Raspberry Pi Pico W, utilizando uma matriz de LEDs endereçáveis 5x5, um joystick, botões de controle e um buzzer para feedback sonoro. O objetivo do jogo é simples e envolvente: o jogador deve mover um cursor luminoso pela matriz de LEDs e "coletar" a cor correspondente exibida no LED RGB inferior. A cada acerto, um ponto é acumulado e a velocidade do jogo pode aumentar gradativamente, tornando o desafio ainda mais empolgante.

O projeto foi desenvolvido para proporcionar uma experiência lúdica e educativa, aplicando conceitos de eletrônica e programação de sistemas embarcados. Ele pode ser utilizado como ferramenta de ensino para iniciantes em programação de hardware e desenvolvimento de jogos simples.

🛠️ Componentes Utilizados
Microcontrolador: Raspberry Pi Pico W
Matriz de LEDs: 5x5 endereçável (WS2812B)
LED RGB Inferior: Indica a cor a ser capturada pelo jogador
Joystick: Controla a posição do cursor na matriz de LEDs
Botões A e B: Interagem com o jogo (coleta de cores e reinício)
Buzzer: Emite sons de feedback para acertos e vitórias
🎯 Como Funciona
Início do jogo: O jogador precisa pressionar o botão A ou B para começar.
Objetivo: O LED RGB inferior exibe uma cor. O jogador deve navegar pela matriz de LEDs e encontrar a cor correspondente.
Coleta da cor: Ao posicionar o cursor na cor correta e pressionar o botão B, um ponto é acumulado e uma nova cor é gerada.
Condição de vitória: Ao coletar 5 cores corretamente, o jogador vence e uma animação especial em formato de coração é exibida, acompanhada por um efeito sonoro.
Reinício: Após a vitória, o jogo pode ser reiniciado automaticamente ou manualmente ao pressionar o botão B.
