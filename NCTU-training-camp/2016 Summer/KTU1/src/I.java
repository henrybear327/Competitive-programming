import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class I
{
    public static void main(String[] args)
    {
    	MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        BigInteger[] inp = new BigInteger[3];
        for(int i = 0; i < 3; i++) {
        	String str = sc.nextLine();
        	inp[i] = new BigInteger(str);
        }
        
        boolean ok = false;
        for(int i = 0; i < 3; i++)
        	for(int j = 0; j < 3; j++)
        		for(int k = 0; k < 3; k++)
        			if(inp[i].add(inp[j]).equals(inp[k]))
        				ok = true;
       
        if(ok == true)
        	System.out.println("YES");
        else
        	System.out.println("NO");
        
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
