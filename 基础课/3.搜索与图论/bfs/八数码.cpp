#include <iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<unordered_map>
using namespace std;
string s;
const int go[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int bfs()
{
    string ans = "12345678x";
    queue<string> q;
    unordered_map<string, int> dis;
    q.push(s);
    while(!q.empty())
    {
        string t = q.front();
        q.pop();
        if(t==ans)
            return dis[t];
        int distance = dis[t];
        int k = t.find('x');
        int x = k / 3, y = k % 3;//第几行几列
        for (int i = 0; i < 4;i++)
        {
            int dx = x + go[i][0];
            int dy = y + go[i][1];
            if(dx>=0&&dx<3&&dy>=0&&dy<3)
            {
                swap(t[dx * 3 + dy], t[k]);
                if(!dis.count(t))   //  没有出现
                {
                    dis[t] = distance + 1;
                    q.push(t);
                }
                swap(t[dx * 3 + dy], t[k]); //回溯
            }
        }
    }
    return -1;
}
int main()
{
    char ch[2];
    for (int i = 0; i < 9; i++)
    {
        cin >> ch;
        s += ch[0];
    }
    cout << bfs();
    return 0;
}