%player(Name, Username, Age)

player('Danny', 'Best Player Ever', 27).
player('Annie', 'Worst Player Ever', 24).
player('Harry', 'A-Star Player', 26).
player('Manny', 'The Player', 14).
player('Johnny', 'A Player', 16).

%game(Name, Categories, MinAge)

game('5 ATG', [action, adventure, open-world, multiplayer], 18).
game('Carrier Shift: Game Over', [action, fps, multiplayer, shooter], 16).
game('Duas Botas', [action, free, strategy, moba], 12).

%played(Player, Game, HoursPlayed, PercentUnlocked)

played('Best Player Ever', '5 ATG', 3, 83).
played('Worst Player Ever', '5 ATG', 52, 9).
played('The Player', 'Carrier Shift: Game Over', 44, 22).
played('A Player', 'Carrier Shift: Game Over', 48, 24).
played('A Star Player', 'Duas Botas', 37, 16).
played('Best Player Ever', 'Duas Botas', 33, 22).

% 1 a 6 sem usar bibliotecas, findall, etc

% Player completou pelo menos 80% de um jogo
achievedALot(Player):-
   played(Player, _, _, PercentUnlocked),
   PercentUnlocked >= 80.

% Game e um jogo adequado a idade de Name
isAgeAppropriate(Name, Game):-
    player(Name, _, Age),
    game(Game, _, MinAge),
    Age >= MinAge.

timePlayingGamesAux(_Player, [], _ListOfTimes, SumTimes, SumTimes).

timePlayingGamesAux(Player, [Head | Tail], ListOfTimes, SumTimes, SumTimes2):-
    played(Player, Head, HoursPlayed, _),
    Sum is SumTimes + HoursPlayed,
    write(HoursPlayed),
    timePlayingGamesAux(Player, Tail, [ListOfTimes | HoursPlayed], Sum, SumTimes2).

% N de horas que Player investiu a jogar cada um de Games
timePlayingGames(Player, Games, ListOfTimes, SumTimes):-
    timePlayingGamesAux(Player, Games, ListOfTimes, 0, SumTimes).

my_member([], _Element):- fail.
my_member([Element | Tail], Element).
my_member([Head | Tail], Element):-
    my_member(Tail, Element).


% imprime na consola os jogos da categoria Cat e a idade recomendada
listGamesOfCategory(Cat):-
    game(Game, Categories, MinAge),
    my_member(Cat, Categories).

% atualiza base de conhecimento relativamente ao n de horas que Player jogou Game
updatePlayer(Player, Game, Hours, Percentage).

% Devolve lista de jogos nos quais Player investiu menos de 10h a jogar
fewHours(Player, Games).

% Devolve lista dos jogadores com idade compreendida entre MinAge e MaxAge (limites inclusivos)
% ageRange(MinAge, MaxAge, Players)  

% idade media dos jogadores que jogam o jogo Game
% averageAge(Game, AverageAge)

% determina o(s) jogador(es) que jogam o jogo Game com maior eficiencia (maior percentagem em menos horas)
% mostEffectivePlayers(Game, Players)

% areClose(DistMax, MatrixDist, -Pares)

% distance(Obj1, Obj2, Dendograma, -Distancia)

