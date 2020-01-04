//Happynewyear 2019/2/6 13:31 
#include<bits/stdc++.h>
using namespace std;

int n,x,y,s,minx=0x7fffffff;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=3;i++) 
    {
        scanf("%d%d",&x,&y);
        s=(n/x+(n%x!=0))*y;
        if (s<minx) minx=s;
    }
    printf("%d\n",minx);
    return 0;
}
