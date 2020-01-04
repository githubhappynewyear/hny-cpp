#include<bits/stdc++.h>
using namespace std;

int n,a[501][501],ma=0;

int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;i++)
        for(register int j=i+1;j<=n;j++)
        {
            scanf("%d",&a[i][j]); 
            a[j][i]=a[i][j];
        }
    for(register int i=1;i<=n;i++)
    {
        sort(a[i]+1,a[i]+n+1);
        ma=ma>a[i][n-1]?ma:a[i][n-1];
    }
    printf("1\n%d",ma);
    return 0;
}
