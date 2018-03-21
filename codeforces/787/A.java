import java.util.Scanner;
import java.util.Arrays;

public class sj {
    public static void main(String[] args) {
        int i,j,k,n,m,a,b,c,d;
        boolean vis[]=new boolean[1000100];
        Scanner sc=new Scanner(System.in);
        b=sc.nextInt();
        a=sc.nextInt();
        d=sc.nextInt();
        c=sc.nextInt();
        for(i=a;i<1000000;i+=b) vis[i]=true;
        for(i=c;i<1000000;i+=d) 
            if(vis[i]==true){
                System.out.println(i);
                return;
           }
        System.out.println("-1");
        return;
    }
}
