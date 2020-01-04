#include<bits/stdc++.h>
using namespace std;

const int S=1005;
long long b[S],x[S],tmp[S],xc[S];
int n,q;

int main()
{
    cin>>n>>q;
    for (int i=1;i<=S;i++)
        tmp[i]=1;
    for (int i=1;i<=n;i++)
        cin>>b[i];
    sort(b,b+n+1);
    for (int i=1;i<=q;i++)
	{
        cin>>xc[i]>>x[i];
        for (int j=1;j<=xc[i];j++)
            tmp[i]*=10;
    }
    for (int i=1;i<=q;i++)
	{
        for (int j=1;j<=n;j++)
            if (b[j]%tmp[i]==x[i])
			{
                cout<<b[j]<<endl;
                break;
            }
            else if (j==n)
			{
                cout<<"-1"<<endl;
                break;
            }    
    }
}
