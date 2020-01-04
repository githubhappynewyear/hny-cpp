//https://blog.csdn.net/wjiangchengjia/article/details/98511256
//https://www.luogu.org/record/23834397
#include<bits/stdc++.h>
using namespace std;
int j,n,s,a,num;
int len[200002];
int read()
{
    int i=0,f=1;
    char ch;
    for(ch=getchar();!isdigit(ch)&&ch!='-';ch=getchar());
    if(ch=='-')
    {
        f=-1;
        ch=getchar();
    }
    for(;isdigit(ch);ch=getchar())
      i=(i<<3)+(i<<1)+ch-'0';
    return i*f;
}
bool comp(const int &a,const int &b)
{
	return a>b; 
}
int find(int low,int high)
{
	int mid,data;
	data=len[low-1];
	while(low<=high)
	{
		mid=(low+high)>>1;
		if(len[mid]+data<=s) high=mid-1;
		else low++;
	}
	return low;
}
int main()
{
	n=read();s=read();
	for(int i=1;i<=n;i++) len[i]=read();
	sort(len+1,len+1+n,comp);
	int sum=0;
	a=1;
	while(len[a]>=s) a++;
	for(int i=a;i<=n-1;i++)
	{
		j=find(i+1,n);
		sum+=(n-j+1);
	}
	cout<<sum<<endl;
	return 0;
}


