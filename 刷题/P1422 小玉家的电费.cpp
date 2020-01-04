#include<bits/stdc++.h>
using namespace std;

int a;

int main()
{
    cin>>a;
    if(a<=150)
        cout<<setprecision(1)<<fixed<<a*0.4463<<endl;
    else if(a>150 && a<=400)
        cout<<setprecision(1)<<fixed<<(a-150)*0.4663+66.945<<endl;
    else if(a>400)
        cout<<setprecision(1)<<fixed<<(a-400)*0.5663+66.945+116.575<<endl;
    return 0;
}
