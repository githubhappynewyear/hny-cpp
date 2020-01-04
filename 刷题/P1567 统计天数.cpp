//Happynewyear 2019/2/7 12:44 
#include<bits/stdc++.h>
using namespace std;

long long a[10000002];

int main()
{
    int n,sum=1,ans=0;
    scanf("%d",&n);
    a[n+1]=-1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=2;i<=n+1;i++)
    {
        if(a[i]<a[i-1])
        {
            ans=max(sum,ans);
            sum=1;
        }
        else
        sum++;
    }
    printf("%d",ans);
    return 0;
}
