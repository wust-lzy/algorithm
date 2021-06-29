#include <iostream>
using namespace std;
const int s[7][3] = {   //7个三元组 可以选和不选
    {0,0,1},
    {0,1,0},
    {0,1,1},
    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};
int main()
{
    int t;
    cin >> t;
    while(t--){
        int a, b, c, ans = 0;
        cin >> a >> b >> c;
        for (int i = 0; i < 1 << 7;i++){    //枚举每一种选择的情况
            int sa = 0, sb = 0, sc = 0, cnt = 0;
            for (int j = 0; j < 7;j++){ 
                if(i>>j&1){ //  每个三元组被选择了
                    sa += s[j][0];
                    sb += s[j][1];
                    sc += s[j][2];
                    cnt++;
                }
            }
            if(sa<=a&&sb<=b&&sc<=c)
                ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
    return 0;
}