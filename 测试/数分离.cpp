#include<bits/stdc++.h>
using namespace std;

int digit(long long n,int k)
{
    int tmp;
    for(int i=1;i<=k;i++)
    {
        tmp=n%10;
        n/=10;
    } 
    return tmp;
}

int main()
{
    long long x,y;
    cin>>x>>y;
    cout<<digit(x,y)<<endl;
    return 0;
}
