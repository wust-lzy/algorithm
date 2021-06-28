import java.util.*;
/**
 * @author Zzy
 * @version 1.0
 * @date 2021/5/25 19:06
 */
public class Main {
    public int minMoves2(int[] nums) {
        int sum=0;
        Arrays.sort(nums);
        for (int num : nums) {
            sum+=Math.abs(nums[nums.length/2]-num);
        }
        return sum;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t>0){
            t--;
            int n=sc.nextInt(),m=sc.nextInt();
            int a[][]=new int[n][m];
            int vis[][]=new int[n][m];
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    a[i][j]=sc.nextInt();
                }
            }
            long sum=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(vis[i][j]==0){
                        vis[i][j]=1;
                        List<Integer>l=new ArrayList<>();
                        int x2=i,y2=m-j-1;
                        int x3=n-i-1,y3=j;
                        int x4=n-i-1,y4=m-j-1;
                        l.add(a[i][j]);
                        if(vis[x2][y2]==0){
                            vis[x2][y2]=1;
                            l.add(a[x2][y2]);
                        }
                        if(vis[x3][y3]==0){
                            vis[x3][y3]=1;
                            l.add(a[x3][y3]);
                        }
                        if(vis[x4][y4]==0){
                            vis[x4][y4]=1;
                            l.add(a[x4][y4]);
                        }
                        Collections.sort(l);
                        int mid=l.get(l.size()/2);
                        for (Integer integer : l) {
                            sum+=Math.abs(mid-integer);
                        }
                    }
                }
            }
            System.out.println(sum);
        }
    }
}
