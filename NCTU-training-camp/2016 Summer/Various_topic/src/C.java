import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C
{
	public static int gcd(int a, int b)
	{
		return a == 0 ? b : gcd(b % a, a);
	}
	
    public static void main(String[] args)
    {
    	MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        // case 2 4 6
        int n;
        n = sc.nextInt();
        
        int d = sc.nextInt(), mx = d;
        for(int i = 0; i < n - 1; i++) {
        	int cur = sc.nextInt();
        	mx = Math.max(mx, cur);
        	d = gcd(d, cur);
        }
       
        int cnt = mx / d;
        cnt -= n;
        
        if(cnt % 2 == 0)
        	out.println("Bob");
        else
        	out.println("Alice");
        
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
