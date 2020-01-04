#include<bits/stdc++.h>
#define maxn 10000005
using namespace std;

struct node
{
    int x,y;
    int s1,s2;
    bool operator <(const node& b) const
    {
    return s1<b.s1;
    }
}a[100005];

int main()
{
    int x1,x2,y1,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].s1=(a[i].x-x1)*(a[i].x-x1)+(a[i].y-y1)*(a[i].y-y1);
            a[i].s2=(a[i].x-x2)*(a[i].x-x2)+(a[i].y-y2)*(a[i].y-y2);
    }
    sort(a+1,a+n+1);
    int rb=0,ans=maxn;
    for(int i=n;i;i--)
    {
        rb=max(rb,a[i+1].s2);
        ans=min(ans,a[i].s1+rb);
    }
    printf("%d",ans);
    return 0;
}
