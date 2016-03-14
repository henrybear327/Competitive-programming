import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt();
        
        String inp = sc.nextLine();
        
        int[] cnt = new int[3]; //RGB
        for(int i = 0; i < inp.length(); i++) {
        	if(inp.charAt(i) == 'R')
        		cnt[0]++;
        	else if(inp.charAt(i) == 'G')
        		cnt[1]++;
        	else
        		cnt[2]++;
        }
        
        int tmp = 0;
        for(int i = 0; i < 3; i++)
        	if(cnt[i] > 0)
        		tmp++;
        boolean only_one = (tmp == 1);
        
        if((cnt[0] != 0 && cnt[1] != 0 && cnt[2] != 0) || (
        		(cnt[0] > 1 && cnt[1] > 1) || (cnt[1] > 1 && cnt[2] > 1) || 
        		(cnt[0] > 1 && cnt[2] > 1)) )
        	out.println("BGR");
        else {
        	if(n == 1 || only_one == true)
        		out.print(inp.charAt(0));
        	else {
        		if(cnt[0] == 0) {
        			if(cnt[1] > cnt[2]) // G > B
        				out.println("BR");
        			else if(cnt[1] == cnt[2])
        				out.println("R");
        			else
        				out.println("GR");
        		} else if(cnt[1] == 0) { 
        			if(cnt[0] > cnt[2]) // R > B
        				out.println("BG");
        			else if(cnt[0] == cnt[2])
        				out.println("G");
        			else
        				out.println("GR");
        		} else {
        			if(cnt[0] > cnt[1]) // R > G
        				out.println("BG");
        			else if(cnt[0] == cnt[1])
        				out.println("B");
        			else
        				out.println("BR");
        		}
        	}
        }
        
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
