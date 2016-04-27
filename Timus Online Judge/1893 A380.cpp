#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	char str[5];
	while(scanf("%s",str) != EOF)
	{
		int row,ch;
		if(strlen(str) == 3)
		{
			row = (str[0]-'0')*10 + str[1]-'0';
			ch = str[2];
		}
		else
		{
			row = str[0]-'0';
			ch = str[1];
		}
		
		if(1 <= row && row <= 2)
		{
			if(ch == 'A' || ch == 'D') printf("window\n");
			else printf("aisle\n");
		}
		else if(3 <= row && row <= 20)
		{
			if(ch=='B' || ch=='C' || ch=='D' || ch == 'E') printf("aisle\n");
			else if(ch=='A' || ch=='F') printf("window\n");
			else printf("neither\n");
		}
		else
		{
			if(ch == 'C' || ch=='D' || ch=='G' || ch=='H') printf("aisle\n");
			else if(ch=='A' || ch=='K') printf("window\n");
			else printf("neither\n");
		}
	}
}
