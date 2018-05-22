import java.io.*;
import java.util.*;

public class C
{
	public static long gcd(long a, long b)
	{
		return a == 0 ? b : gcd(b % a, a);
	}
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        long n = sc.nextLong(), a = sc.nextLong(), b = sc.nextLong(), 
        		p = sc.nextLong(), q = sc.nextLong();

        long lcm = a % gcd(a, b) == 0 ? a / gcd(a, b) * b : b / gcd(a, b) * a;
        long common = n / lcm;
        
        long cnta = n / a - common;
        long cntb = n / b - common;
        
        //out.printf("%d %d %d\n", cnta, cntb, common);
        
        long ans = cnta * p + cntb * q + common * Math.max(p, q);
        out.println(ans);
        
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
