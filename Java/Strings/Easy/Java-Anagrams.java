import java.util.Scanner;

public class Solution {

    static boolean isAnagram(String a, String b) {
        int[] freqs = new int[26];
        for (int i = 0; i < a.length(); i++) {
            freqs[Character.toLowerCase(a.charAt(i)) - 'a']++;
        }
        for (int i = 0; i < b.length(); i++) {
            freqs[Character.toLowerCase(b.charAt(i)) - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (freqs[i] != 0)
                return false;
        }
        return true;
    }

    public static void main(String[] args) {
