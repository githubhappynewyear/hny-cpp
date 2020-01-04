//Happynewyear 2019/2/6 10:50 
#include<bits/stdc++.h>
using namespace std;

int gw;
int d[9];
int cf(int x){ 
    while(x!=0){        
        gw=x%10;
        x=(x-gw)/10;
        d[gw]++;
    }
}

int main()
{
    int a,b,c;
    for (int i=1;i<=9;i++)
        for (int j=1;j<=9;j++)
            for (int k=1;k<=9;k++)
            {
                a=i*100+j*10+k;
                b=a*2;
                c=a*3;
                cf(a);
                cf(b);
                cf(c);
                if(d[1]==1&&d[2]==1&&d[3]==1&&d[4]==1&&d[5]==1&&d[6]==1&&d[7]==1&&d[8]==1&&d[9]==1){
                    cout<<a<<" "<<b<<" "<<c<<endl;
                }
                for (int e=1;e<=9;e++){
                    d[e]=0;
                }
            }
            return 0;
}
