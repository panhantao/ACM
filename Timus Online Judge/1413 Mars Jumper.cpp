#include<iostream>
#include<cstdio>
using namespace std;

const double a = 0.707106781186548;

int main()
{
	double x=0,y=0;
	char ch;
	while(scanf("%c",&ch) != EOF)
	{
		if(ch == '0') break;
		else if(ch == '1') { x -= a; y -= a; }
		else if(ch == '2') { y --; }
		else if(ch == '3') { x += a; y -= a; }
		else if(ch == '4') { x --; }
		else if(ch == '6') { x ++; }
		else if(ch == '7') { x -= a; y += a; }
		else if(ch == '8') { y ++; }
		else if(ch == '9') { x += a; y += a; }
	}
	printf("%.10lf %.10lf\n",x,y);
}
