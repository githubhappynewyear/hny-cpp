#include<bits/stdc++.h>
#define in(x) x=read()
#define MAXN 81
#define k m-(R-L)
#define bll __int128
using namespace std;

inline int read() 
{
    int X=0,w=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') w=-1;ch=getchar();}
    while(ch>='0' && ch<='9') X=(X<<3)+(X<<1)+ch-'0',ch=getchar();
    return X*w;
}

int n,m;
int num[MAXN];
bll ans,p[MAXN],f[MAXN][MAXN];

bll dp(int L,int R)
{
    if(f[L][R]!=-1) return f[L][R];
    if(R-L>=1) f[L][R]=max(num[L]*p[k]+dp(L+1,R),dp(L,R-1)+num[R]*p[k]);
    else f[L][R]=num[L]*p[k];
    return f[L][R];
}

void print(bll x)
{
    if(!x) return;
    if(x) print(x/10);
    putchar(x%10+'0');
}

int main()
{
    in(n);in(m);
    p[0]=1;
    for(int i=1;i<=m;i++) p[i]=p[i-1]*2;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) in(num[j]);
        memset(f,-1,sizeof(f));
        ans+=dp(1,m);
    }
    if(!ans) printf("0");
    else print(ans);
    return 0;
}
