
import java.util.Scanner;
import java.lang.*;
import java.util.Arrays;
public class sj {
    public static void main(String[] args){
        Scanner inp=new Scanner(System.in);
        int m,i,j,k=0,n,l,r,ans=0;
        l=inp.nextInt();
        r=inp.nextInt();
        long a[]=new long[1100];
        for(i=0;i<32;i++)
            for(j=0;j<32;j++) {
            a[k]=(long)Math.pow(2,i);
            a[k]*=(long)Math.pow(3,j);
            k++;
        }
        Arrays.sort(a,0,k);
        for(i=0;i<k;i++) if(a[i]>=l&&a[i]<=r) ans++;
        System.out.println(ans);
    }
}
