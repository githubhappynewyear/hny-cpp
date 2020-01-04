#include<bits/stdc++.h>
using namespace std;

int a[40050];
int ans[15050][10];
int t[15050];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
	{
        cin>>a[i];
        t[a[i]]++; 
    }
    for(int i=1;i<=(n-2)/9;i++)
	{
        int sum=0,x=9*i+1;
        for(int xd=9*i+2;xd<=n;xd++)
		{
            int xc=xd-i;
            sum+=t[xd-x]*t[xd-x+2*i];
            ans[xd][4]+=sum*t[xc];
            ans[xc][3]+=sum*t[xd]; 
        }
        sum=0;
        x=n-9*i-1;
        for(int xa=n-9*i-1;xa>=1;xa--)
		{
            int xb=xa+2*i;
            sum+=t[n-(x-xa)]*t[n-(x-xa)-i];
            ans[xa][1]+=sum*t[xb];
            ans[xb][2]+=sum*t[xa];
        }
    }
    for(int i=1;i<=m;i++)
	{
        for(int j=1;j<=4;j++)
		{
            cout<<ans[a[i]][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
