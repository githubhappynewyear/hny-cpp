#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n=0;
	char c;
	scanf("%d",&n);
	if(n%123>=97)
		c=n%123;
	else if(n%91>=65)
		c=n%91;
	else
		c='*';
	printf("%c",c);
	return 0;
}
