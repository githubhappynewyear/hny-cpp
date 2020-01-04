#include<bits/stdc++.h>
using namespace std;

int n,m,type,pos,value,a[2001];

void Insert(int pos,int value)
{
	for(int i=n;i>=pos;i--)
		a[i+1]=a[i];
	a[pos]=value;
	n++;
}

void Delete(int pos)
{
	for(int i=pos+1;i<=n;i++)
		a[i-1]=a[i];
	n--;
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>type>>pos;
		if(type==1)
			cout<<a[pos]<<endl;
		if(type==2)
		{
			cin>>value;
			Insert(pos,value); 
		}
		if(type==3) Delete(pos);
	}
	return 0;
}
