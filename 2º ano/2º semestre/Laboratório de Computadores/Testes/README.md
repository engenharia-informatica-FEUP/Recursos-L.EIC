# Informações sobre os testes
* Nos testes de LCOM sai sempre um dos seguintes tópicos: timer, teclado, rato ou a placa gráfica.
* Os testes são semelhantes aos labs, mas com ligeiras modificações. São semelhantes na medida em que se trata de um tipo de dispositivo (timer, teclado, rato ou placa gráfica) e são diferentes na medida em que a informação de cada bit, os pormenores técnicos são diferentes. Para além disso, o teste é adaptado para o tempo que têm para o fazer. 
* Recomenda-se que saibam bem como fazer os labs. De preferência, refazê-los várias vezes até se sentirem familiarizados com todo o tipo de erros que podem aparecer e também como forma de "decorarem" as funções que fizeram. 
* Um teste típico de LCOM consiste em várias funções/vários passos que têm de implementar para passar aos vários testes da LCF. Não adianta "saltar" os testes, ou seja, tentar passar ao teste 2, por exemplo, se ainda não consguiram passar ao teste 1. A avaliação é automática e os testes são incrementais. 

## Timer 
* Ver [aqui](pp1-timer-2020.pdf) enunciado de um teste de 2020 (PP1). 
* Ver [aqui](solution-timer.txt) exemplo de uma solução.

## Teclado

## Rato
* Ver [aqui](pp.c) exemplo do código que já é fornecido.
* Ver [aqui](teste-rato.txt) exemplo de uma solução. 
* Como receber as interrupções do rato. 
* Tratar da informação que as interrupções dão (ler packets, dar parse e fazer display como no lab3).
* É semelhante ao lab3 na medida em que têm de receber e lidar com interrupções. E é diferente na medida em que os bytes têm valores diferentes.
* Num dos exercícios foi pedido para fazer uma versão otimizada do "protocolo" do rato. No primeiro byte do packet há dois bits que indicam se há displacement nos eixos X e Y, sendo que os outros dois bytes correspondem ao valor destes displacements. Neste exercício é suposto implementar um protocolo mais eficiente, em que só são enviados os outros bytes se houver displacement. Ou seja:
    * bit deltaX e bit deltaY com valor 1: três bytes para ler (igual ao costume)
    * um dos bits a zero e o outro a 1: dois bytes para ler, sendo que o que tiver o bit a zero não é enviado pelo rato. 
    * os dois bits a zero: um byte para ler (que é o byte que já foi lido), portanto monta-se logo o packet
* Passos:
    1) Dar enable do data reporting ou algo análogo para ele funcionar. Geralmente, isso faz-se escrevendo num Control Register ou enviando um comando para um Command Register. A maneira que é feita no lab dá algum trabalho, porque tem vários passos, mas no teste, em príncipio, é algo mais simplificado.
    2) Subscrever as interrupções. Isso é praticamente igual em todos os dispositivos.
    3) No driver_receive loop, ler um packet que pode estar em vários bytes. Pode acontecer ser uma interrupção por byte ou uma interrupção por packet. Em ambos os casos, altera-se o interrupt handler (ih). Se for uma interrupção por byte pode-se ter um contador static que quando for igual ao número total de bytes trata-se do packet. Se for uma interrupção por packet, lê-se todos os bytes de uma só vez (num loop ou "à força bruta" com vários sys_inb seguidos) e faz-se logo parse do packet. 
    4) Reverter tudo o que foi feito. Isso passa por dar unsubscribe das interrupções. Se foi preciso escrever algo no Control Register, voltar a pôr-lhe o mesmo valor inicial. 

## Placa gráfica
* Ver [aqui](pp2-video-2020.pdf) enunciado de um teste de 2020 (PP2).
* Ver [aqui](pp3-video-and-timer-2020.pdf) outro enunciado de um teste de 2020 (PP3).

