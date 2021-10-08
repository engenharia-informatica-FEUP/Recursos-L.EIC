:- use_module(library(clpfd)).
:- use_module(library(lists)).

get_vars([],_, _, _,[]).
get_vars([H | T], C, Count, Objetos, [VH | VT]):-
	H #= Count #<=> B,
	element(C, Objetos, Var),
	NextC is C + 1,
	VH #= B * Var,
	get_vars(T, NextC, Count, Objetos, VT).
		
impoe_limite(_, _, _, Count, Max):- Count > Max.
impoe_limite(Vars, Prateleiras, Volumes, Count, Max):-
	get_vars(Vars, 1, Count, Volumes, VolumesP),
	element(Count, Prateleiras, Volume),
	sum(VolumesP, #=<, Volume),
	NextCount is Count + 1,
	impoe_limite(Vars, Prateleiras, Volumes, NextCount, Max).
	
get_volumes([], Volumes, Volumes).
get_volumes([P-V | T], Accum, Volumes):-
	append(Accum, [V], NextAccum),
	get_volumes(T, NextAccum, Volumes).
	
get_pesos([], Pesos, Pesos).
get_pesos([P-V | T], Accum, Pesos):-
	append(Accum, [P], NextAccum),
	get_pesos(T, NextAccum, Pesos).
	
get_pesos_comp(_, _, _, Count, Max, []):- Count > Max.
get_pesos_comp(Vars, Prateleiras, Pesos, Count, Max, [PC | PT]):-
	get_vars(Vars, 1, Count, Pesos, PesosP),
	sum(PesosP, #=, PC),
	NextCount is Count + 1,
	get_pesos_comp(Vars, Prateleiras, Pesos, NextCount, Max, PT).

get_prateleiras([], PrateleirasT, PrateleirasT).
get_prateleiras([H | T], Accum, PrateleirasT):-
	append(Accum, H, NextAccum),
	get_prateleiras(T, NextAccum, PrateleirasT).

	
prat(Prateleiras, Objetos, Vars):-
	length(Objetos, NumObjetos),
	length(Prateleiras, NP),
	nth1(1, Prateleiras, P),
	length(P, NP2),
	NumPrateleiras is NP * NP2,
	length(Vars, NumObjetos),
	domain(Vars, 1, NumPrateleiras),
	get_volumes(Objetos, [], Volumes),
	get_pesos(Objetos, [], Pesos),
	get_prateleiras(Prateleiras, [], PrateleirasT),
	impoe_limite(Vars, PrateleirasT, Volumes, 1, NumPrateleiras),
	get_pesos_comp(Vars, Prateleiras, Pesos, 1, NumPrateleiras, PesosComp),
	impoe_pesos(PesosComp, NumPrateleiras, NP2),
	labeling([], Vars).

impoe_pesos(_, P, P).
impoe_pesos(PesosComp, Count, P):-
	element(Count,PesosComp, PesoComp),
	Prev is Count - P,
	element(Prev,PesosComp, PesoComp2),
	PesoComp #>= PesoComp2,
	NextCount is Count - 1,
	impoe_pesos(PesosComp, NextCount, P).
