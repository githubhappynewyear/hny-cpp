//Happynewyear 2019/2/7 13:11
#include<bits/stdc++.h>
using namespace std;

char s[100],c[100];

int main()
{
    int n,s=0;
    cin>>n;
    if(n<0)
    {
        cout<<"-";
        n=-n; 
    }
    
    while(n!=0)
    {
        s=s*10+n%10;
        n=n/10;
    }
    cout<<s;
    return 0;
}
