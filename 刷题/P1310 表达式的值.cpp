#include<bits/stdc++.h>
using namespace std;

const int M=10007,N=100005;
int n,i,u[N],v[N],top,k;
char c[N],sta[N],ans[2*N];

int main()
{
    scanf("%d\n%s",&n,c);
    ans[++k]='.';
    for(i=0;c[i];i++)
    {
        if(c[i]=='('||c[i]=='*')
            sta[++top]=c[i];
        if(c[i]=='+')
        {
            while(sta[top]=='*')
                ans[++k]=sta[top--];
            sta[++top]=c[i];
        }
        if(c[i]==')')
        {
            while(sta[top]!='(')
                ans[++k]=sta[top--];
            top--;
        }
        if(c[i]!='('&&c[i]!=')')
            ans[++k]='.';
    }
    while(top>0)
        ans[++k]=sta[top--];
    for(i=1;i<=k;i++)
    {
        if(ans[i]=='.')
        {
            u[++top]=1;
            v[top]=1;
        }
        if(ans[i]=='*')
        {
            top--;
            u[top]=(u[top+1]*v[top]+u[top]*v[top+1]+u[top]*u[top+1])%M;
            v[top]=v[top]*v[top+1]%M;
        }
        if(ans[i]=='+')
        {
            top--;
            v[top]=(u[top+1]*v[top]+u[top]*v[top+1]+v[top]*v[top+1])%M;
            u[top]=u[top]*u[top+1]%M;
        }
    }
    printf("%d",u[1]);
}
