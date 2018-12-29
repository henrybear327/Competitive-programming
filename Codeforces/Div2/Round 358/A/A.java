import java.io.*;
import java.util.*;

public class A
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt(), m = sc.nextInt();
        
        int[] cnt1 = new int[5];
        int[] cnt2 = new int[5];
        
        int n1 = n / 5, n2 = n % 5;
        int m1 = m / 5, m2 = m % 5;
        
        for(int i = 0; i < 5; i++) {
        	if(i == 0)
        		cnt1[i] = n1;
        	else
        		cnt1[i] = n1 + (i <= n2 ? 1 : 0);
        }
        
        for(int i = 0; i < 5; i++) {
        	if(i == 0)
        		cnt2[i] = m1;
        	else
        		cnt2[i] = m1 + (i <= m2 ? 1 : 0);
        }
        
        long ans = (long)cnt1[0] * cnt2[0];
        for(int i = 1; i < 5; i++)
        	ans += (long)cnt1[i] * cnt2[5 - i];
        
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
