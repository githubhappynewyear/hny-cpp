#include<bits/stdc++.h>
using namespace std;
const int M=400005;
int a[M],b[M],ans[M],r,f,n;
priority_queue<int>dui;
char c;
int read()
{
    r=0;f=1;
    c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c))r=(r<<1)+(r<<3)+c-'0',c=getchar();
    return r;
}
void in()
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    a[i]=read();
    for(int i=1;i<=n;++i)
    b[i]=read();
}
void out(int x)
{
    if(x>9)out(x/10);
    putchar(x%10+'0');
}
void ac()
{
    for(int i=1;i<=n;++i)
    dui.push(a[1]+b[i]);
    for(int i=2;i<=n;++i)
    for(int j=1;j<=n;++j)
    {
        if(a[i]+b[j]>dui.top())break;
        if(a[i]+b[j]<dui.top())
        dui.pop(),dui.push(a[i]+b[j]);
    }
    for(int i=1;i<=n;++i)
    ans[i]=dui.top(),dui.pop();
    for(int i=n;i>=1;--i)
    out(ans[i]),putchar(10);
}
int main()
{
    in();ac();
    return 0;
}
