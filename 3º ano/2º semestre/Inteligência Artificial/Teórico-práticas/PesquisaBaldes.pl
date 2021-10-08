%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%     A* Algorithm  - Nodes have the form: S+D+F+A
%%%            where S describes the state or configuration
%%%                  D is the depth of the node
%%%                  F is the evaluation function value
%%%                  A is the ancestor list for the node
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%:- op(400,yfx,'#').    % Node builder notation

s:- estado_ini(State), solve(State,Sol), write(Sol).

solve(State,Soln) :-
    f_function(State,0,F),
    search([State+0+F+[]],S),
    reverse(S,Soln).

f_function(State,D,F) :-
    h_function(State,H), F is D + H.

search([State+_+_+Soln|_], Soln) :- estado_obj(State).
search([B|R],S) :-
    expand(B,Children),
    insert_all(Children,R,Open),
    search(Open,S).

insert_all([F|R],Open1,Open3) :-
    insert(F,Open1,Open2),
    insert_all(R,Open2,Open3).
insert_all([],Open,Open).

insert(B,Open,Open) :- repeat_node(B,Open), ! .
insert(B,[C|R],[B,C|R]) :- cheaper(B,C), ! .
insert(B,[B1|R],[B1|S]) :- insert(B,R,S), !.
insert(B,[],[B]).

repeat_node(P+_+_+_, [P+_+_+_|_]).
cheaper( _+_+F1+_ , _+_+F2+_ ):- F1 < F2.

expand(State+D+_+S,MyChildren):-
     bagof(Child+D1+F+[Move|S],
             (operador(Move,State,Child,Custo),
              D1 is D+Custo,
              f_function(Child,D1,F)),
           MyChildren).  %write(MyChildren), nl.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%  Codigo Especifico Problema dos Baldes
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Capacidade(C1/C1).  estado_ini(B1/B2).  estado_obj(N1,N2).
cap(4/3).
estado_ini(0/0).
estado_obj(2/_).
%operador(Nome, EstIni, EstFin, Custo).
operador(d12a, Q1/Q2, Q1F/C2, 1):-
	cap(_/C2), Q1>0, Q2<C2, Q1>=C2-Q2, Q1F is Q1-(C2-Q2).
operador(d12b, Q1/Q2, 0/Q2F, 1):-
	cap(_/C2), Q1>0, Q2<C2, Q1<C2-Q2, Q2F is Q1+Q2.
operador(d21a, Q1/Q2, C1/Q2F, 1):-
	cap(C1/_), Q2>0, Q1<C1, Q2>=C1-Q1, Q2F is Q2-(C1-Q1).
operador(d21b, Q1/Q2, Q1F/0, 1):-
	cap(C1/_), Q2>0, Q1<C1, Q2<C1-Q1, Q1F is Q1+Q2.
operador(enc1, Q1/Q2, C1/Q2, 1):- cap(C1/_), Q1<C1.
operador(enc2, Q1/Q2, Q1/C2, 1):- cap(_/C2),Q2<C2.
operador(esv1, Q1/Q2, 0/Q2, 1):- Q1>0.
operador(esv2, Q1/Q2, Q1/0, 1):- Q2>0.
%h function: 0 seignifica pesquisa de custo uniforme
h_function(_,0).
