#include<bits/stdc++.h>
using namespace std;

const int kkk=1000050;

int n,k,x,u,v,val;
int first[kkk];
struct node{int u,v,val,next;}side[2*kkk];

int cnt=0;
void addedge(int u,int v,int val)
{
    side[++cnt].u=u;
    side[cnt].v=v;
    side[cnt].val=val;
    side[cnt].next=first[u];
    first[u]=cnt;
}

bool visit[kkk];
int head=0,tail=0;
int p[kkk],dis[kkk];
int s1,t1,s[kkk],t[kkk];
void spfa()
{
    memset(visit,0,sizeof(visit));
    memset(dis,127,sizeof(dis));

    for(int i=1;i<=s1;i++)
    {
        dis[s[i]]=0;
        p[++tail]=s[i];
        visit[s[i]]=true;
    }

    while(head<tail)
    {
        head++;
        visit[p[head]]=false;
        for(int i=first[p[head]];i;i=side[i].next)
        {
            u=side[i].u;
            v=side[i].v;
            if(dis[v]>dis[u]+side[i].val)
            {
                dis[v]=dis[u]+side[i].val;
                if(!visit[v])
                {
                    tail++;
                    p[tail]=v;
                    visit[v]=true;
                }
            }
        }
    }
}

int main()
{
    cin>>n>>k>>x;
    for(int i=1;i<=k;i++)
    {
        cin>>u>>v>>val;
        addedge(u,v,val);
        addedge(v,u,val);
    }
    s1=1; s[1]=x;
    t1=1; t[1]=n;

    spfa();
    for(int i=1;i<=t1;i++)  cout<<dis[t[t1]]<<endl;
    return 0;
}
