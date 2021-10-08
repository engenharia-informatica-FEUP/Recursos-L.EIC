#include <iostream>
#include <cstdlib> 
#include <windows.h>

#define HEI 6
#define WID 7

using namespace std;

//Simple State representation. Only board is needed bu other fields are useful.
struct state{
	int board[HEI][WID];
	int lastMoveX, lastMoveY;
	int player;
	int nmoves;
};

//Move is trivial on this game (only col - column where to play). 
struct move{
	int col;
};
  
//Basic functions to implement a simple C game with Human/Computer game and Minimax 
void draw_state(state st);
void init_state(state &st);
move get_human_mov(state st);
move get_pc_rand_mov(state st);
move get_pc_greedy_mov(state st);
bool valid_movement(state st, move mov);
state execute_movement(state st, move mov);
int check_winner(state st);
int evaluate(state st, int pl);

int main()
{
   state st; move mov;
   srand(GetTickCount()); 
   init_state(st);
   draw_state(st);
   
   do {
      	//mov = get_human_mov(st);
      	if (st.player==1) mov = get_pc_greedy_mov(st); else mov=get_human_mov(st);
      	st = execute_movement(st, mov);
      	draw_state(st);
   } while (check_winner(st)==-1);
   cout << "End of Game! Winner: " << check_winner(st) << endl;
   
   system("PAUSE");
}

void init_state(state &st)
{
	for(int i=0; i<HEI; i++)	
		for(int j=0; j<WID; j++)
			st.board[i][j]=0;
	st.nmoves=0; st.player=1; 
}

void draw_state(state st)
{
   	cout << "| 1 | 2 | 3 | 4 | 5 | 6 | 7 |" << endl;
   	cout << "-----------------------------" << endl;
   	for (int y=HEI-1; y>=0; y--) {
      	for (int x=0; x<WID; x++) {
         	if (st.board[y][x] == 0) cout << "|   ";
         	else if (st.board[y][x] == 1) cout << "| X ";
         	else if (st.board[y][x] == 2) cout << "| O ";
         	if (x==WID-1) cout << "|\n";
      }
      cout << "-----------------------------" << endl;
   }
   cout << "Evaluation: " << evaluate(st, st.player) << endl;
}

bool valid_movement(state st, move mov)
{
	return (mov.col>=1 && mov.col<= WID && st.board[HEI-1][mov.col-1]==0);
}

state execute_movement(state st, move mov)
{
	int i=0;
   	while (st.board[i][mov.col-1] != 0) i++;
   	st.board[i][mov.col-1]=st.player;
   	st.lastMoveY = i; st.lastMoveX = mov.col-1;
   	st.player= 3-st.player;
   	st.nmoves++;
   	return st;
}

// Get Human Movement from keyboard
move get_human_mov(state st)
{
   move mov;  
   do {
   		cout << "\nPlayer" << st.player << ", Please Select Move (1-7): ";
      	cin >> mov.col;
   } while (!valid_movement(st, mov));
   return mov;
}

//Get PC Random Movement
move get_pc_rand_mov(state st)
{
   move mov;  
   do {
   		mov.col=rand()%7+1;
   } while (!valid_movement(st, mov));
   return mov;	
}

//Get PC Greedy Movement (wins but also looses game easily)
move get_pc_greedy_mov(state st)
{	
   move mov, movfin;
   int aval=-1000; 
   state st2; 
   for(mov.col=0; mov.col<WID; mov.col++){
   		if (valid_movement(st, mov)) {
   			st2 = execute_movement(st,mov);
			if (evaluate(st2, st.player)>aval) {aval=evaluate(st2, st.player); movfin=mov;}
		}  	
	}	   
   	return movfin;	
}

bool count(int n, int pl, int p1, int p2, int p3, int p4)
{
	int pec = (p1==pl) + (p2==pl)+ (p3==pl) + (p4==pl);
	if (n==4) return pec==4;
	int vaz = (p1==0) + (p2==0)+ (p3==0) + (p4==0);
	if (n==3) return pec==3 && vaz==1;
}

//calculates lines of 4 or lines of 3 with an empty cell for
//horizontal, vertical and diagonal
int line(int n, state st, int pl)
{
	int lin=0;
    for(int i=0; i<HEI; i++)
        for(int j=0; j<WID; j++) {
			if(j<WID-3 && count(n, pl, st.board[i][j],st.board[i][j+1],st.board[i][j+2],st.board[i][j+3])) 
				lin++;
			if(i<HEI-3 && count(n, pl, st.board[i][j],st.board[i+1][j],st.board[i+2][j],st.board[i+3][j]))
				lin++;
			if(j<WID-3 && i<HEI-3 && 
				count(n, pl, st.board[i][j],st.board[i+1][j+1],st.board[i+2][j+2],st.board[i+3][j+3])) 
				lin++;
        	if(j>3 && i<HEI-3 && 
				count(n, pl, st.board[i][j],st.board[i+1][j-1],st.board[i+2][j-2],st.board[i+3][j-3]))
				lin++;
    }
    return lin;
}

int check_winner(state st)
{
   	if (st.nmoves==42) return 0;
   	if (line(4, st, 1)>0) return 1;
   	if (line(4, st, 2)>0) return 2;
  	return -1;
}

int posit(state st, int pl)
{
	int val=0;
    for(int i=0; i<HEI; i++)
        for(int j=0; j<WID; j++) 
			if (st.board[i][j]==pl)
				if (j==3) val+=2; else if (j==2 || j==4) val++;	
    return val;
}

int evaluate(state st, int pl)
{
	int pos = posit(st,pl) - posit(st,3-pl);
	int lin3 = line(3, st, pl) - line(3, st, 3-pl);
	int lin4 = line(4, st, pl) - line(4, st, 3-pl);
	int val = lin4*100 + lin3*5 + pos;
	cout << "Val: " << val << "  = Pos: " << pos << "  Lin3: " << lin3 << "  Lin4: " << lin4 << endl;
	return val;
}


