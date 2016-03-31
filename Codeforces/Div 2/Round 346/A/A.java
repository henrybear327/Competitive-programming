import java.io.*;
import java.util.*;

public class A
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt();
        
        // int ans = (a - 1 + (b % n) + (b < 0 ? n : 0)) % n + 1; // Wrong! (b < 0 ? n : 0) may not overcome the negative effect!
        int ans = (((a - 1 + b) % n) + n) % n + 1; // +n here can overcome negative effect because %n guarantees the number range -n+1 ~ 0
        // int ans = (a - 1 + b + (b < 0 ? n : 0)) % n + 1; //3 1 -4
        
        out.println(ans);
        
        /*
        b = b % n;
		int ans = ( a + b ) % n;
		if(ans <= 0)
			ans = n + ans;
        out.println(ans);
        */

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
