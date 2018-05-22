import java.io.*;
import java.util.*;

public class B
{
	public static boolean isLeap(int year)
	{
		return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int y = sc.nextInt();
        
        long sum = 0;
        for(int i = 1;; i++) {
        	if(isLeap(y + i) == true)
        		sum += 366;
        	else
        		sum += 365;
        	
        	if(sum % 7 == 0 && isLeap(y + i) == isLeap(y)) {
        		out.println(y + i);
        		break;
        	}
        }
        
        out.close();
    }

    // PrintWriter for faster output
    public static PrintWriter out;

    // MyScanner class for faster input
    public static class MyScanner
    {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        boolean hasNext()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (Exception e) {
                    return false;
                }
            }
            return true;
        }

        String next()
        {
            if (hasNext())
                return st.nextToken();
            return null;
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
