import java.io.*;
import java.util.*;

public class G
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt(), m = sc.nextInt(), 
        		i = sc.nextInt(), j = sc.nextInt(), 
        		a = sc.nextInt(), b = sc.nextInt();
        
        int ans = Integer.MAX_VALUE;
        
        int[] dx = {1, 1, n, n};
        int[] dy = {1, m, 1, m};

        for(int k = 0; k < 4; k++) {
        	int x = Math.abs(i - dx[k]), y = Math.abs(j - dy[k]);
        	if(x == 0 && y == 0) { // on corner
        		ans = 0;
        		break;
        	}
        	if(x % a == 0 && y % b == 0) {
        		if( y == 0 && (x / a) % 2 == 0 && b >= m) {
        			continue;
        		} else if( x == 0 && (y / b) % 2 == 0 && a >= n) {
        			continue;
        		}
        		
        		if( (x / a) % 2 == 0  && (y / b) % 2 == 0)
        			ans = Math.min(ans, Math.max(x / a, y / b));
        		else if( (x / a) % 2 == 1  && (y / b) % 2 == 1)
        			ans = Math.min(ans, Math.max(x / a, y / b));
        		
        		//out.println(k + " " + ans);
        	}
        }
        
        out.println((ans == Integer.MAX_VALUE ? "Poor Inna and pony!" : ans));
        
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
