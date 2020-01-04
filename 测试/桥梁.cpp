//https://blog.csdn.net/wjiangchengjia/article/details/95523541 
#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
const int Max=2000010;
long long fa[Max];
long long first[Max],next[Max],from[Max],to[Max],tot[Max],ans[Max];//tot为以i为fa的联通块中点个数
long long broke[Max];
void init()
{
	for(int i=1;i<=n;i++){
		fa[i]=i;
		tot[i]=1;
	}
}
int findfa(long long x) {return fa[x]==x?x:fa[x]=findfa(fa[x]);}
void mergefa(long long a,long long b)
{
	long long t1=findfa(a),t2=findfa(b);
	if(t1!=t2) fa[t2]=t1;
}
void build(long long u,long long v)
{
	next[++cnt]=first[u];
	first[u]=cnt;
	to[cnt]=v;
	from[cnt]=u;
}
int main()
{
	cin>>n>>m;
	init(); 
	for(int i=1;i<=m;i++){
		long long a,b; cin>>a>>b;
		build(a,b);
	}
	ans[m+1]=n*(n-1)/2;
	for(int i=m;i>=1;i--)
	{
	//	for(int j=1;j<=n;j++)
	//		cout<<fa[j]<<' ';
	//	cout<<endl;
		long long a=findfa(from[i]),b=findfa(to[i]);
		if(a!=b){
		mergefa(from[i],to[i]);
		ans[i]=ans[i+1]-(long long)(tot[a]*tot[b]);
		tot[findfa(from[i])]=tot[a]+tot[b];
		}
		else
			ans[i]=ans[i+1];
	}
	for(int i=2;i<=m+1;i++)
		cout<<ans[i]<<endl;
	return 0;
}



