:- use_module(library(clpfd)).
:- use_module(library(lists)).

get_tasks([],[], [], [], _, Tasks,Tasks).
get_tasks([DH | DT], [SH | ST], [EH | ET], [NH | NT], Count, Accum, Tasks):-
	append(Accum, [task(SH, DH, EH, NH, Count)], NextAccum),
	NextCount is Count + 1,
	get_tasks(DT, ST, ET, NT, NextCount, NextAccum, Tasks).
	

furniture:-
	homens(NumHomens),
	tempo_max(Tempo_max),
	findall(Objeto, objeto(Objeto, _, _), Objetos),
	findall(NHomens, objeto(_, NHomens, _), NumHomensT),
	findall(Duracao, objeto(_, _, Duracao), Duracoes),
	length(Objetos, NumObjetos),
	length(StartTimes, NumObjetos),
	length(EndTimes, NumObjetos),
	domain(StartTimes, 1, Tempo_max),
	domain(EndTimes, 1, Tempo_max),
	get_tasks(Duracoes, StartTimes, EndTimes, NumHomensT, 1, [],Tasks),
	maximum(Tempo, EndTimes),
	Tempo #=< Tempo_max,
	cumulative(Tasks, [limit(NumHomens)]),
	append(StartTimes, EndTimes, Vars),
	labeling([minimize(Tempo)], Vars),
	write(Tempo), nl,
	write(StartTimes).
