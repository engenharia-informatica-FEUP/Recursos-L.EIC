%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%     A* Algorithm
%%%     Nodes have form S+D+F+A
%%%            where S describes the state/board
%%%                  D is the depth of the node
%%%                  F is the evaluation function value
%%%                  A is the ancestor list for the node
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%:- op(400,yfx,'#'). % Node builder notation

%s. Resolve o problema aplicando distintos metodos de pesquisa
s:-
   estado_ini(State),
   f_function(State,0,F),
   search([State+0+F+[]],S),
   reverse(S,Soln),
   write(Soln).

%f_function(+State,+D,-F).
% Calcula a funcao F dada o G(n)= D (profundide do No) e o
% valor da% heuristica H (para o A* ou pesquisa gulosa)
f_function(State,D,F):-
	h_function(State,H),
	F is D + H.

%Pesquisa a solução
search([State+_+_+Soln|_], Soln) :-
	teste_obj(State).
search([B|R],S):-
	expand(B,Children),
	insert_all(Children,R,Open),
	search(Open,S).

%Funcao Auxiliar que insere nos na lista
insert_all([F|R],Open1,Open3) :-
    insert(F,Open1,Open2),
    insert_all(R,Open2,Open3).
insert_all([],Open,Open).

insert(B,Open,Open) :- repeat_node(B,Open), ! .
insert(B,[C|R],[B,C|R]) :- cheaper(B,C), ! .
insert(B,[B1|R],[B1|S]) :- insert(B,R,S), !.
insert(B,[],[B]).

%verifica se um no' e' repetido
repeat_node(P+_+_+_, [P+_+_+_|_]).

%verifica se um no tem um custo (funcao F) menor que outro
cheaper( _+_+F1+_ , _+_+F2+_ ):- F1 < F2.

%calcula os sucessores de um dado Estado State aplicando
%todos os operadores possiveis cujas pre-condicoes se verificam
expand(State+D+_+S,Sucessores):-
     bagof(Child+D1+F+[Move|S],
             (operador(Move,State,Child,Custo),
              D1 is D+Custo,
              f_function(Child,D1,F)),
           Sucessores),
     %write(Sucessores), nl,
     nl.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Codigo Especifico para o NPuzzle
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%estado(-Est).
%Retorna o estado inicial Est para o problema
estado_ini([[1,3,6],[5,2,0],[4,7,8]]).

%teste_obj(+Est).
%Verifica se Est verifica o test objetivo retornando
%true or false. Neste caso so' funciona para 3x3
%devendo ser alterado para NxN
teste_obj([[1,2,3],[4,5,6],[7,8,0]]).

%visualiza(+Estado)
%Visualiza em forma de Matriz, no ecran, o Estado Est
visualiza([]).
visualiza([Lin|RL]):-
	vis_lin(Lin),nl,
	visualiza(RL).

vis_lin([]).
vis_lin([El|REl]):-
	write(El),write(' '),
	vis_lin(REl).

%pos_espaco(+Estado,-YEsp, -XEsp)
%Determina a Posicao (X,Y) do Espaco (peca 0)
%A funcao pode ser alterada para pesquisa a posicao
%(X,Y) de um dado elemento a pesquisar
%Para tornar mais eficiente, a posição do Espaco
%deve fazer parte do estado do problema!
pos_espaco(Est,YEsp,XEsp):-
	posicao(Est,1,YEsp,XEsp).

posicao([Lin|_],YEsp,YEsp,XEsp):-
	posLin(Lin,1,XEsp).
posicao([_|RL],Y,YEsp,XEsp):-
	Y2 is Y+1,
	posicao(RL,Y2,YEsp,XEsp).

posLin([0|_],XEsp,XEsp).
posLin([_|REl],X,XEsp):-
	X2 is X+1,
	posLin(REl,X2,XEsp).

%movimento_valido(?Mov,+Est).
%verifica se um dado movimento e' valido no estado Est
%ou retorna movimentos validos nesse estado.
movimento_valido(cim,Est):- pos_espaco(Est,Y,_), Y>1.
movimento_valido(bai,Est):- pos_espaco(Est,Y,_), Y<3.
movimento_valido(esq,Est):- pos_espaco(Est,_,X), X>1.
movimento_valido(dir,Est):- pos_espaco(Est,_,X), X<3.

