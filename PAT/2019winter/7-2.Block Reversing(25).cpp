#include<bits/stdc++.h>
using namespace std;
struct node
{
    int ad,data,next;
}v[100010];
void func(vector<node>&ans)
{
    int n=ans.size();
    for(int i=n-1;i>0;i--)
        printf("%05d %d %05d\n",ans[i].ad,ans[i].data,ans[i-1].ad);
    printf("%05d %d -1",ans[0].ad,ans[0].data);
}
int main()
{
    int first,n,k;
    scanf("%d %d %d",&first,&n,&k);
    vector<node>temp;
    int index;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&index);
        scanf("%d %d",&v[index].data,&v[index].next);
        v[index].ad=index;
    }
    //±éÀúÁ´±í
    for(int i=first;i!=-1;i=v[i].next)
        temp.push_back(v[i]);
    n=temp.size();
    for(int i=0;i<n/k;i++)
        reverse(temp.begin()+i*k,temp.begin()+(i+1)*k);
    if(n%k!=0)
        reverse(temp.end()-n%k,temp.end());
    //cout<<endl;
    func(temp);
	return 0;
}

