#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory.h>
#include<algorithm>
#include<functional>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;

#define ptf             printf
#define sf              scanf
#define Fin(s)          freopen(s,"r",stdin)
#define Fout(s)         freopen(s,"w",stdout)
#define MS(x,val)       memset(x,val,sizeof(x))
#define pb(x)           push_back(x)
#define pf(x)           push_front(x)
#define mp              make_pair
#define MI(a,b)         a<b ? a:b
#define MX(a,b)         a<b ? b:a
#define LL              long long
#define PI              3.1415926535

const double eps = 1e-8;

double getArea(double a,double b,double c)
{
	double p = 0.5*(a+b+c);
	return 0.25*c*c + sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
	double a,b;
	while(sf("%lf%lf",&a,&b) != EOF)
	{
		double l,r,midarea,midmidarea;
		l = sqrt(a*a+b*b); r = a+b;
		
		while(l+eps < r)
		{
			double mid = (l+r)/2;
			double midmid = (mid+r)/2;
			
			midarea = getArea(a,b,mid);
			midmidarea = getArea(a,b,midmid);
			
			if(midarea >= midmidarea) r = midmid;
			else l = mid;
		}
		
		ptf("%.6lf\n",midarea);
	}
}
