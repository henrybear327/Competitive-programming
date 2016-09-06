import java.io.*;
import java.util.*;

public class A
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt();
        char[][] ans = new char[n][10];
        boolean has = false;
        for(int i = 0; i < n; i++) {
        	String inp = sc.nextLine();
        	ans[i] = inp.toCharArray();
        	
        	if(has)
        		continue;
        	if(ans[i][0] == ans[i][1] && ans[i][0] == 'O') {
        		ans[i][0] = ans[i][1] = '+';
        		has = true;
        	} else if(ans[i][3] == ans[i][4] && ans[i][3] == 'O') {
        		ans[i][3] = ans[i][4] = '+';
        		has = true;
        	}
        }
        
        if(has) {
        	out.println("YES");
	        for(int i = 0; i < n; i++)
	        	out.println(ans[i]);
        } else {
        	out.println("NO");
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
