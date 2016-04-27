#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;

stack<int> sta;
int seq[100005];
int ptr = 0;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i ++) scanf("%d",&seq[i]);
	
	for(int i = 1; i <= n; i ++)
	{
		sta.push(i);
		while(!sta.empty() && sta.top() == seq[ptr])
		{
			sta.pop();
			ptr ++;
		}
	}
	if(sta.empty()) printf("Not a proof\n");
	else printf("Cheater\n");
}
