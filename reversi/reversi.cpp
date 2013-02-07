#include <iostream>
#include <vector>
using namespace std;

bool validMove(char player, int x, int y, vector <string> board)
{	
	char oppPlayer;
	//Determine opposite player
	if(player = 'W')
		oppPlayer = 'B';
	else
		oppPlayer = 'W';
		
	//If not empty space, invalid move
	if(board[x][y] != '-')
	{
		return false;
	}
		
	//If a neighbor is not opposite player, invalid move
	bool neighbor = false;	
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{		 
			int testX = x+i;
			int testY = y+j;
			if(testX>=0 && testX<8 && testY>=0 && testY<8)
			{
				if(board[testX][testY] == oppPlayer)
					return true;
			}
		}
	}	
	
	return false;
}

/* Head ends here */
void nextMove(char player, vector <string> board)
{
    for (int i=0;i<8;i++)
    {
    	for (int j=0;j<8;j++)
    	{
    		if(validMove(player, i,j,board))
    		{
    			board[i][j]='V';
    			cerr << endl;
    		}
    	}
    }
    
    //DEBUG PRINT BARD
	for (int m=0;m<8;m++)
	{
		cerr << board[m] << endl;
	}
}


/* Tail starts here */
int main() 
{

    char player;
    vector <string> board;

    cin >> player;

    for(int i=0; i<8; i++) 
    {
        string s; cin >> s;
        board.push_back(s);
    }
  
    nextMove(player,board);

    return 0;
}
