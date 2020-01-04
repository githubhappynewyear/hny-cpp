#include<bits/stdc++.h>
using namespace std;

int x,y,a[10010],b[10010],g[10010],k[10010],n,p=-1;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i) 
        scanf("%d%d%d%d",&a[i],&b[i],&g[i],&k[i]);
    scanf("%d%d",&x,&y);
    for(int i=1;i<=n;++i) 
        if(a[i]<=x&&(a[i]+g[i])>=x&&b[i]<=y &&(b[i]+k[i])>=y) p=i;
    printf("%d\n",p);
    return 0;
}
