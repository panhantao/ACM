#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

int n,m;
int arr[2][3005];

bool chk()
{	
	for(int i = 1; i < m; i ++)
	{
		int s = arr[0][i]+arr[0][i-1]+arr[1][i]+arr[1][i-1];
		if(s == 3) return false;
	}
	return true;
}

int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		for(int i = 0; i < m; i ++) scanf("%d",&arr[0][i]);
		
		if(n == 1) { printf("Yes\n"); continue; };
		
		bool jud = true;
		for(int i = 1; i < n; i ++)
		{
			for(int j = 0; j < m; j ++) scanf("%d",&arr[1][j]);
			if(jud)
			{
				jud = chk();
				memcpy(arr[0],arr[1],sizeof(arr[1]));
			}
		}
		
		if(jud) printf("Yes\n");
		else printf("No\n");
	}
}
