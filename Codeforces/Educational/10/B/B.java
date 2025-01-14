import java.io.*;
import java.util.*;

public class B
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt();
        int[] inp = new int[n];
        for(int i = 0; i < n; i++) {
        	inp[i] = sc.nextInt();
        }
        
        Arrays.sort(inp);
        
        int[] ans = new int[n];
        int idx = 1;
        for(int i = n / 2 + (n % 2 == 0 ? 0 : 1); i < n; i++) {
        	ans[idx] = inp[i];
        	idx += 2;
        }
        
        idx = 0;
        for(int i = 0; i < n / 2 + (n % 2 == 0 ? 0 : 1); i++) {
        	ans[idx] = inp[i];
        	idx += 2;
        }
        
        for(int i = 0; i < n; i++)
        	out.printf("%d ", ans[i]);

        

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
