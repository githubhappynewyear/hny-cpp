#include<bits/stdc++.h>
using namespace std;

string a;
string s="NOIP@CCF";
char b;

int main()
{
	while(1)
	{
		cin>>b;
		if(b=='Y')
		{
			cin>>a;
			if(a==s)
			{
				cout<<"Success";
				return 0;
			}
			else
				cout<<"Sorry"<<endl;
		}
		else 
			if(b=='N')
				return 0;
	}
	return 0;
}
	
