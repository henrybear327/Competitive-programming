import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class G
{
    public static void main(String[] args)
    {
    	MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        String inp = sc.nextLine();
        
        int z = 0, o = 0;
        for(int i = 0; i < inp.length(); i++)
        	if(inp.charAt(i) == '0')
        		z++;
        	else
        		o++;
        
        out.println(Math.min(z, o));
        	
        
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
