#include<bits/stdc++.h>
using namespace std;
 
int n,record;
double x,ansv,answ,w[21],v[21],maxans;
 
int main()
{
    cin>>x>>n;
    for (int i=1;i<=n;i++) cin>>w[i]>>v[i];
    int num=1<<n;
    for (int i=0;i<num;i++)
    {
        int tmp=1;
        ansv=answ=0;
        for (int j=0;j<n;j++)
        {
            if (((tmp<<j)&i)>0)
            {
                ansv+=v[j+1];
                answ+=w[j+1];
            }
            if (answ>x) break;
        }
        if (answ>x) continue;
        if (ansv>maxans)
        {
            maxans=ansv;
            record=i;
        }
    }
    cout<<int(maxans)<<endl;
    int tmp=1;
    for (int j=0;j<n;j++)
    {
        if (((tmp<<j)&record)>0) cout<<j+1<<" ";
    }
    return 0;
}
