#include<bits/stdc++.h> 
using namespace std;

int main()
{
	int n;
	double p,s;
	cin>>n>>p;
	if(n>100)
	    s=(n-100)*p*0.7+100*p;
	else
	    s=n*p;
	cout<<fixed<<setprecision(2)<<s<<endl;
	return 0;
}
