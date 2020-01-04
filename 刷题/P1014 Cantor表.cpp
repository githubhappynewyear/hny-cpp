//Happynewyear 2019/2/7 13:10
#include<bits/stdc++.h>
using namespace std;

long long l=1,r,mid,n,a;

int main()
{
    cin>>n;
    r=n;
    while(l<r)
    {
        mid=(l+r)/2;
        if(mid*(mid+1)/2<n)
        {
            l=mid+1;
        }
        else
            r=mid;
    }
    a=n-l*(l-1)/2;
    
    if(l%2==0)
    {
        cout<<a<<'/'<<l+1-a;
    }
    else
        cout<<l+1-a<<'/'<<a;
    return 0;
}
