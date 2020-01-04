#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0x7fffffff,a[100005],s[100005];
inline bool comp(const int &a,const int &b)
{
    return a>b;
}
void solve(int cur,int maxn)
{
    if(ans<=maxn) return;
    if(cur==n+1)
	{
        if(ans>maxn) ans=maxn;
        return;
    }
    for(int i=1;i<=k;i++)
	{
        if(s[i]+a[cur]<ans)
		{
            s[i]+=a[cur];
            solve(cur+1,max(maxn,s[i]));
            s[i]-=a[cur];
        }
    }
    return;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1,comp);
    for(int i=1;i<=n;i++)
	{
        int minn=0x3f3f3f3f,pos=0;
        for(int j=1;j<=k;j++) if(s[j]<minn) minn=s[pos=j];
        s[pos]+=a[i];
    }
    for(int i=1;i<=n;i++) ans=max(ans,s[i]);
    memset(s,0,sizeof(s));
    solve(1,0);
    printf("%d\n",ans);
    return 0;
}
