import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt();
        
        int[] ans = new int[2 * n];
        
        int base = 0;
        for(int i = 1; i < n; i += 2) {
        	ans[base] = i;
        	ans[base + n - i] = i;
        	base++;
        }
        
        base = n;
        for(int i = 2; i < n; i += 2) {
        	ans[base] = i;
        	ans[base + n - i] = i;
        	base++;
        }
        
        for(int i = 0; i < 2 * n; i++)
        	if(ans[i] == 0)
        		ans[i] = n;
        
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 2 * n; i++) {
        	sb.append(ans[i]);
        	
        	if(i == 2 * n - 1)
        		sb.append('\n');
        	else
        		sb.append(' ');
        }
        
        out.println(sb);
        

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
