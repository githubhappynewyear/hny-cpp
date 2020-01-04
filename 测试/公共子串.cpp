//https://blog.csdn.net/wjiangchengjia/article/details/98512081
#include<bits/stdc++.h>
using namespace std;
int n,d;
string s[35];
bool ok(int len)
{
	for(int i=2;i<=n;i++)
	{
		bool m=false;
		for(int j=0;j+len-1<d;j++)
		{
			bool ok=true;
			for(int k=0;k<len;k++)
				if(s[0][k]!=s[i][j+k])
				{
					ok=false;
					break;
				}
			if(ok==true) m=true;
		}
		if(!m) return false;
	}
	return true;
} 
int main()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int len=d;len>=1;len--)
	{
		for(int i=0;i+len-1<d;i++)
		{
			s[0]="";
			for(int j=i;j<i+len;j++) s[0]+=s[1][j];
			if(ok(len)==true)
			{
				cout<<len<<endl;
				return 0;
			}
		}
	}
	puts("0");
	return 0;
}
/*
3 6
aabcab
abcaab
bcabca 
*/

