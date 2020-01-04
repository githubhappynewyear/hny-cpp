#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,a,b,c,s;
    cin>>x;
    a=x/100%10;
    b=x/10%10;
    c=x/1%10;
    s=a+b+c;
    cout<<s<<endl;
    return 0;
}
