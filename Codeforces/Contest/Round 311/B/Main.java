import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
       MyScanner sc = new MyScanner();
       out = new PrintWriter(new BufferedOutputStream(System.out));
       
       int n = sc.nextInt(), w = sc.nextInt();
       
       int[] inp = new int[2 * n];
       for(int i = 0; i < 2 * n; i++)
    	   inp[i] = sc.nextInt();
       Arrays.sort(inp);
       
       double a = inp[0], b = inp[n];
       
       double x = Math.min((double) w / (3 * n), Math.min(a, b / 2.0));
       
       out.printf("%f\n", 3 * n * x);

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
