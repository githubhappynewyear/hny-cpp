#include<bits/stdc++.h>
using namespace std;

list<int>num[100001];

void fun(int start)
{
	list<int>::iterator it;
	it=num[start].begin();
	for(; it != num[start].end(); it++)
	{
		printf("%d ",*it);
	}
}

int main () {

	int m,n,i,a,b;
	cin>>n>>m;

	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		num[a].push_back(b);
		num[b].push_back(a);
	}

	for (i=1;i<=n;i++)
	{
		fun(i);
		printf("\n");
	}
	return 0;
}
