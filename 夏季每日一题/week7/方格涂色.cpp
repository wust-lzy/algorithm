#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        bool flag = false;
        int n, u, r, d, l;
        cin >> n >> u >> r >> d >> l;
        for (int i = 0; i < 16;i++){    //  枚举四个顶点是否填色
            int a[4] = {0};
            for (int j = 0; j < 4;j++)  //二进制枚举
                if(i>>j&1)
                    a[j] = 1;   
            if(u>=a[0]+a[1]&&u<=n-2+a[0]+a[1] && 
               r>=a[1]+a[2]&&r<=n-2+a[1]+a[2] && 
               d>=a[2]+a[3]&&d<=n-2+a[2]+a[3] && 
               l>=a[3]+a[0]&&l<=n-2+a[3]+a[0]
            )
            {
                flag = true;
                break;
            }
        }
        printf("%s\n",flag?"YES":"NO");
    }
    return 0;
}