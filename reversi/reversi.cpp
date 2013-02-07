#include <stdio.h>
#include <string.h>
#include <math.h>

/* Head ends here */
void nextMove(char player, char board[9][9])
{
    //logic here
}

/* Tail starts here */
int main() 
{

    int i;
    char player;
    char board[9][9];
    char line[9];
    scanf("%c", &player);

    for(i=0; i<9; i++) 
    {
        scanf("%s", line);
        strncpy(board[i], line, 9);
    }
    nextMove(player,board);
    return 0;
}