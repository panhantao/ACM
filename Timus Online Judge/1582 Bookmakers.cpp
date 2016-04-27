#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	double k1,k2,k3;
	while(scanf("%lf%lf%lf",&k1,&k2,&k3) != EOF)
	{
		double ans = (1000.0*k2) / (k2/k1+k2/k3+1.0) + 0.5;
		printf("%d\n",(int)ans);
	}
}
