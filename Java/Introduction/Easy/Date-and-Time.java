import java.util.*;

public class Solution {
    public static String getDay(String day, String month, String year) {
        Calendar c = Calendar.getInstance();
        c.set(Integer.parseInt(year), Integer.parseInt(month)-1, Integer.parseInt(day));
        
        int dayNum = c.get(Calendar.DAY_OF_WEEK);
        switch (dayNum) {
            case 1: return "SUNDAY";
            case 2: return "MONDAY";
            case 3: return "TUESDAY";
            case 4: return "WEDNESDAY";
            case 5: return "THURSDAY";
            case 6: return "FRIDAY";
            case 7: return "SATURDAY";
        }
        return "ERROR";
    }
