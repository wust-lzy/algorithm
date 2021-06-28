
import java.util.Scanner;

/**
 * @author Zzy
 * @version 1.0
 * @date 2021/5/21 14:47
 */
public class Main {
    static String dfs(int n){
        String res="";//字符串递归处理
        for(int i=14;i>=0;i--){
            if((n>>i & 1)==1){//二进制对应位为1 分情况讨论 先列举出口
                if(res.length()>0)
                    res+='+';
                if(i==0)
                    res+="2(0)";
                else if(i==1)
                    res+="2";
                else
                    res+="2("+dfs(i)+")";
            }
        }
        return res;
    }
    public static void main(String[] args) {
        int n;
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            n=sc.nextInt();
            System.out.println(dfs(n));
        }
    }
}
