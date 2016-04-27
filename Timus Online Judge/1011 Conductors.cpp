#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	double p,q;
	while(scanf("%lf%lf",&p,&q) != EOF)
	{	
		p += 1e-9; q -=1e-9;
		for(int i = 1;; i ++)
		{
			int pp = int(i*p)/100;
			int qq = int(i*q)/100;
			if(pp != qq)
			{
				printf("%d\n",i);
				break;
			}
		}
	}
}
