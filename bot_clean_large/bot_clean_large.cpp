#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
using namespace std;

/* Head ends here */
void next_move(int posx, int posy, int dimx, int dimy, vector <string> board)
{
    vector <int> xCoord;
    vector <int> yCoord;
    vector <int> dist;

    for(int x=0;x<dimx;x++)        //top to bottom
        for(int y=0;y<dimy;y++)    //left to right
        {
            if(board[x][y]=='d')
            {
                xCoord.push_back(x);
                yCoord.push_back(y);
                dist.push_back(abs(posx-x)+abs(posy-y));
            }
        }

    int minDistIndex = distance(dist.begin(), min_element(dist.begin(), dist.end()));
    int dirtPosX = xCoord[minDistIndex];
    int dirtPosY = yCoord[minDistIndex];

    if (dirtPosX<posx)
            cout << "UP" << endl;
        else if (dirtPosX>posx)
            cout << "DOWN" << endl;
        else if (dirtPosY<posy)
            cout << "LEFT" << endl;
        else if (dirtPosY>posy)
            cout << "RIGHT" << endl;
        else
            cout << "CLEAN" << endl;
}
/* Tail starts here */
int main() {
    int pos[2];
    int dim[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    cin>>dim[0]>>dim[1];
    for(int i=0;i<dim[0];i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], dim[0], dim[1], board);
    return 0;
}
