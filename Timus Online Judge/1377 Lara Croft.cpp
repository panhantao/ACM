#include<iostream>
using namespace std;

bool visited[105][105] = {0};
int tox[] = {0,1,0,-1};
int toy[] = {1,0,-1,0};
int dir = 0;
int row,col,xx1,yy1,xx2,yy2;
int curx,cury;
int n = 0;

bool valid(int x,int y)
{
	if (x >= 1 && x <= row && y >= 1 && y <= col && !visited[x][y])return true;
	else return false;
}

void bfs()
{
	curx = cury = 1;
	while(visited[xx1][yy1]==false || visited[xx2][yy2]==false)
	{
		visited[curx][cury] = true;
		
		if(visited[xx1][yy1] == true || visited[xx2][yy2] == true)n ++;
		
		int nextx = curx + tox[dir%4];
		int nexty = cury + toy[dir%4];
		
		if(!valid(nextx,nexty) || visited[nextx][nexty]) dir ++;
		
		curx += tox[dir%4];
		cury += toy[dir%4];
	}
	n --;
}

int main()
{
	cin >> row >> col >> xx1 >> yy1 >> xx2 >> yy2;
	bfs();
	cout << n << endl;
}