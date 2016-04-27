#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;

#define eps 1e-10

int n;
double arr[100005];
double averx,avery,a,b;

int main()
{
	while(scanf("%d",&n) != EOF)
	{
		averx = avery = 0.0;
		for(int i = 0; i < n; i ++)
		{
			scanf("%lf",&arr[i]);
			averx += i;
			avery += arr[i];
		}
		averx += eps; avery += eps;
		averx /= n; avery /= n;
		
		double s1 = 0.0, s2 = 0.0;
		for(int i = 0; i < n; i ++)
		{
			s1 += i*arr[i];
			s2 += i*i;
		}
		s1 -= n*averx*avery;
		s2 -= n*averx*averx;
		
		s1 += eps; s2 += eps;
		
		b = s1/s2;
		a = avery - b*averx;
		
		printf("%.6lf %.6lf\n",a,b);
	}
}
