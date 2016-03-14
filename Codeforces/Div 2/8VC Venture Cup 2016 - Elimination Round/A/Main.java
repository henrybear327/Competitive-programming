import java.io.*;
import java.util.*;

public class Main
{
	public static boolean go(String cmd)
	{
		// out.printf("%d %s\n", cmd.length(), cmd);
		int x = 0, y = 0;
		for(int i = 0; i < cmd.length(); i++) {
			if(cmd.charAt(i) == 'U')
				y--;
			else if(cmd.charAt(i) == 'D')
				y++;
			else if(cmd.charAt(i) == 'R')
				x++;
			else
				x--;
		}
				
		return (x == 0 && y == 0);
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt();
        String inp = sc.nextLine();
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
        	for(int j = i + 1; j <= n; j++)  {
        		if(go(inp.substring(i,  j)) == true)
        			ans++;
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
