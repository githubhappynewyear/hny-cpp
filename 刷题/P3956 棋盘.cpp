#include<bits/stdc++.h>
using namespace std;

int i,m,n,j,k,q,p,w;
int a[1100][1100];
int f[4]={0,0,1,-1},ff[4]={1,-1,0,0};
int minn=0x7fffffff;
int d[1100][1100];
bool bl[1100][1100];

void search(int x,int y,int c,int color)
{
    if((x==n)&&(y==n))
    {
        minn=min(c,minn);
        return;
    }

    for(int i=0;i<4;i++)
    {
        int p=x+f[i],q=y+ff[i];
        if((p<=n)&&(p>0)&&(q<=n)&&(q>0))
        if(bl[p][q])
        if(a[x][y]||a[p][q])
        {
            if(a[p][q]==0)
            {
                if(c+2<d[p][q])
                { 
                    bl[p][q]=0;
                    d[p][q]=c+2,search(p,q,c+2,color);
                    bl[p][q]=1;
                } 
            }
            else
            {
                if((color==a[p][q])&&(c<d[p][q]))
                { 
                    bl[p][q]=0;
                    d[p][q]=c,search(p,q,c,color);
                    bl[p][q]=1;
                } 
                else if((c+1<minn)&&(c+1<d[p][q]))
                { 
                    bl[p][q]=0; 
                    d[p][q]=c+1,search(p,q,c+1,a[p][q]);
                    bl[p][q]=1;
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++) d[i][j]=0x7fffffff,a[i][j]=0,bl[i][j]=1;

    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&q,&p,&w);
        a[q][p]=w+1;
    }

    bl[1][1]=0;

    search(1,1,0,a[1][1]);

    if(minn==0x7fffffff) printf("-1");
    else printf("%d",minn);

    return 0;
}
