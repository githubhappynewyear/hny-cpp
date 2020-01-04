//Happynewyear 2019/2/7 13:11
#include<bits/stdc++.h>
using namespace std;

double num=0,x=0;
char c,p;
int a[100],l=1,mid,pd;

int main()
{
    memset(a,0,sizeof(a));
    pd=1;
    while(c!='=')
    {
        c=getchar();
        if(c=='-')
            ++l,pd=-1; 
        if(c=='+')
            ++l,pd=1;
        if(c>='0'&&c<='9')
        {
            if(!a[l])
                a[l]=(c-'0')*pd;
            else
                a[l]=a[l]*10+(c-'0')*pd;
        }
        if(c>='a'&&c<='z')
        {
            p=c;
            if(a[l]!=0)
                x+=a[l],a[l]=0;
            else
                x+=pd;
            --l; 
        }
    }
    mid=l,++l,pd=1;
    while(c!='\n')
    {
        c=getchar();
        if(c=='-')
            ++l,pd=-1;
        if(c=='+')
            ++l,pd=1;
        if(c>='0'&&c<='9')
        {
            if(!a[l])
                a[l]=(c-'0')*pd;
            else
                a[l]=a[l]*10+(c-'0')*pd;
        }
        if(c>='a'&&c<='z')
        {
            p=c;
            if(a[l]!=0)
                x-=a[l],a[l]=0;
            else
                x-=pd; 
            --l; 
        }
    }
    for(int i=1;i<=l;++i)
    {
        if(i<=mid)
            num-=a[i];
        else
            num+=a[i]; 
    }
    if(!(num/x))
        printf("%c=0.000",p);
    else
        printf("%c=%.3lf",p,num/x); 
    return 0; 
}
