import java.io.*;
import java.util.*;

public class A
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int h1 = sc.nextInt(), h2 = sc.nextInt();
        int a = sc.nextInt(), b = sc.nextInt();
        
        if((h1 + a * 8) < h2 && (b >= a)) {
        	out.println("-1");
        } else {
        	if(h1 + a * 8 >= h2) {
        		out.println(0);
        	} else {
	        	if(a == b) {
	        		out.println(0);
	        	} else {
	        		int x = h2 - (h1 + 8 * a);
		        	int y = 12 * (a - b);
		        	if(x % y == 0)
		        		out.println(x / y);
		        	else
		        		out.println(x / y + 1);
	        	}
        	}
        	
        	/*
        	while(h1 < h2) {
        		if(day == 0) {
        			h1 += a * 8;
        		} else {
        			h1 += a * 12;
        		}
        		if(h1 >= h2)
        			break;
        		day++;
        		h1 -= 12 * b;
        	}
        	out.println(day);
        	*/
        }

        // Start writing your solution here.

        /*
        int n      = sc.nextInt();        // read input as integer
        long k     = sc.nextLong();       // read input as long
        double d   = sc.nextDouble();     // read input as double
        String str = sc.next();           // read input as String
        String s   = sc.nextLine();       // read whole line as String

    	while(sc.hasNext()) {
    		...
    	}

        int result = 3*n;
        out.println(result);                    // print via PrintWriter
        */
        	
        // Stop writing your solution here.
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
