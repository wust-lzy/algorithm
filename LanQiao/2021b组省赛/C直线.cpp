#include <bits/stdc++.h>
using namespace std;
set<pair<double, double> > ss; //普通的直线
set<double> dx,dy; //两种特殊的直线
struct point
{
    double x, y;
};
void solve(point a,point b)
{
    if(a.x==b.x)    //平行于y轴
        dx.insert(a.x);
    else if(a.y==b.y)    //平行于x轴
        dy.insert(a.y);
    else    //计算表达式y=kx+bb
    {
        double k = (b.y - a.y) / (b.x - a.x);
        // double bb = a.y - k * a.x;   //错误解
        //运用两个点的坐标提升精度
        double bb = (a.y * b.x - a.x * b.y) / (b.x - a.x);
        ss.insert(pair<double, double>(k, bb));
    }
}
int main()
{
    
    vector<point> v;
    for (int i = 0; i <= 19;i++)
    {
        for (int j = 0; j <= 20;j++)
        {
            point temp = {i * 1.0, j * 1.0};//转换为double
            v.push_back(temp);
        }
    }
    int len = v.size();
    for (int i = 0; i < len;i++)    //枚举所有的直线
    {
        for (int j = i + 1; j < len;j++)
        {
            solve(v[i], v[j]);
        }
    }
    cout << dx.size() + dy.size() + ss.size();  //三种直线集合个数求和
    return 0;
}