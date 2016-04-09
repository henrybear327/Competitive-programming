import java.io.*;
import java.util.*;

public class B
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt(), m = sc.nextInt();
        	
        int cnt = 0, b = 1, bb = 2 * n + 1;
        for(int i = 0; i < n && cnt < m; i++) {
        	for(int j = 0; j < 4 && cnt < m; j++) {
        		if(j == 0 && bb <= m)
        			out.printf("%d ", bb);
        		else if(j == 1 && b <= m)
        			out.printf("%d ", b);
        		else if(j == 2 && bb + 1 <= m)
        			out.printf("%d ", bb + 1);
        		else if(j == 3 && b + 1 <= m)
        			out.printf("%d ", b + 1);
        	}
        	bb += 2;
        	b += 2;
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
