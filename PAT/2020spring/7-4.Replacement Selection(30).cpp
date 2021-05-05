#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int val, depth;
    node(int v,int d)
    {
        val = v;
        depth = d;
    }
    friend bool operator <(node a,node b){
        if(a.depth!=b.depth)//depth大的排后面
            return a.depth > b.depth;
        else //depth相同，val大的排后面
            return a.val >= b.val;
    }
};
void func(vector<int> &ans)
{
    for (int i = 0; i < ans.size();i++)
    {
        printf("%d", ans[i]);
        if(i!=ans.size()-1)
            printf(" ");
        else
            printf("\n");
    }
}
vector<int> ans[10001];
int main()
{
    int n, m, t;
    cin >> n >> m;
    priority_queue<node,vector<node> > temp;
    for (int i = 0; i < m;i++)
    {
        scanf("%d", &t);
        temp.push(node(t, 0));
    }
    for (int i = m; i < n;i++)
    {
        scanf("%d", &t);
        node first = temp.top();
        temp.pop();
        ans[first.depth].push_back(first.val);
        int cnt = first.depth;
        if(t<first.val)
            cnt++;
        temp.push(node(t, cnt));
    }
    while(!temp.empty())
    {
        node u = temp.top();
        temp.pop();
        ans[u.depth].push_back(u.val);
    }
    for (int i = 0;;i++)
    {
        if(ans[i].empty())
            break;
        func(ans[i]);
    }
        return 0;
}