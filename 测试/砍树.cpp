#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;

int h[maxn+10],n,ans;

int main()
{
    memset(h,255,sizeof(h));
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(h[a]!=-1)
        {
            ans+=h[a]+b;
            h[a]=0;
        }
        else
        {
            h[a]=b;
        }
    }
    for(int i=0;i<=maxn;i++)
    {
        int r=h[i];
        if(h[i]!=-1)
        {
            for(int j=std::max(i-h[i],0);j<=std::min(i+h[i],maxn);j++)
            {
                if((h[j]!=-1)&&(j!=i))
                {
                    r=std::min(r,abs(j-i));
                }
            }
        }
        ans+=h[i]-r;
    }
    printf("%d\n",ans);
    return 0;
}
