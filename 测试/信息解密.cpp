//Happynewyear 2019/2/10 19:30
#include<bits/stdc++.h>
using namespace std;
const int maxn=10005;
#define ll long long

int a[maxn];
int b[maxn];
int m,n,k;

int getsum(int x)
{
    int l=0,r=n-1;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(b[mid]<=x)
            l=mid+1;
        else
            r=mid-1;
    }
    return l;
}

bool check(int x)
{
    ll ans=0;
    for(int i=0;i<m;i++)
    {
            if(!a[i])
            {
                ans+=n;
                continue;
            }
            int cnt=x/a[i];
            ans+=getsum(cnt);
    }
     return ans>=k;
}

int main()
{
    scanf("%d %d %d",&m,&n,&k);
    for(int i=0;i<m;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    sort(a,a+m);
    sort(b,b+n);
    int l=0;
    int r=a[m-1]*b[n-1];
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid)) r=mid-1;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}
