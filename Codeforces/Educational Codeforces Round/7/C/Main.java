import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt(), k = sc.nextInt();
        
        int[] inp = new int[n + 2];
        for(int i = 1; i <= n; i++)
        	inp[i] = sc.nextInt();
       
        int[] next = new int[n + 2];
        Arrays.fill(next, 0);
        
        next[n] = n + 100;
        for(int i = n; i >= 1; i--)
        	if(inp[i] != inp[i - 1])
        		next[i - 1] = i;
        	else
        		next[i - 1] = next[i];
       
        for(int i = 0; i < k; i++) {
        	int l = sc.nextInt(), r = sc.nextInt(), x = sc.nextInt();
        	
        	if(inp[l] != x)
        		out.println(l);
        	else if(next[l] <= r)
        		out.println(next[l]);
        	else
        		out.println("-1");
        }

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
