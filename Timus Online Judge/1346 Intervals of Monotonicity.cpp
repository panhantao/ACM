#include<iostream>
#include<cstdio>
using namespace std;

int arr[100010];

int main()
{
	int beg,end;
	while(scanf("%d%d",&beg,&end) != EOF)
	{
		end -= beg;
		for(int i = 0; i <= end; i ++) scanf("%d",&arr[i]);
		
		int sta = -1;		// 0-up, 1-down;
		int cnt = 1;
		
		for(int i = 1; i <= end; i ++)
		{
			if(sta == -1)
			{
				if(arr[i] > arr[i-1]) sta = 0;
				if(arr[i] < arr[i-1]) sta = 1;
				continue;
			}
			
			if(arr[i]<arr[i-1] && sta==0)
			{
				cnt ++;
				sta = -1;
			}
			if(arr[i]>arr[i-1] && sta==1)
			{
				cnt ++;
				sta = -1;
			}
		}
		
		printf("%d\n",cnt);
	}
}
