#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

#define PI 3.1415926535898

int l,r;

int main()
{
	while(scanf("%d%d",&l,&r) != EOF)
	{
		if(r <= l/2) printf("%.3lf\n",PI*r*r);		// 圆被正方形覆盖 
		else if(r*r >= 2*(l/2)*(l/2)) printf("%.3lf\n",1.0*l*l);	// 圆覆盖正方形  
		else		// 两者相交
		{
			double angle = 90-2*(acos(0.5*l/r)*180.0/PI);
			double fana = angle/360*PI*r*r;
			
			double tmpr = sqrt(r*r-0.25*l*l);
			printf("%.3lf\n",4.0*fana + 2.0*tmpr*l);
		}
	}
}
