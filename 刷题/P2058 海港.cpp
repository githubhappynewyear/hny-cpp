#include<bits/stdc++.h>
using namespace std;
#define maxx 100007
#define maxk 300007
struct node{
    int t,k;
}q[maxk];
int n,f=1,r,ans[maxx],k,t,x,gg,aans;

inline void Init()
{
    scanf("%d",&n);
}
inline void Work()
{
    for(register int i=1;i<=n;i++)
    {
        scanf("%d%d",&t,&k);
        for(register int j=1;j<=k;j++)
        {
            scanf("%d",&x);
            q[++r]=(node){t,x};
            if(!ans[x])
                aans++;
            ans[x]++;
        }
        while(f<=r&&t-q[f].t>=86400)
        {
            ans[q[f].k]--;
            if(!ans[q[f].k])
                aans--;
            f++;
        }
        printf("%d\n",aans);
    }
}

int main()
{
    Init();
    Work();
    return 0;
}
