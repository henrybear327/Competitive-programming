import java.io.*;
import java.util.*;

public class D
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt();
        int ans = 0;
        
        int[] x = new int[n + 2];
        int[] y = new int[n + 2];
        for(int i = 0; i < n + 1; i++) {
        	x[i] = sc.nextInt();
        	y[i] = sc.nextInt();
        }
        x[n + 1] = x[1];
        y[n + 1] = y[1];
        	
        int[] dir = new int[n + 2];
        /*
         * ESWN
         * 0123
         * */
        for(int i = 1; i < n + 2; i++) {
        	if(x[i] == x[i - 1]) {
        		if(y[i] > y[i - 1]) {
        			dir[i - 1] = 3;
        		} else {
        			dir[i - 1] = 1;
        		}
        	} else {
        		if(x[i] > x[i - 1]) {
        			dir[i - 1] = 0;
        		} else {
        			dir[i - 1] = 2;
        		}
        	}
        }
        
        for(int i = 1; i < n + 1; i++) {
        	if((dir[i] - 1 + 4) % 4 == dir[i - 1])
        		ans++;
        }
        out.println(n - ans);
                
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
