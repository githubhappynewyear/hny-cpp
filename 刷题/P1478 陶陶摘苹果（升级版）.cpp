//Happynewyear 2019/2/7 12:57
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int apl[5001],pwr[5001],f[5001];
int max_l,n,s,a,b,i,j,k;

int main()
{
    cin>>n>>s;
    cin>>a>>b;
    max_l=a+b;
    for(i=1;i<=n;++i)
    cin>>apl[i]>>pwr[i];
    for(i=1;i<=n;++i)
        for(j=s;j>=pwr[i];--j)
        if(apl[i]<=max_l)
        	f[j]=max(f[j],f[j-pwr[i]]+1);
    cout<<f[s]<<endl;
    return 0;
}
