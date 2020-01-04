//https://www.luogu.com.cn/problem/T34871 
/*
题目描述
老师在开学第一天就把所有作业都布置了，每个作业如果在规定的时间内交上来的话才有学分。每个作业的截止日期和学分可能是不同的。例如如果一个作业学分为10，要求在6天内交，那么要想拿到这10学分，就必须在第6天结束前交。

每个作业的完成时间都是只有一天。例如，假设有7次作业的学分和完成时间如下：

作业号 1 2 3 4 5 6 7

期 限 1 1 3 3 2 2 6

学 分 6 7 2 1 4 5 1

最多可以获得15学分，其中一个完成作业的次序为2，6，3，1，7，5，4，注意可能还有其他方法。

你的任务就是找到一个完成作业的顺序获得最大学分。

输入格式
第一行一个整数N，表示作业的数量；

接下来N行，每行包括两个整数，第一个整数表示作业的完成期限，第二个数表示该作业的学分。

输出格式
输出一个整数表示可以获得的最大学分。保证答案不超过longint范围。

输入输出样例
输入 #1复制
7
1 6
1 7
3 2
3 1
2 4
2 5
6 1
输出 #1复制
15
说明/提示
【数据范围】

对于部分数据，N<=1000；

对于部分数据，N<=10000；

对于部分数据，N<=100000；

对于部分数据，作业的完成期限小于100；

对于部分数据，作业的完成期限小于1000；

对于所有数据，N<=1000000，作业的完成期限均小于700000。
*/
#include<bits/stdc++.h>
using namespace std;
#define Maxm 700005
#define Maxn 1000005

bool bj[Maxm];
int pre[Maxm];

struct node
{
	int date;
	int value;
}t[Maxn];

bool cmp(const node &a,const node &b)
{
	return a.value>b.value;
}

int find(int x)
{
	if(!bj[x])
		return x;
	pre[x]=find(pre[x]);
	return pre[x]; 
}

int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&t[i].date,&t[i].value);
	}
	for(int i=1;i<=Maxm;i++)
	{
		pre[i]=i-1;
	}
	
	sort(t+1,t+n+1,cmp);
	
	for(int i=1;i<=n;i++)
	{
		int tmp=find(t[i].date);
		if(tmp)
		{
			bj[tmp]=true;
			ans+=t[i].value;
			if(t[i].date!=tmp)
			pre[t[i].date]=pre[tmp];
		}
	}
	printf("%d\n",ans);
	return 0;
}
