#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const char name[] = "Sandro";

int main()
{
	int l,k,h;
	while(scanf("%d%d%d",&l,&k,&h) != EOF)
	{
		if(l%k == 0)
		{
			printf("%.6lf %.6lf\n",1.0*l/k*h,1.0*l/k*h);
		}
		else
		{
			double mx = l/k*h, mi = (l/k+1)*h;
			printf("%.6lf %.6lf",mx,mi);
		}
	}
}
