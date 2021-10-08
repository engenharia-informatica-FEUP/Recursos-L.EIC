:- dynamic facto/4.	% facto(Atributo,Valor,FCerteza,ListaRegrasHistoria)

:- op(800,xfy,e).
:- op(900,xfx,entao).
:- op(850,fx,se).
:- op(950,xfx,com).
:- op(1000,xfx,::).


questionavel(motor_funciona,'O motor funciona ?',[sim,nao]).
questionavel(luz,'Qual a intensidade da luz ?',[fraca,razoavel,boa]).
questionavel(radio,'Qual a intensidade do radio ?',[fraca,razoavel,boa]).
questionavel(cheiro_gas,'Sente cheiro a gasolina ?',[sim,nao]).
questionavel(indicador_gas,'Como esta o indicador de gasolina ?',[vazio,baixo,meio,cheio]).

inicio:- retractall(facto(_,_,_,_)), 
	verifica(problema,Valor,FC,[obj(problema)]),
	write('O problema e '), write(Valor),
	write(' com factor de certeza= '), write(FC),nl.



1:: se motor_funciona=nao e bateria=ma entao problema=bateria com fc=1.
2:: se luz=fraca entao bateria=ma com fc=0.5.
3:: se radio=fraco entao bateria=ma com fc=0.5.
4:: se motor_funciona=sim e cheiro_gas=sim entao problema=encharcado com fc=0.8.
5:: se motor_funciona=sim e indicador_gas=vazio entao problema=sem_gasolina com fc=0.9.
6:: se motor_funciona=sim e indicador_gas=baixo entao problema=sem_gasolina com fc=0.3.
