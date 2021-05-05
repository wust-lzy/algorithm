#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node
{
    int val;
    node *left, *right;
};
vector<int> in, pre, ans;
int n;
node *buildTree(int root, int start, int end)
{
    if (start > end)
        return NULL;
    int i = start;
    while (i < end && in[i] != pre[root])
        i++;
    node *t = new node();
    t->left = buildTree(root + 1, start, i - 1);
    t->right = buildTree(root + 1 + i - start, i + 1, end);
    t->val = pre[root];
    return t;
}
void bfs(node *root)
{
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            node *temp = q.front();
            q.pop();
            if(i==0)
                ans.push_back(temp->val);
            if (temp->left != NULL)
                q.push(temp->left);
            if (temp->right != NULL)
                q.push(temp->right);
        }
    }
}
int main()
{
    cin >> n;
    in.resize(n);
    pre.resize(n);
    for (int i = 0; i < n; i++)
        cin >> in[i];
    for (int i = 0; i < n; i++)
        cin >> pre[i];
    node *root = buildTree(0, 0, n - 1);
    bfs(root);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << " ";
        else
            cout << "\n";
    }
    return 0;
}