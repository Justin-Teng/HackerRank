import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the minimumNumber function below.
    static int minimumNumber(int n, String password) {
        String numbers = "0123456789";
        String lower_case = "abcdefghijklmnopqrstuvwxyz";
        String upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String special_characters = "!@#$%^&*()-+";

        boolean num = false;
        boolean lower = false;
        boolean upper = false;
        boolean special = false;

        for (int i = 0; i < numbers.length(); i++) {
            if (password.indexOf(numbers.charAt(i)) != -1) {
                num = true;
                break;
            }
        }

        for (int i = 0; i < lower_case.length(); i++) {
            if (password.indexOf(lower_case.charAt(i)) != -1) {
                lower = true;
                break;
            }
        }

        for (int i = 0; i < upper_case.length(); i++) {
            if (password.indexOf(upper_case.charAt(i)) != -1) {
                upper = true;
                break;
            }
        }

        for (int i = 0; i < special_characters.length(); i++) {
            if (password.indexOf(special_characters.charAt(i)) != -1) {
                special = true;
                break;
            }
        }

        int result = 0;
        if (!num)
            result++;
        if (!lower)
            result++;
        if (!upper)
            result++;
        if (!special)
            result++;
        result = Math.max(result, 6 - password.length());

        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int n = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        String password = scanner.nextLine();

        int answer = minimumNumber(n, password);

        bufferedWriter.write(String.valueOf(answer));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}
