#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int stk[N], tt;

//插入
void push(int x)
{
    stk[++tt] = x;
}

//弹出
void pop()
{
    tt--;
}

//判断是否为空
bool isEmpty()
{
    return tt == 0;
}
//栈顶元素
int top()
{
    return stk[tt];
}
int main()
{
    int m;
    cin >> m;
    while(m--){
        string s;
        cin >> s;
        int x;
        if(s=="push"){
            cin >> x;
            push(x);
        }else if(s=="pop"){
            pop();
        }else if(s=="empty"){
            printf("%s\n", isEmpty() ? "YES" : "NO");
        }else if(s=="query")
            printf("%d\n", top());
    }
    return 0;
}