#include<bits/stdc++.h>
using namespace std;

int T,n,a[100005],m; 

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		priority_queue<int,vector<int>,greater<int> >small;
		priority_queue<int>big;
		//priority_queue<int,vector<int>,less<int> >big;
		
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		
		sort(a,a+n);
		int i,t;
		if(n&1)
			for(i=0;i<n/2+1;i++) big.push(a[i]);
		else
			for(i=0;i<n/2;i++) big.push(a[i]);
		
		for(;i<n;i++) small.push(a[i]);
		cin>>m;
		string o;
		while(m--)
		{
			cin>>o;
			if(o[0]=='a')
			{
				cin>>t;
				if(t<big.top()) big.push(t);
				else small.push(t);
				
				if(big.size()>small.size()+1)
				{
					int h=big.top();
					small.push(h);
					big.pop(); 
				}
				else if(big.size()<small.size())
				{
					int k=small.top();
					big.push(k);
					small.pop();
				}
			}
			else
			cout<<big.top()<<endl;
		}
	}
	return 0;
}
