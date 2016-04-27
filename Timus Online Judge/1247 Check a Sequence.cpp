#include<iostream>
#include<cstdio>
using namespace std;

int s,n;
int arr[30005];

// A[i]+A[i+1]+...+A[j] <= (j-i+1)+N equals
// A[i]-1 + A[i+1]-1 +...+ A[j]-1 <= N

int maxseq()
{
	int best = -10, tmp = 0;
	for(int i = 0; i < s; i ++)
	{
		tmp += arr[i];
		if(tmp < 0) tmp = 0;
		if(tmp > best) best = tmp;
	}
	return best;
}

int main()
{
	while(scanf("%d%d",&s,&n) != EOF)
	{
		for(int i = 0; i < s; i ++)
		{
			scanf("%d",&arr[i]);
			arr[i] --;
		}
		
		int s = maxseq();
		
		if(s <= n) printf("YES\n");
		else printf("NO");
	}
}
