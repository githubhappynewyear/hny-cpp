#include<bits/stdc++.h>
using namespace std;

char a[101];
int b[101],sum[101],k;
bool c[101];

int cmp(int x,int y)
{
    if(x>y) return 1;
    else return 0;
}

int ps(int x)
{ 
    if(x==1) return 0;
    if(x==2) return 1;
    int j=2;
    while(j<=sqrt(x)&&x%j!=0) j++;
    if(x%j==0) return 0;
    else return 1;
}

int main()
{
    cin>>a;
    int len=strlen(a);
    for(int i=0;i<len;i++)
     b[i+1]=a[i];
    for(int i=1;i<=len;i++)
      if(c[b[i]]==0)
       {
        for(int j=i;j<=len;j++)
         if(b[i]==b[j]) 
          sum[i]++;
        c[b[i]]=1; 
        k++;    
       }
    sort(sum+1,sum+len+1,cmp);
    if(ps(sum[1]-sum[k]))
     cout<<"Lucky Word"<<endl<<sum[1]-sum[k];
    else
     cout<<"No Answer"<<endl<<"0";
    return 0;
}
