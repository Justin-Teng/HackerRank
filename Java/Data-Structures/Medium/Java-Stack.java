import java.util.*;
class Solution{
	
	public static void main(String []argh)
	{
		Scanner sc = new Scanner(System.in);
		
		while (sc.hasNext()) {
			String input=sc.next();
            Stack s = new Stack();
            boolean flag = false;
            
            for (int i = 0; i < input.length(); i++) {
                char c = input.charAt(i);
                if (c == '(' || c == '{' || c == '[')
                    s.push(c);
                else if (c == ')') {
                    if (s.isEmpty() || s.peek() != '(') {
                        flag = true;
                        break;
                    } else
                        s.pop();
                } else if (c == '}') {
                    if (s.isEmpty() || s.peek() != '{') {
                        flag = true;
                        break;
                    } else
                        s.pop();
                } else {
                    if (s.isEmpty() || s.peek() != '[') {
                        flag = true;
                        break;
                    } else
                        s.pop();
                }
            }
            if (flag || !s.isEmpty())
                System.out.println("false");
            else
                System.out.println("true");
		}
		
	}
}



