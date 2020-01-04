//Happynewyear 2019/2/7 12:49
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char Happynewyear[100]; 
    int n,j; 
    scanf("%d%s",&n,Happynewyear); 
    for(j=0;Happynewyear[j]!='\0';j++)
        putchar((Happynewyear[j]-'a'+n)%26+'a');
    return 0;
}
