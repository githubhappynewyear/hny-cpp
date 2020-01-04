#include<bits/stdc++.h>
using namespace std;

int main()
{
	int L,R,len,ans=0;
	scanf("%d%d",&L,&R);
	
	for(int i=L;i<=R;i++)
	{
		int t=i;
		while(t!=0)
		{
			if(t%10==2)ans++;
			t=t/10; 
		}
	}
	printf("%d",ans);
	return 0;
}
