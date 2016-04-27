#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const int INF = 0x2FFFFFF;
const double sqrt2 = 141.421356237;
bool route[1002][1002] = {false};
double dp[3][1002] = {0};
int col,row,r;

int main()
{
	scanf("%d%d%d",&col,&row,&r);
	for(int i = 0; i < r; i ++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		route[x][y] = true;
	}
	
	// DP with compression
	
	for(int i = 1; i <= col; i ++) dp[0][i] = dp[0][i-1]+100;
	
	double a,b,c;
	int now,last;
	for(int i = 1; i <= row; i ++)
	{
		now = i%2,last;
		if(now == 0) last = 1;
		else last = 0;
		for(int j = 0; j <= col; j ++)
		{
			a = dp[last][j]+100;
			
			if(j > 0) b = dp[now][j-1]+100;
			else b = INF;
			
			if(route[j][i]) c = dp[last][j-1]+sqrt2;
			else c = INF;
			
			dp[now][j] = min(a,min(b,c));
		}
	}
	
	int ans = dp[now][col]+0.5;
	if(ans > int(dp[now][col]))
		printf("%d\n",ans);
	else
		printf("%d\n",ans);
	
}
