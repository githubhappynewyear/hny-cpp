#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
int f,t;
string data_maker,accepted,out,in;
int main(){
    system("ECHO OFF");
    system("mode con cols=30 lines=7");
    system("del /q points");//����ļ���
    system("mkdir points");//�����ļ���
    system("cls");
    "Ԥ����";
    int point=30;//���Ե��� 
    data_maker="random.exe";//�������� 
    accepted="noi.exe";//�õĳ��� 
    in="1.in";//�������� 
    out="1.out";//��׼��� 
    "END";
    for(int i=1;i<=point;i++){
        system(data_maker.c_str());
        f=clock();
        system(accepted.c_str());
        t=clock()-f;
        string m;
        stringstream k;
        k<<i;
        k>>m;
        string c="copy "+in+" "+"points\\",d="ren points\\"+in+" "+"point"+m+".in";//����in
        system(c.c_str());
        system(d.c_str());
        c="copy "+out+" "+"points\\",d="ren points\\"+out+" "+"point"+m+".out";//����out
        system(c.c_str());
        system(d.c_str());
    }
    return 0;
}
