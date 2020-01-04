//Happynewyear 2019/2/6 10:52
#include<bits/stdc++.h>
using namespace std;

int ans=0;
long double x,s=2,d=0;

int main()
{
    cin>>x;
    while(d<x)
      {
          d+=s;
          s=s/100*98;
          ans++;
      }
    cout<<ans<<endl;
    return 0;
}
