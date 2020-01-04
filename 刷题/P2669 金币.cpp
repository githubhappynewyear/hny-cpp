#include<bits/stdc++.h>
using namespace std;

int main()
{
    int K,N,coin=0;
    scanf("%d",&K);
    for(N=1;K-N>=0;K-=N++)
        coin+=N*N;
    printf("%d\n",coin+K*N);
    return 0;
}
