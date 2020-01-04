#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a[6];
    int b,ans=0;
    cin>>b;
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=6;j++)
        cin>>a[j];
        if(!(a[1]=='A'||a[1]=='B'||a[1]=='C'||a[1]=='D'||a[1]=='E'||a[1]=='F'||a[1]=='G'||a[1]=='R'||a[1]=='S'||a[1]=='T'))
        {
        	ans++;
        }
    }
    cout<<ans;
    return 0;
    }
