#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    node *left,*right;
};
int v[35];
vector<int>ans;
node *buildTree(int l,int r)
{
    if(l>r)
        return NULL;
    int index,minn=1e9;
    for(int i=l;i<=r;i++)
    {
        if(minn>v[i])
        {
            index=i;
            minn=v[i];
        }
    }
    node *root=new node();
    root->val=minn;
    root->left=buildTree(l,index-1);
    root->right=buildTree(index+1,r);
    return root;
}
void bfs(node *root)
{
    queue<node *>q;
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        ans.push_back(temp->val);
        if(temp->left!=NULL)
            q.push(temp->left);
        if(temp->right!=NULL)
            q.push(temp->right);

    }
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
        cin>>v[i];
    node *root=buildTree(0,n-1);
    bfs(root);
    for(int i=0;i<n;i++)
    {
        printf("%d",ans[i]);
        if(i!=n-1)
            printf(" ");
    }
	return 0;
}
