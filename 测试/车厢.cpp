#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,s=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++)
		for(int j=1;j<n-i;j++)
		{
			if(a[j]<a[j-1])
			{
				swap(a[j],a[j-1]);
				s++;
			}
		}
	cout<<s<<endl;
	return 0;
}
