#include<bits/stdc++.h>
using namespace std;
#define MAXN 1200000

int a[MAXN],b[MAXN];

int main()
{
	int n,k,p,f=0,tail,q=0;
	cin>>n>>k>>p;
	for(int i=1;i<=k;i++) a[i]=i;
	tail=k;
	for(int i=1;i<=k/n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			f++;
			if(j==n) b[++q]=a[f];
			for(int t=1;t<=p;t++)
			{
				f++;
				a[++tail]=a[f];
			}
		}
	}
	sort(b+1,b+q+1);
	for(int i=1;i<=k/n;i++)
	    cout<<b[i]<<endl;
	return 0;
}
