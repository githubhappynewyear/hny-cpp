//Happynewyear 2019/2/8 12:29
#include<bits/stdc++.h>
using namespace std;

int f[5];

int main()
{
    for(int i=1;i<=4;i++)
        scanf("%d",&f[i]);
        sort(f+1,f+5);
        if(f[1]+f[2]>f[3]||f[2]+f[3]>f[4])
            cout<<"TRIANGLE"<<endl;
        else
            if(f[1]+f[2]==f[3]||f[2]+f[3]==f[4])
                cout<<"SEGMENT"<<endl;
            else
                cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
