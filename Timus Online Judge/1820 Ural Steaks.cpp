#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k) != EOF)
	{
		if(k >= n) printf("2\n");
		else
		{
			if((2*n)%k == 0) printf("%d\n",2*n/k);
			else printf("%d\n",2*n/k+1);
		}
	}
}
