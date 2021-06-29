#include <iostream>
#include<cstring>
using namespace std;

const int N = 105;
int a[N];

int mex(){
    for (int i = 0; i < 105;i++){
        if(a[i]==0)
            return i;
        else
            a[i]--;
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        memset(a, 0, sizeof a);
        while(n--){
            int x;
            cin >> x;
            a[x]++;
        }
        cout << mex() + mex() << endl;
    }
    return 0;
}