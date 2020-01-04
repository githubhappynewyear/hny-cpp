#include<bits/stdc++.h>
using namespace std;

const int y[2][9]={{0,-2,-1,1,2,2,1,-1,-2},{0,1,2,2,1,-1,-2,-2,-1}};
long long dp[21][21]={1};
bool x[21][21];

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    for(int i=0;i<9;++i)
        if(c+y[0][i]>=0&&c+y[0][i]<=a&&d+y[1][i]>=0&&d+y[1][i]<=b)
            x[c+y[0][i]][d+y[1][i]]=1;
    for(int i=0;i<=a;++i)
        for(int j=0;j<=b;++j)
        {
            if(i)
                dp[i][j]+=dp[i-1][j];
            if(j)
                dp[i][j]+=dp[i][j-1];
            dp[i][j]*=!x[i][j];
        }
    printf("%lld",dp[a][b]);
    return 0;
}
