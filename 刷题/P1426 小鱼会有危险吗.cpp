//Happynewyear 2019/2/7 13:06
#include<bits/stdc++.h>
using namespace std;

int main()
{
    double Happynewyear,Jameswood;
    double CZK,Venus;
    cin>>CZK>>Venus;
    Happynewyear=log(1-0.02*(CZK-Venus)/7)/log(0.98);
    Jameswood=log(1-0.02*(CZK+Venus)/7)/log(0.98);
    if(Jameswood-Happynewyear>=1)
        cout<<'y';
    else
        cout<<'n';
    return 0;
}
