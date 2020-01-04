#include<bits/stdc++.h>
using namespace std;

long long i,j,n,p,cou[1000005],ans,a[1000005],dp[1000005],f;//dp[i]:到a[i]的最大值
int main()
{
    cin>>n>>p;
    ans=-1<<30;
    for(i=1;i<=n;++i) 
    {
        cin>>a[i];
    }
    dp[1]=a[1];
    cou[1]=a[1]; 
    for(i=2;i<=n;++i)
    {
        dp[i]=max(dp[i-1]+a[i],a[i]);
    }
    for(i=2;i<=n;++i)
    {
        dp[i]=max(dp[i],dp[i-1]);
    }
    cou[2]=cou[1]+dp[1];
    ans=cou[1];
    for(i=3;i<=n;++i)
    {
        if(dp[i-1]+cou[i-1]<0&&cou[i-1]>0) f=1;
        if(f==1)
        {
            cou[i]=(cou[i-1]%p+dp[i-1])%p;
        }
        else 
        {
            cou[i]=max(cou[i-1]+dp[i-1],cou[i-1]);
        }
        ans=max(ans,cou[i]);
    }
    if(f==1) cout<<cou[n]%p<<endl;
    else cout<<ans%p<<endl;
    return 0;
}
