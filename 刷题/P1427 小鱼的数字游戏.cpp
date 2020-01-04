//Happynewyear 2019/2/7 12:38
#include<bits/stdc++.h>
using namespace std;

int i=0,a[105];

int main()
{
    do 
    {
        ++i;
        cin>>a[i];
    }while(a[i]!=0);
    for (int j=i-1;j>=1;j--) cout<<a[j]<<" ";
    return 0;
}
