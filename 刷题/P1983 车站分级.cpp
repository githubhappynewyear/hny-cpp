#include <bits/stdc++.h>
using namespace std;

const int N = 1500;
int head[N << 3], top, n, m, tp, stp[N], in[N << 3], arc[N];
bool nd[N << 3];
struct Node
{
    int y, nxt;
    Node() {    }
    Node( int y, int nxt ) : y(y), nxt(nxt) {    }
} e[N * 700];
void Adde( int x, int y )
{
    in[y]++;
    e[++top] = Node(y, head[x]), head[x] = top;
}
#define ls (bt << 1)
#define rs (bt << 1 | 1)
void Build( int bt, int lf, int rg )
{
    tp = max(tp, bt);
    if(lf == rg)
    {
        arc[lf] = bt;
        nd[bt] = 1;
        return;
    }
    int mid=(lf+rg)>>1;
    Adde(ls,bt);
    Build(ls,lf, mid);
    Adde(rs,bt);
    Build(rs,mid+1,rg);
}
void Query(int bt,int lf,int rg,int L,int R,int tmp)
{
    if(L>R) return;
    if(L<=lf && rg<=R)
    {
        Adde(bt, tmp);
        return;
    }
    int mid=(lf+rg)>>1;
    if(L<=mid) Query(ls,lf,mid,L,R,tmp);
    if(R>mid) Query(rs,mid+1,rg,L,R,tmp);
}
int que[N<<5],h,t,dep[N<<3];
void Bfs()
{
    for(int i = 1; i <= tp; ++i)
        if(!in[i]) que[++t] = i, dep[i] = nd[i];
    while(h < t)
    {
        int u = que[++h];
        for(int i = head[u]; i; i=e[i].nxt)
        {
            int v = e[i].y;
            in[v]--;
            dep[v] = max(dep[u]+nd[v],dep[v]);
            if(in[v] == 0) que[++t]=v;
        }
    }
}

int main()
{
    cin>>n>>m;
    Build(1,1,n);
    for(int i=1,cnt;i<=m;++i)
    {
        scanf("%d",&cnt);
        ++tp;
        for(int j=1;j<=cnt;++j)
            scanf("%d",&stp[j]);
        for(int j=1;j<cnt;++j)
        {
            Adde(tp,arc[stp[j]]);
            Query(1,1,n,stp[j]+1,stp[j+1]-1,tp);
        }
        Adde(tp, arc[stp[cnt]]);
    }
    Bfs();
    int ans=0;
    for(int i=1;i<=n;++i)
        ans=max(ans, dep[arc[i]]);
    cout<<ans<<endl;
    return 0;
} 
