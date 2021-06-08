#include<iostream>
using namespace std;

const int N = 1e6 + 10;
int l[N], r[N], e[N], idx;

void init()
{
    //0表示左端点，1表示右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}
//L x，表示在链表的最左端插入数 x。
void insl(int x)
{
    l[idx] = 0;//新节点->pre=head
    r[idx] = r[0];//新节点->next=head->next
    r[0] = idx;//head->next=新节点
    l[r[idx]] = idx;//新节点->next->pre=新节点
    e[idx++] = x;  //add x
}

//R x，表示在链表的最右端插入数 x。
void insr(int x)
{
    r[idx] = 1; //新节点->next=tail
    l[idx] = l[1]; //新节点->pre=tail->pre
    r[l[idx]] = idx;//新节点->pre->next=新节点
    l[1] = idx;//tail->pre=新节点
    e[idx++] = x;  
}
//IR k x，表示在第 k 个插入的数右侧插入一个数。
void inskr(int k,int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}
//IL k x，表示在第 k 个插入的数左侧插入一个数。
void inskl(int k,int x)
{
    e[idx] = x;
    l[idx] = l[k];
    r[idx] = k;
    r[l[idx]] = idx;
    l[k] = idx;
    idx++;
}
//D k，表示将第 k 个插入的数删除。
void remove(int k)
{
    r[l[k]] = r[k];//k->pre->next=k->next
    l[r[k]] = l[k];//k->next->pre=k->pre
}

int main()
{
    init();
    int m;
    cin >> m;
    while(m--)
    {
        string c;
        int k, x;
        cin >> c;
        if(c=="R"){
            cin >> x;
            insr(x);
        }else if(c=="L"){
            cin >> x;
            insl(x);
        }else if(c=="D"){
            cin >> k;
            remove(k + 1);//初始化两个节点，第k个数的下标为k+2-1
        }else if(c=="IL"){
            cin >> k >> x;
            inskl(k + 1, x);
        }else if(c=="IR"){
            cin >> k >> x;
            inskr(k + 1, x);
        }
    }
    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";
        return 0;
}