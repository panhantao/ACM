#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int i = 1000000;
	while(i --)
		printf("%c",rand()%26+'a');
}
