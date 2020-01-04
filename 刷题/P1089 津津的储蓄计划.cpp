//Happynewyear 2019/2/5 21:45
//https://www.luogu.org/discuss/show/98519 
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,i;
    c=0;b=0;
    for(i=1;i<=12;i++)
    {
        c=c+300;
        scanf("%d",&a);
        if(c<a)
        {
            printf("-%d",i);
            return 0;
        }  
        while(c-a>=100)
        {
            c=c-100;
            b++;
        }
    c=c-a;
    }
    b=b*100*1.2;
    printf("%d",b+c);
    return 0;
}
