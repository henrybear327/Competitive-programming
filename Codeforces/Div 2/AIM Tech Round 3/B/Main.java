import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt();
        
        int[] inp = new int[n];
        
        for(int i = 0; i < n; i++) 
        	inp[i] = sc.nextInt();
        
        Arrays.sort(inp);
        
        long ans = inp[n - 1];
        int ok = inp[n - 1] - 1;
        for(int i = n - 2; ok > 0 && i >= 0; i--) {
        	if(ok > inp[i]) {
        		ans += inp[i];
        		ok = inp[i] - 1;
        	} else {
        		ans += ok;
        		ok--;
        	}
        }
        
        out.println(ans);

        // Start writing your solution here.

        /*
        int n      = sc.nextInt();        // read input as integer
        long k     = sc.nextLong();       // read input as long
        double d   = sc.nextDouble();     // read input as double
        String str = sc.next();           // read input as String
        String s   = sc.nextLine();       // read whole line as String

	while(sc.hasNext()) {
		...
	}

        int result = 3*n;
        out.println(result);                    // print via PrintWriter
        */

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
