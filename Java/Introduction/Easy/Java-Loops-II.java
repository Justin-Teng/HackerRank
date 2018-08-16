import java.util.*;
import java.io.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int factor = 2;
            int s_n = a+b;
            for (int j = 0; j < n; j++) {
                System.out.printf("%d ", s_n);
                s_n += factor*b;
                factor *= 2;
            }
            System.out.printf("%n");
        }
        in.close();
    }
}
