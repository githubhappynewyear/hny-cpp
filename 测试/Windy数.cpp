#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll f[30][20],bit[60];
ll n;

ll dfs(ll pos,ll pre,bool lim)
{
    if(pos<=0) return 1;
    if(!lim&&f[pos][pre]!=-1) return f[pos][pre];
    ll num=lim ? bit[pos] : 9 ;
    ll ans=0,pre_x;
    for(ll i=0;i<=num;i++)
    {
        if(abs(pre-i)>=2)
        {
        	pre_x=i;
      		if(pre==-3&&i==0)pre_x=-3;
       		ans+=dfs(pos-1,pre_x,lim&&i==num);
       }
    }
    if(!lim) f[pos][pre]=ans;
    return ans;
}
ll solve(ll n)
{
    ll len=0;
    while(n)
    {
        bit[++len]=n%10;
        n/=10;
    }
    return dfs(len,-3,1);
}

int main()
{
    memset(f,-1,sizeof(f));
    memset(bit,0,sizeof(bit));
    ll x,y;
    cin>>x>>y;
    cout<<solve(y)-solve(x-1);
}
