#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char arr[29][2] = {{'a',1},{'b',2},{'c',3},{'d',1},{'e',2},{'f',3},{'g',1},{'h',2},
{'i',3},{'j',1},{'k',2},{'l',3},{'m',1},{'n',2},{'o',3},{'p',1},{'q',2},{'r',3},
{'s',1},{'t',2},{'u',3},{'v',1},{'w',2},{'x',3},{'y',1},{'z',2}};

int main()
{
	string str;
	getline(cin,str);
	int count = 0;
	
	for(int i = 0; i < str.length(); i ++)
	{
		if(isalpha(str[i]))count += arr[str[i] - 'a'][1];
		else if(str[i] == '.' || str[i] == ' ')count ++;
		else if(str[i] == ',')count += 2;
		else if(str[i] == '!')count += 3;
	}
	cout<<count<<endl;
}