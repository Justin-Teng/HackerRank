import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        String[] tokens = s.split("[ !,?\\._'@]");
        
        int count = 0;
        for (String token : tokens)
            if (token.length() > 0)
                count++;
        
        System.out.println(count);
        
        for (String token : tokens)
            if (token.length() > 0)
                System.out.println(token);
        
        scan.close();
    }
}

