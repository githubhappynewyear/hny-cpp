//Happynewyear 2019/2/7 12:55
#include<bits/stdc++.h>
using namespace std;

bool isprime(int x)
{
    if(x<2)return false;
    if(x==2)return true;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)return false;
    }
    return true;
}

int l,r,x,y; 
int a[10];
bool b=true;
void go(int x,int k)
{
    if(x==(k+1)/2)
    {
        for(int i=k;i>x;i--)
        {
            a[i]=a[k-i+1];
        }
        int Happynewyear=0;
        for(int i=1;i<=k;i++)
        {
            Happynewyear=Happynewyear*10+a[i];
        }
        if(Happynewyear<l)return;
        if(Happynewyear>r)
        {
            b=false;
            return;
        }
        if(isprime(Happynewyear))cout<<Happynewyear<<endl; 
        return; 
    }
    int i;
    if(x)i=0;
    else i=1;
    for(i=i;i<=9;i++)
    { 
        if(b==false)return; 
        a[x+1]=i;
        go(x+1,k);
    }
    return;
}

int Jameswood(int j)
{
    int b=j,count=0;
    while(b>0)
    {
        b/=10;
        count++;
    }
    return count;
}

int main()
{
    cin>>l>>r;
    x=Jameswood(l);
    y=Jameswood(r);
    for(int i=x;i<=y;i++)
    {
        if(i==1)
        {
            if(l<=5&&r>=5)cout<<5<<endl;
            if(l<=7&&r>=7)cout<<7<<endl;
            continue;
        }
        if(i==2)
        {
            if(l<=11&&r>=11)cout<<11<<endl;
            continue;
        }
        if(i%2==0)continue;
        if(i==9)break; 
        b=true; 
        go(0,i);
    }
    return 0;
}
