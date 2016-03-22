import java.io.*;
import java.util.*;

public class b
{
	public static double fast_pow(double n, int t) {
		if(t == 0)
			return 1;
		double ans = 1;
		while(t > 0) {
			if((t & 1) == 1)
				ans *= n;
			n *= n;
			t >>= 1;
		}
		
		return ans;
	}
	
	public static double fast_pow1(double x, int t) {
		if(t == 0)
			return 1;
		if((t & 1) == 1)
			return fast_pow1(x * x, t >> 1) * x;
		else
			return fast_pow1(x * x, t >> 1);
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        double n = sc.nextInt();
        int t = sc.nextInt();
        
        //out.println(fast_pow(2, 7));
        out.printf("%.15f\n", n * fast_pow(1.000000011, t));
        //out.printf("%.15f\n", n * fast_pow1(1.000000011, t));

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
