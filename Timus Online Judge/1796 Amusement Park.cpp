#include<iostream>
#include<cstdio>
using namespace std;

int val[10] = {10,50,100,500,1000,5000};
int note[10],p,sum=0,low,high=0;

int main()
{
	for(int i = 0; i < 6; i ++)
	{
		scanf("%d",&note[i]);
		high += note[i] * val[i];
	}
	
	for(int i = 0; i < 6; i ++)
	{
		if(note[i] != 0)
		{
			low = high-val[i];
			break;
		}
	}
	
	scanf("%d",&p);
	
	printf("%d\n",high/p - low/p);
	for(int i = low/p+1; i <= high/p; i ++)
		printf("%d ",i);
	printf("\n");
	
	system("pause");
}
