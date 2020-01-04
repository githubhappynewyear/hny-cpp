#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("clue.in","r",stdin);
	//freopen("clue.out","w",stdout);
	int K,X;
	cin>>K>>X;
	for(int i=X-K+1;i<X+K;i++)
		cout<<i<<" "; 
	return 0;
}
