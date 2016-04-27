#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;

#define pf 				printf
#define sf 				scanf
#define Fin(s)  		freopen(s,"r",stdin)
#define Fout(s) 		freopen(s,"w",stdout)
#define REP(i,o,b,d) 	for(int i = o; i < b; i += d)
#define MS(x,val) 		memset(x,val,sizeof(x))
#define pb(x) 			push_back(x);

template<typename T> T MX(T a,T b) { return a<b ? b:a; }
template<typename T> T MI(T a,T b) { return a<b ? a:b; }

struct Board
{
	int status[5][5],step;
}board;

bool check(const Board &b)
{
	if(b.status[0][0]==1 && b.status[0][1]==1 && b.status[1][0]==1 && b.status[1][1]==1 &&
	b.status[0][2]==2 && b.status[0][3]==2 && b.status[1][2]==2 && b.status[1][3]==2 &&
	b.status[2][0]==4 && b.status[2][1]==4 && b.status[3][0]==4 && b.status[3][1]==4 &&
	b.status[2][2]==3 && b.status[2][3]==3 && b.status[3][2]==3 && b.status[3][3]==3) return true;
	if(b.status[0][0]==4 && b.status[0][1]==4 && b.status[1][0]==4 && b.status[1][1]==4 &&
	b.status[0][2]==1 && b.status[0][3]==1 && b.status[1][2]==1 && b.status[1][3]==1 &&
	b.status[2][0]==3 && b.status[2][1]==3 && b.status[3][0]==3 && b.status[3][1]==3 &&
	b.status[2][2]==2 && b.status[2][3]==2 && b.status[3][2]==2 && b.status[3][3]==2) return true;
	if(b.status[0][0]==3 && b.status[0][1]==3 && b.status[1][0]==3 && b.status[1][1]==3 &&
	b.status[0][2]==4 && b.status[0][3]==4 && b.status[1][2]==4 && b.status[1][3]==4 &&
	b.status[2][0]==2 && b.status[2][1]==2 && b.status[3][0]==2 && b.status[3][1]==2 &&
	b.status[2][2]==1 && b.status[2][3]==1 && b.status[3][2]==1 && b.status[3][3]==1) return true;
	if(b.status[0][0]==2 && b.status[0][1]==2 && b.status[1][0]==2 && b.status[1][1]==2 &&
	b.status[0][2]==3 && b.status[0][3]==3 && b.status[1][2]==3 && b.status[1][3]==3 &&
	b.status[2][0]==1 && b.status[2][1]==1 && b.status[3][0]==1 && b.status[3][1]==1 &&
	b.status[2][2]==4 && b.status[2][3]==4 && b.status[3][2]==4 && b.status[3][3]==4) return true;
	return false;
}

int bfs()
{
	queue<Board> que;
	que.push(board);

	Board now,tmp;
	while(!que.empty())
	{
		now = que.front(); que.pop();
		if(check(now)) return now.step;
		
		tmp = now; tmp.step = now.step+1;
		tmp.status[0][1]=tmp.status[2][0]; tmp.status[2][0]=tmp.status[3][2];
		tmp.status[3][2]=tmp.status[1][3]; tmp.status[1][3]=now.status[0][1];
		que.push(tmp);
		tmp = now; tmp.step = now.step+1;
		tmp.status[2][0]=tmp.status[0][1]; tmp.status[0][1]=tmp.status[1][3];
		tmp.status[1][3]=tmp.status[3][2]; tmp.status[3][2]=now.status[2][0];
		que.push(tmp);
		
		tmp = now; tmp.step = now.step+1;
		tmp.status[0][2]=tmp.status[1][0]; tmp.status[1][0]=tmp.status[3][1];
		tmp.status[3][1]=tmp.status[2][3]; tmp.status[2][3]=now.status[0][2];
		que.push(tmp);
		tmp = now; tmp.step = now.step+1;
		tmp.status[1][0]=tmp.status[0][2]; tmp.status[0][2]=tmp.status[2][3];
		tmp.status[2][3]=tmp.status[3][1]; tmp.status[3][1]=now.status[1][0];
		que.push(tmp);
		
		tmp = now; tmp.step = now.step+1;
		tmp.status[1][1]=tmp.status[2][1]; tmp.status[2][1]=tmp.status[2][2];
		tmp.status[2][2]=tmp.status[1][2]; tmp.status[1][2]=now.status[1][1];
		que.push(tmp);
		tmp = now; tmp.step = now.step+1;
		tmp.status[2][1]=tmp.status[1][1]; tmp.status[1][1]=tmp.status[1][2];
		tmp.status[1][2]=tmp.status[2][2]; tmp.status[2][2]=now.status[2][1];
		que.push(tmp);
		
		tmp = now; tmp.step = now.step+1;
		tmp.status[0][0]=tmp.status[0][3]; tmp.status[0][3]=tmp.status[3][3];
		tmp.status[3][3]=tmp.status[3][0]; tmp.status[3][0]=now.status[0][0];
		que.push(tmp);
		tmp = now; tmp.step = now.step+1;
		tmp.status[0][0]=tmp.status[3][0]; tmp.status[3][0]=tmp.status[3][3];
		tmp.status[3][3]=tmp.status[0][3]; tmp.status[0][3]=now.status[0][0];
		que.push(tmp);
	}
}

int main()
{
	REP(i,0,4,1)
		REP(j,0,4,1)
			sf("%d",&board.status[i][j]);
	board.step = 0;
	
	pf("%d",bfs());
}