%executa_movimento(+Mov,+Est,-NEst).
%Excecuta o movimento Mov no estado Est gerando o
%novo estado NEst
executa_movimento(Mov,Est,NEst):-
	movimento_valido(Mov,Est),
	pos_espaco(Est,Y,X),
	posicao_seg(Mov,Y,X,YC,XC),
	muda_tab(Peca,0,YC,XC,Est,Est2),
	muda_tab(0,Peca,Y,X,Est2,NEst).

%posicao_seg(+Mov,+Y,+X,-YC,-XC).
%Dado o tipo de movimento Mov e a posicao (X,Y) do
%espaco calcula a posicao para onde este se move (XC,YC)
posicao_seg(cim,Y,X,YC,X):- YC is Y-1.
posicao_seg(bai,Y,X,YC,X):- YC is Y+1.
posicao_seg(esq,Y,X,Y,XC):- XC is X-1.
posicao_seg(dir,Y,X,Y,XC):- XC is X+1.

%Funcao auxiliar para ligar ao codigo de pesquisa
operador(Move,State,Child,1):-
	executa_movimento(Move,State,Child).

%lista_movs(+Est,-Lista)
%Dado o Estado calculas a lista de movimentos validos
%nesse estado (i.e cujas pre-condicoes se verificam)
lista_movs(Est,Lista):-
	findall(Mov,movimento_valido(Mov,Est),Lista).

%lista_sucessores(+Est,-Lista)
%Dado o Estado calculas a lista de estados sucessores
%que podem ser atingidos aplicados os operadores validos
lista_sucessores(Est,Lista):-
	findall(NEst,executa_movimento(_,Est,NEst),Lista).

%Predicados Auxiliares
%membrotab(-Pec,+Y,+X,+Tab)
%Retorna a peca que esta' na posicao (X,Y) do tabuleiro
membrotab(Pec,Y,X,Tab):-
	pos_lista(Linha, Y, Tab),
	pos_lista(Pec, X, Linha).
pos_lista(Memb,N,Lista):-
	procura(Memb,1,N,Lista).
procura(Memb,N,N,[Memb|_]).
procura(Memb,P,N,[_|T]):-
	P2 is P+1,
	procura(Memb,P2,N,T).

%muda_tab(?Peca,?PNov,+Y,+X,+Tab,-NovoTab)
%Muda na Matriz Estado/Tabuleiro Tab a Peca que esta na
%posicao (X,Y) de Peca para PNov gerando NovoTab
muda_tab(Peca,PNov,Y,X,Tab,NovoTab):-
	muda_tab2(1,Peca,PNov,Y,X,Tab,NovoTab),!.
muda_tab2(_,_,_,_,_,[],[]).
muda_tab2(Y,Peca,PNov,Y,X,[Lin|Resto],[NovLin|Resto2]):-
	muda_linha(1,Peca,PNov,X,Lin,NovLin),
	N2 is Y+1,
	muda_tab2(N2,Peca,PNov,Y,X,Resto,Resto2).
muda_tab2(N,Peca,PNov,Y,X,[Lin|Resto],[Lin|Resto2]):-
	N\=Y, N2 is N+1,
	muda_tab2(N2,Peca,PNov,Y,X,Resto,Resto2).

muda_linha(_,_,_,_,[],[]).
muda_linha(X,Peca,Pnov,X,[Peca|Resto],[Pnov|Resto2]):-
	N2 is X+1,
	muda_linha(N2,Peca,Pnov,X,Resto,Resto2).
muda_linha(N,Peca,Pnov,X,[El|Resto],[El|Resto2]):-
	N\=X, N2 is N+1,
	muda_linha(N2,Peca,Pnov,X,Resto,Resto2).

%h_function(+Est,-Valor)
%Criar funcao que calcula o valor da função Heuristica H
%do AStar ou Pesquisa Gulosa para um dado Estado

h_function(_,0).
%h_function(Est,Val):-

