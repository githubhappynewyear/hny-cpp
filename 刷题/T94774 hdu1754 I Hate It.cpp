#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define N 200001
using namespace std;

int num[N];
struct Tree
{
    int l;    //左端点 
    int r;    //右端点 
    int Max;  //总数 
}tree[N*4];   //总线段长度为N，若开数组，一般开到N的4倍 

void build(int root,int l,int r)  //建立线段树：root为根节点，它的区间为[l,r] 
{
    tree[root].l=l;
    tree[root].r=r;
    if(tree[root].l==tree[root].r)  //当左右端点相等时就是叶子节点 
    {
  	    tree[root].Max=num[l];      //赋初值 
	    return;                     //递归出口 
    }
    int mid=(l+r)/2;
    build(root<<1,l,mid);           //root<<1 相当于root*2 ，即它的左孩子 
    build(root<<1|1,mid+1,r);       //root<<1|1 相当于root*2+1 ，即它的右孩子 
    tree[root].Max=max(tree[root<<1].Max,tree[root<<1|1].Max);  //父亲的Max=max(左孩子的Max,右孩子的Max)
}

void update(int root,int pos,int val)  //更新：root是根节点，pos和val表示将在pos点的值更新为val 
{
    if(tree[root].l==tree[root].r)     //如果是叶子节点，即是pos对应的位置 
    {
  	    tree[root].Max=val;            //更新操作 
	    return;                        //递归出口 
    }
    int mid=(tree[root].l+tree[root].r)/2;
    if(pos<=mid)                              //如果pos点是root对应的左孩子 
        update(root<<1,pos,val);              //在左孩子里面找 
    else
        update(root<<1|1,pos,val);            //在右孩子里面找
    tree[root].Max=max(tree[root<<1].Max,tree[root<<1|1].Max);  //父亲的Max=max(左孩子的Max,右孩子的Max)
}
	
int query(int root,int L,int R)              //查询：root为根节点，[L,R]表示要查询的区间 
{
    if(L<=tree[root].l && R>=tree[root].r)   //如果要查询的区间[L,R]包含root节点表示的区间 
	    return tree[root].Max;               //直接返回root节点的Max值 
    int mid=(tree[root].l+tree[root].r)/2;   
	int ret1=0,ret2=0;
    if(L<=mid) ret1=query(root<<1,L,R);     //查询root节点的左孩子 
    if(R>mid)  ret2=query(root<<1|1,L,R);   //查询root节点的右孩子               
    return max(ret1,ret2);                  //返回左、右子树中较大值 
}	

int main()
{
    //freopen("hdu1754.in","r",stdin);
    //freopen("hdu1754.out","w",stdout);	
    
    int n,m,a,b;
    char str[2];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
		for(int i=1;i<=n;i++) 
           scanf("%d",&num[i]);    //在学生i的成绩 
        build(1,1,n);              //从根节点1开始构建线段树，区间[1,n] 
        while(m--)
        {
        	scanf("%s%d%d",str,&a,&b);
        	if(str[0]=='Q')
        	{
        	    if(a>b) swap(a,b);             //查询区间[a,b] 
        	    printf("%d\n",query(1,a,b));   //输出查询结果 
			}
			else  update(1,a,b);               //更新a点的值为b
        }
    }     
	return 0;
}
