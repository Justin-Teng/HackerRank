import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int n = in.nextInt();
        ArrayList<Integer> a = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            a.add(in.nextInt());
        }
        in.nextLine();

        int q = in.nextInt();
        for (int i = 0; i < q; i++) {
            String command = in.next();
            in.nextLine();
            if (command.equals("Insert")) {
                int x = in.nextInt();
                int y = in.nextInt();
                a.add(x, y);
            } else {
                int x = in.nextInt();
                a.remove(x);
            }
        }

        for (int i = 0; i < a.size(); i++) {
            System.out.print(a.get(i));
            if (i != a.size()-1)
                System.out.print(' ');
        }
    }
}

