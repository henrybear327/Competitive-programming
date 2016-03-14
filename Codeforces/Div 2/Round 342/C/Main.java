import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt(), k = sc.nextInt();
        k--;
        
        int sum = 0, cnt = 1;
        int[][] ans = new int[n][n];
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < k; j++) {
        		ans[i][j] = cnt++;
        	}
        }
        for(int i = 0; i < n; i++) {
        	for(int j = k; j < n; j++) {
        		ans[i][j] = cnt++;
        	}
        	sum += ans[i][k];
        }
        
        /*
         *  500 250 takes 670 ms
        out.println(sum);
        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		out.printf("%d%c", ans[i][j], j == n - 1 ? '\n' : ' ');

        // Stop writing your solution here.
        out.close();
        */
        
        /*
         * Try StringBuilder, 500 250 is now 140ms!!
         * 
         	StringBuilder sb = new StringBuilder();
            for(int i=0;i<n;i++) sb.append(result[i]).append(' ');
            sb.setCharAt(sb.length()-1, '\n');
            System.out.print(sb);
         * */
        StringBuilder sb = new StringBuilder();
        sb.append(sum).append('\n');
        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++) {
        		sb.append(ans[i][j]);
        		if(j == n - 1)
        			sb.append('\n');
        		else
        			sb.append(' ');
        	}
        
        System.out.print(sb);
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
