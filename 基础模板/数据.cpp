#include <windows.h>
#include <bits/stdc++.h>
using namespace std;
int f,t;
string data_maker,accepted,out,in;
int main(){
    system("ECHO OFF");
    system("mode con cols=30 lines=7");
    system("del /q points");//清空文件夹
    system("mkdir points");//创建文件夹
    system("cls");
    "预调版";
    int point=30;//测试点数 
    data_maker="random.exe";//数据生成 
    accepted="noi.exe";//好的程序 
    in="1.in";//输入数据 
    out="1.out";//标准输出 
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
        string c="copy "+in+" "+"points\\",d="ren points\\"+in+" "+"point"+m+".in";//储存in
        system(c.c_str());
        system(d.c_str());
        c="copy "+out+" "+"points\\",d="ren points\\"+out+" "+"point"+m+".out";//储存out
        system(c.c_str());
        system(d.c_str());
    }
    return 0;
}
