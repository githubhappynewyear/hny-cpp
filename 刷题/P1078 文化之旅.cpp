#include<bits/stdc++.h>
using namespace std;

int n,k,m,s,t,ans=100000000,cnt=0;
int c[200];
int vis[200][200];
int visit[200];

struct node
{
    int to,next,value;
}e[20000];
int head[200];
int que[100000],qh=0,qt=0;

bool inq[1000];

int dist[1000];

void add(int u,int v,int w)
{
    e[++cnt].to=v;
    e[cnt].value=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}

void spfa()
{
    memset(dist,0x7f7f7f,sizeof(dist));
    dist[n]=0;
    que[++qt]=n;
    while(qh<qt)
    {
        int p=que[++qh];
        inq[p]=false;
        for(int i=head[p];i;i=e[i].next)
        {
            if(dist[e[i].to]>dist[p]+e[i].value)
            {
                dist[e[i].to]=dist[p]+e[i].value;
                if(!inq[e[i].to])
                {
                    inq[e[i].to]=true;
                    que[++qt]=e[i].to;
                }
            } 
        }
    }
}

void dfs(int u,int step)
{
    bool pp=false;
    if(u==t)
    ans=min(ans,step);
    if(step>=ans)
    return;
    visit[c[u]]=true;
    for(int i=1;i<=k;i++)
    if(vis[i][c[u]]) visit[i]=true;
    for(int i=head[u];i;i=e[i].next)
    {
        if(!visit[c[e[i].to]]&&!vis[c[t]][c[e[i].to]]&&((e[i].to!=t&&c[e[i].to]!=c[t])||e[i].to==t)&&step+e[i].value+dist[e[i].to]<ans)//最后一个剪枝很重要，如果当前的值加上以后不考虑文化冲突到达终点的最短路比答案大的话就不搜索了 
        pp=true,dfs(e[i].to,step+e[i].value);
    }
    if(!pp)
    visit[c[u]]=false;
    for(int i=1;i<=k;i++)
    if(vis[c[u]][i]) visit[i]=false;
}

int main()
{
    scanf("%d%d%d%d%d",&n,&k,&m,&s,&t);
    for(int i=1;i<=n;i++)
    scanf("%d",&c[i]);
    for(int i=1;i<=k;i++)
    for(int j=1;j<=k;j++)
    scanf("%d",&vis[i][j]);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        add(u,v,w),add(v,u,w);
    }
    spfa();
    dfs(s,0); 
    if(ans==100000000) printf("-1");
    else printf("%d",ans);
}
