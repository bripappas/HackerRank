#include<iostream>
#include<vector>
using namespace std;

/* Head ends here */
void nextMove(int posx, int posy, vector <string> board) 
{
	int dirtPosX=-1, dirtPosY=-1;
	for(int i=0;i<5;i++)
	{
			dirtPosX = i;
			dirtPosY = board[i].find("d");
			if (dirtPosY >= 0)
				break;
	}
	
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
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    nextMove(pos[0], pos[1], board);
    return 0;
}
