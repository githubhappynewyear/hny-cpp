#include<bits/stdc++.h>
using namespace std;

char s[5001];int f[5001][5001];int n;
int dfs(int i,int j)
{
    if (f[i][j]!=0xfffffff)
        return f[i][j];
    if (s[i-1]==s[j-1])
        return f[i][j]=dfs(i+1,j-1);
    else
        {
		f[i][j]=min(dfs(i+1,j),dfs(i,j-1))+1;
        }
        return f[i][j];
}
int main()
{
    scanf("%d",&n);
    cin>>s;
    for (int i=1;i<=n;i++)
    {  for (int j=i+1;j<=n;j++)
          f[i][j]=0xfffffff;
        f[i][i]=0;
    }
    f[1][n]=dfs(1,n);
    printf("%d",f[1][n]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
