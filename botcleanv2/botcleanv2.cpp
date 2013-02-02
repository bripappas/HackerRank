//Traveling Salesman Problem
//Implemented as nearest neighbor (not optimal)
//THIS IS AWFUL CODE

#include<iostream>
#include<vector>
#include<cmath>
#include <algorithm>
#include <fstream>
using namespace std;

/* Head ends here */
void next_move(int posx, int posy, vector <string> board)
{
    
	ofstream myfileW;
    ofstream myFileDirtyW;
	myfileW.open("been.txt",ios::app);
    myFileDirtyW.open("seen.txt",ios::app);
    for(int i=-1;i<=1;i++)
    {
        for(int j=-1;j<=1;j++)
        {
            if((posx+i > -1)&&(posx+i<5)&&(posy+j> -1)&&(posy+j<5))
            {
                if(board[posx+i][posy+j] == '-')
                {
                    myfileW << posx+i << endl;
                    myfileW << posy+j << endl;
                }
                if(board[posx+i][posy+j] == 'd')
                {
                    myFileDirtyW << posx+i << endl;
                    myFileDirtyW << posy+j << endl;
                }
            }
        }
    }
    
	myfileW << posx << "\n" << posy << endl;
	myfileW.close();
    myFileDirtyW.close();
    
    if(board[posx][posy]=='d')
    {
        cout << "CLEAN" << endl;
        return;
    }
	
	string xBeen,yBeen;
	int xB, yB;
	
	ifstream myfileRDirty ("seen.txt");
	while(myfileRDirty.good())
	{
		getline(myfileRDirty,xBeen);
		getline(myfileRDirty,yBeen);
		xB = atoi(xBeen.c_str());
		yB = atoi(yBeen.c_str());
		board[xB][yB] = 'd';
	}
	myfileRDirty.close();
	
	ifstream myfileR ("been.txt");
	while(myfileR.good())
	{
		getline(myfileR,xBeen);
		getline(myfileR,yBeen);
		xB = atoi(xBeen.c_str());
		yB = atoi(yBeen.c_str());
		board[xB][yB] = '-';
	}
	myfileR.close();
	
    for(int i=0;i<5;i++)
	    cerr << board[i] << endl;
	
    vector <int> DxCoord;
    vector <int> DyCoord;
    vector <int> Ddist;
    vector <int> OxCoord;
    vector <int> OyCoord;
    vector <int> Odist;

    for(int x=0;x<5;x++)        //top to bottom
        for(int y=0;y<5;y++)    //left to right
        {
            if(board[x][y]=='d')
            {
                DxCoord.push_back(x);
                DyCoord.push_back(y);
                Ddist.push_back(abs(posx-x)+abs(posy-y));
            }
            else if(board[x][y]=='o')
            {
				OxCoord.push_back(x);
                OyCoord.push_back(y);
                Odist.push_back(abs(posx-x)+abs(posy-y));
			}
            
        }
    
    int DminDistIndex = 0;
    int OminDistIndex = 0;
    
    if(Odist.empty())
        Odist.push_back(200);
    if(Ddist.empty())
        Ddist.push_back(200);

    DminDistIndex = distance(Ddist.begin(), min_element(Ddist.begin(), Ddist.end()));
    OminDistIndex = distance(Odist.begin(), min_element(Odist.begin(), Odist.end()));
    
    
    int newX=-1,newY=-1;
    if(Ddist[DminDistIndex] <= Odist[OminDistIndex])
    {
		newX = DxCoord[DminDistIndex];
		newY = DyCoord[DminDistIndex];
	}
	else
	{
		newX = OxCoord[OminDistIndex];
		newY = OyCoord[OminDistIndex];
	}
    
    cerr << newX << " " << newY << endl;

    if (newX<posx)
		cout << "UP" << endl;
	else if (newX>posx)
		cout << "DOWN" << endl;
	else if (newY<posy)
		cout << "LEFT" << endl;
	else if (newY>posy)
		cout << "RIGHT" << endl;
	else
		cout << "UP"
}

/* Tail starts here */
gitint main() {
    int pos[2];
    vector <string> board;
    cin>>pos[0]>>pos[1];
    for(int i=0;i<5;i++) {
        string s;cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
