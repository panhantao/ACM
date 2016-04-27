#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

vector<int> graph[105];
int in[105] = {0};

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 1; i <= n; i ++)
	{
		int tmp;
		while(scanf("%d",&tmp) && tmp)
		{
			graph[i].push_back(tmp);
			in[tmp] ++;
		}
	}
	
	// topsort
	
	int done = 0;
	while(done < n)
	{
		for(int i = 1; i <= n; i ++)
		{
			if(in[i] == 0)
			{
				in[i] = -1;
				printf("%d ",i);
				done ++;
				for(int j = 0; j < graph[i].size(); j ++)
					in[ graph[i][j] ] --;
				//break;
			}
		}
	}
	//system("pause");
}
