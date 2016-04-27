#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	long n;
	cin >> n;
	
	string str = "";
	
	if(n == 1) { cout<< 1 << endl; return 0; }
	if(n == 0) { cout<< 10 << endl; return 0; }
	
	while(n != 1)
	{
		for(int i = 2;;i ++)
			if(n % i == 0)
			{
				if(i > 9) { cout << -1 << endl; return 0; }
				str += i + '0';
				n /= i;
				break;
			}
	}

	sort(str.begin(),str.end());
	
	int pos;
	
	pos = str.find("33");
	while(pos != -1) { str.erase(pos,2); str += '9';pos = str.find("33"); }

	pos = str.find("222");
	while(pos != -1) { str.erase(pos,3); str += '8';pos = str.find("222"); }

	pos = str.find("23");
	while(pos != -1) { str.erase(pos,2); str += '6';pos = str.find("23"); }

	pos = str.find("22");
	while(pos != -1) { str.erase(pos,2); str += '4';pos = str.find("22"); }
	
	sort(str.begin(),str.end());
	
	cout<<str<<endl;
	
	//system("pause");
}
