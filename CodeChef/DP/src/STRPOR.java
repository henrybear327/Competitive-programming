import java.io.*;
import java.util.*;

public class STRPOR
{
	public static long M = (long)1e9 + 7;
	
	public static long modInv(long a)
	{
		// fast exp a^(M - 2)
		long exp = M - 2;
		long res = 1, base = a;
		while(exp > 0) {
			if((exp & 1) == 1) {
				res = res * base % M;
			}
			base = base * base % M;
			exp >>= 1;
		}
		
		return res;
	}
	
	public static long next(long num, long numerator, long denominator)
	{
		num = num * numerator % M;
		//out.println("modInv = " + modInv(denominator));
		num = num * modInv(denominator) % M;
		
		return num;
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int T = sc.nextInt();
        while(T-- > 0) {
        	int n = sc.nextInt(), x = sc.nextInt();
        	long m = sc.nextLong();
        	
        	long[] inp = new long[n];
        	for(int i = 0; i < n; i++)
        		inp[i] = sc.nextLong() % M;
        	
        	long mul = 1, ans = 0;
        	long numerator = m, denominator = 1;
        	for(int i = x - 1; i >= 0; i--) {
        		numerator %= M;
        		denominator %= M;
        		
        		ans = (ans + inp[i] * mul % M) % M;
        		mul = next(mul, numerator++, denominator++);
        		// out.println(ans + " " + mul);
        	}
        	
        	//out.println("ans = " + ans);
        	out.println(ans);
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
