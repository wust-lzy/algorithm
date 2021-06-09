#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int q[N], hh, tt;//hh队头  tt队尾

int front()
{
    return q[hh];
}

void push(int x){
    q[tt++] = x;
}

void pop(){
    hh++;
}

bool isEmpty(){
    return hh>=tt;
}
int main()
{
    int m;
    cin >> m;
    while(m--){
        string s;
        int x;
        cin >> s;
        if(s=="push"){
            cin >> x;
            push(x);
        }else if(s=="pop"){
            pop();
        }else if(s=="empty"){
            printf("%s\n", isEmpty() ? "YES" : "NO");
        }else if(s=="query"){
            printf("%d\n", front());
        }
    }
    return 0;
}