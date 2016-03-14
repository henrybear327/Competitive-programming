import java.io.*;
import java.util.*;

public class Main
{
	public static long ext_gcd(long a, long b, long[] x, long[] y) {
		if(a == 0) {
			x[0] = 0;
			y[0] = 1;
			return b;
		}
		
		long[] x1 = new long[1];
		long[] y1 = new long[1];
		
		long gcd = ext_gcd(b % a, a, x1, y1);
		x[0] = y1[0] - b / a * x1[0];
		y[0] = x1[0];
		
		return gcd;
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        while(sc.hasNext() == true) {
        	long a = sc.nextLong(), b = sc.nextLong();
            
            long[] x = new long[1];
    		long[] y = new long[1];
            
    		if(a == b)
    			out.println("0 1 " + a);
    		else {
    			long gcd = ext_gcd(a, b, x, y);
    			out.println(x[0] + " " + y[0] + " " + gcd);
    		}
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
