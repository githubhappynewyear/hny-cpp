#include<bits/stdc++.h>
using namespace std;

string b[1000000];

bool cmp(string a,string b)
{
    return a<b;
}

int main()
{
    int n,l;
    cin>>n>>l;
    for(int i=1;i<=n;++i)
        cin>>b[i];
    sort(b+1,b+1+n,cmp);
    for(int i=1;i<=n;++i)
        cout<<b[i];
    return 0;
}
