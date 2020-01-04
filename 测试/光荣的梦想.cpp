#include<bits/stdc++.h>
using namespace std;

long long ans=0;
int a[500005],r[500005],n;

inline void zql(int s,int mid,int t)
{
    int k=s;
    int i=s;
    int j=mid+1;
    while(i<=mid&&j<=t)
        if(a[i]>a[j])
        {
            r[k++]=a[j++];
            ans=ans+(mid+1-i);
        }
        else
            r[k++]=a[i++];

    while(i<=mid)
        r[k++]=a[i++];
    while(j<=t)
        r[k++]=a[j++];

    for(i=s;i<=t;i++)
        a[i]=r[i];
}

inline void gl(int s,int t)
{
    if(s<t)
    {
        int mid=(s+t)/2;
        gl(s,mid);
        gl(mid+1,t);
        zql(s,mid,t);
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    gl(1,n);
    cout<<ans<<endl;
    return 0;
}
