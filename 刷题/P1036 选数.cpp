//Happynewyear 2019/2/7 12:51
#include<bits/stdc++.h>
using namespace std;

int x[20],n,k;

bool isprime(int n)
{
    int s=sqrt(double(n));
    for(int i=2;i<=s;i++)
    {
        if(n%i==0)return false;
    }
    return true;
}

int rule(int choose_left_num,int already_sum,int start,int end)
{
    if(choose_left_num==0)return isprime(already_sum);
    int sum=0;
    for(int i=start;i<=end;i++)
    {
        sum+=rule(choose_left_num-1,already_sum+x[i],i+1,end);
    }
    return sum;
}

int main()
{
    cin>>n>>k;
    for(int i =0;i<n;i++)cin>>x[i];
    cout<<rule(k,0,0,n-1);
}
