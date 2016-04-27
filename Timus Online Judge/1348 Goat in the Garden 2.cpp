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

int main()
{
	double ax,ay,bx,by,cx,cy,len;
	while(sf("%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&len) != EOF)
	{
		double seglen= sqrt( (ax-bx)*(ax-bx) + (ay-by)*(ay-by) ); 
		double distA = sqrt( (ax-cx)*(ax-cx) + (ay-cy)*(ay-cy) );
		double distB = sqrt( (bx-cx)*(bx-cx) + (by-cy)*(by-cy) );
		
		// lineAB: Ax+By+C=0; d: distance of C to lineAB
		double A,B,C,d;
		if(ax==bx)
		{
			A = 1; B = 0; C = -ax;
			d = fabs(ax-cx);
		}
		else
		{
			A = (ay-by)/(ax-bx); B = -1; C = ay-A*ax;
			d = fabs(A*cx+B*cy+C)/sqrt(A*A+1.0);
		}
		
		// right-angle edge
		double len1 = sqrt(distA*distA - d*d);
		double len2 = sqrt(distB*distB - d*d);
		
		double mi,mx;
		if(len1+len2-seglen <= eps)
		{
			mi = d;
			if(mi < len) mi = 0.0;
			else mi -= len;
			
			mx = MX(distA,distB);
			if(mx < len) mx = 0.0;
			else mx -= len;
		}
		else
		{
			mi = MI(distA,distB);
			if(mi < len) mi = 0.0;
			else mi -= len;
			
			mx = MX(distA,distB);
			if(mx < len) mx = 0.0;
			else mx -= len;
		}
		
		ptf("%.2lf %.2lf\n",mi,mx);
	}
}
