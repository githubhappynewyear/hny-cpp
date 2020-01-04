#include<bits/stdc++.h>
using namespace std;
 
const int Maxn=1000;
int Map[Maxn+10][Maxn+10];
bool visited[Maxn+10][Maxn+10];
int n,m;
int ans=0;
int dx[]={0,1,1,0,-1,-1,-1,0,1};
int dy[]={0,0,1,1,1,0,-1,-1,-1};
bool flood(int nx,int ny)

{
	bool flag=true;
	visited[nx][ny]=true;
	for (int i=1;i<=8;i++)
	{
		int x=nx+dx[i],y=ny+dy[i];
		if(!(1<=x && x<=n && 1<=y && y<=m)) continue;
		if(Map[nx][ny]==Map[x][y] && visited[x][y]==false) flag=flag&flood(x,y);
		if(Map[nx][ny]<Map[x][y]) flag=false;
	}
	return flag;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&Map[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(visited[i][j]==false) ans+=flood(i,j);
	printf("%d\n",ans);
	return 0;
} 
