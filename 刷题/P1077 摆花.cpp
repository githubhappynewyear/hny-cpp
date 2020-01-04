#include<bits/stdc++.h>
using namespace std;

int n,m,a[101],f[101][101][101],ans=0,x,y,z;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
	scanf("%d",&a[i]); 
    for (int i=0;i<=n;i++)
        f[0][i][0]=1;
    for (int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            for (int k=0;k<=min(a[j],i);k++){
                if (k>1) f[i][j][k]=f[i-1][j][k-1];
                    else
					for(int z=0;z<=min(a[j-1],i-k);z++) f[i][j][k]+=f[i-k][j-1][z],f[i][j][k]%=1000007;
            }
    for (int i=0;i<=min(m,a[n]);i++)
        ans+=f[m][n][i],ans%=1000007;
    printf("%d",ans);
    return 0;
}
