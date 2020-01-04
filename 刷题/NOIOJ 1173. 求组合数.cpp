#include<bits/stdc++.h>
using namespace std;

const int mod=10007;
int c[1005][1005];

int main()
{
	int n;
	scanf("%d",&n);
	c[0][0]=c[1][0]=c[1][1]=1;
	
	for(int i=2;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		
	while(n--)
	{
		int x,y; scanf("%d%d",&x,&y);
		printf("%d\n",c[x][y]);
	}
	
	return 0;
}
