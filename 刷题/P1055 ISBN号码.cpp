//Happynewyear 2019/2/6 13:39 
#include<bits/stdc++.h>
using namespace std;

char a[14],b[14],t1,t2;
int t22=0;

int main()
{
    scanf("%c-%c%c%c-%c%c%c%c%c-%c",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9],&t1);
    for(int i=1;i<=9;++i)
        t22+=(a[i]-'0')*i;
    t2=t22%11+'0';
    if(t2=='0'+10)t2='X';
    if(t1==t2)
    {
        cout<<"Right";
        return 0;
    }
    cout<<a[1]<<'-'<<a[2]<<a[3]<<a[4]<<'-'<<a[5]<<a[6]<<a[7]<<a[8]<<a[9]<<'-'<<t2;//±©Á¦µØÊä³ö
    return 0;
}
