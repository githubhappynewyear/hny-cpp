#include<bits/stdc++.h>
using namespace std;
int n,m,a[355]={0},b[5]={0,0,0,0,0},f[41][41][41][41]={0};

int max4(int i,int j,int k,int l)
{
    return max(max(i,j),max(k,l));
}

int dp(int i, int j, int k, int l)
{
    if(i<0||j<0||k<0||l<0)
        return 0;
    else if(f[i][j][k][l])
        return f[i][j][k][l];
    else
	{
        f[i][j][k][l]=max4(dp(i-1,j,k,l),dp(i,j-1,k,l),dp(i,j,k-1,l),dp(i,j,k,l-1));
        f[i][j][k][l]+=a[i+2*j+3*k+4*l+1];
        return f[i][j][k][l];
    }
}
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1,t;i<=m;i++)
	{
        cin>>t;
        b[t]++;
    }
    memset(f,0,sizeof(f));
    f[0][0][0][0]=a[1];
    cout<<dp(b[1],b[2],b[3],b[4]);
    return 0;
}
