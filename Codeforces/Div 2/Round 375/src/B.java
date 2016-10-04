import java.io.*;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.IFLE;

public class B
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt();
        String inp = sc.nextLine();
                
        int len = 0, cnt = 0;
        
        int l = -1;
        boolean in = false;
        for(int i = 0; i <= n; i++) {
        	char c = i != n ? inp.charAt(i) : '_';
        	//out.println("Before: " + i + " " + c + " " + l +  " " + len + " " + cnt);

        	if(c == '_' || i == n) {
        		if(l == -1)
        			continue;
        		
        		if(in == true)
        			cnt++;
        		else 
        			len = Math.max(len, i - l);
        		l = -1;
        	} else if(c == '(') {
        		if(l != -1)
        			len = Math.max(len, i - l);
        		l = -1;
        		in = true;
        	} else if(c == ')') {
        		in = false;
        		if(l != -1) {
        			cnt++;
        		}
        		l = -1;
        	} else {
        		if(l == -1)
        			l = i;
        		continue;
        	}
        	//out.println("After: " + i + " " + c + " " + l +  " " + len + " " + cnt);

        }
        
        out.println(len + " " + cnt);
        
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
