#include<bits/stdc++.h>
using namespace std;

int a,b; 

int main()
{
	cin>>a>>b;
	if(a%4==0&&a%100!=0||a%400==0)
	{
		if(b==2) 
			cout<<"29"<<endl;
		else if(b==1 || b==3 || b==5 || b==7 || b==8 || b==10 || b==12)
			cout<<"31"<<endl; 
		else if(b==4 || b==6 || b==9 || b==11)
			cout<<"30"<<endl;
	}
	else
	{
		if(b==2) 
			cout<<"28"<<endl;
		else if(b==1 || b==3 || b==5 || b==7 || b==8 || b==10 || b==12)
			cout<<"31"<<endl; 
		else if(b==4 || b==6 || b==9 || b==11)
			cout<<"30"<<endl;
	}
	return 0;
}
