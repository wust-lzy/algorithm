#include<iostream>

using namespace std;
const int N = 1e6 + 10;
//head表示头结点 e[i]表示value   ne[i]表示next指针
//idx存储当前用到的点
int head, e[N], ne[N], idx;
//初始化
void init()
{
    head = -1;
    idx = 0;
}

//将x插入头结点
void add_to_head(int x)
{
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}
//在k结点后插入一个x
void ins(int k,int x)
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx++;
}

//将下标是k后面的点删掉
void remove(int k)
{
    ne[k] = ne[ne[k]];
}
int main()
{
    init();
    int m;
    cin >> m;
    while(m--){
        int k, x;
        char c;
        cin >> c;
        if(c=='H'){
            cin >> x;
            add_to_head(x);
        }
        else if(c=='D')
        {
            cin >> k;
            if(!k)
                head = ne[head];
            remove(k-1);
        }else{
            cin >> k >> x;
            ins(k-1, x);
        }
    }
    for (int i = head; i != -1;i=ne[i])
        cout << e[i] << " ";
    return 0;
}