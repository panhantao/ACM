#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<functional>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;

#define ptf             printf
#define sf              scanf
#define Fin(s)          freopen(s,"r",stdin)
#define Fout(s)         freopen(s,"w",stdout)
#define MS(x,val)       memset(x,val,sizeof(x))
#define pb(x)           push_back(x)
#define pf(x)           push_front(x)
#define mp              make_pair
#define MI(a,b)         a<b ? a:b
#define MX(a,b)         a<b ? b:a
#define LL              long long
#define PI              3.1415926535

struct Point
{
	int x,y;
	Point(int xx=0,int yy=0)
	{
		x = xx; y = yy;
	}
}ori;

int n;
string fst;
bool v[15][15];

int conv(string str)
{
	int s = 0,ten = 1;
	for(int i = str.length()-1; i >= 0; i --)
	{
		s += (str[i]-'0')*ten;
		ten *= 10;
	}
	return s;
}

void getoxy()
{
	string str = "";
	for(int i = 0; i < fst.length(); i ++)
	{
		if(fst[i] == ' ')
		{
			ori.x = conv(str);
			str = "";
		}
		else str += fst[i];
	}
	ori.y = conv(str);
}

bool cmp(Point a,Point b)
{
	if(a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

void bfs1()
{
	vector<Point> ans; ans.pb(ori);
	queue<Point> que; que.push(ori); 
	
	while(cin >> fst && fst != ".")
	{
		Point now = que.front();
		que.pop();
		for(int i = 0; i < fst.length()-1; i ++)
		{
			Point next = now;
			if(fst[i] == 'R') next.x ++;
			else if(fst[i] == 'T') next.y ++;
			else if(fst[i] == 'L') next.x --;
			else next.y --;
			ans.pb(next);
			que.push(next);
		}
	}
	
	sort(ans.begin(),ans.end(),cmp);
	
	ptf("%d\n",ans.size());
	for(int i = 0; i < ans.size(); i ++) ptf("%d %d\n",ans[i].x,ans[i].y);
}

const int tox[] = {1,0,-1,0};
const int toy[] = {0,1,0,-1};
const char mark[] = {'R','T','L','B'};

void bfs2()
{
	queue<Point> que;
	que.push(ori);
	v[ori.x][ori.y] = false;
	vector<string> ans;
	
	while(!que.empty())
	{
		Point now = que.front();
		string str = "";
		que.pop();
		
		for(int i = 0; i < 4; i ++)
		{
			Point next = now;
			next.x += tox[i]; next.y += toy[i];
			if(v[next.x][next.y])
			{
				str += mark[i];
				que.push(next);
				v[next.x][next.y] = false;
			}
		}
		str += ',';
		ans.pb(str);
	}
	
	ans[ans.size()-1] = ".";
	ptf("%d %d\n",ori.x,ori.y);
	for(int i = 0; i < ans.size(); i ++) cout<<ans[i]<<endl;
}

int main()
{
	getline(cin,fst);
	
	if(fst.length() > 2)
	{
		getoxy();
		bfs1();
	}
	else
	{
		MS(v,false);
		n = conv(fst);
		for(int i = 0; i < n; i ++)
		{
			int x,y;
			sf("%d %d",&x,&y);
			v[x][y] = true;
			if(i == 0)
			{
				ori.x = x; ori.y = y;
			}
		}
		bfs2();
	}
	//system("pause");
}
