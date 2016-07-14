import java.io.*;
import java.util.*;

public class B
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        String inp = sc.nextLine();
        int n = inp.length();
        
        char[] arr = {'A', 'H', 'M', 'O', 'o', 'T', 'U', 'V', 'v', 'W', 'w', 'X', 'x', 'Y', 'I'};
        if(inp.length() % 2 == 0) {
        	for(int i = 0; i < n / 2; i++) {
        		boolean ok1 = false, ok2 = false;
        		for(int j = 0; j < arr.length; j++) {
        			if(arr[j] == inp.charAt(i))
        				ok1 = true;
        			if(arr[j] == inp.charAt(n - 1 - i))
        				ok2 = true;
        		}
        		
        		char l = inp.charAt(i);
        		char r = inp.charAt(n - 1 - i);
        		if((l == 'p' && r == 'q') || (l == 'q' && r == 'p'))
        			ok1 = ok2 = true;
        		if((l == 'b' && r == 'd') || (l == 'd' && r == 'b'))
        			ok1 = ok2 = true;
        		
        		if( (ok1 == false || ok2 == false) ) {
        			out.println("NIE");
        	        out.close();

        			System.exit(0);
        		}
        	}
        } else {
        	boolean okok = false;
        	for(int j = 0; j < arr.length; j++) {
    			if(arr[j] == inp.charAt(n / 2))
    				okok = true;
    		}
        	if(okok == false) {
        		out.println("NIE");
                out.close();

    			System.exit(0);
        	}
        	
        	for(int i = 0; i < n / 2; i++) {
        		boolean ok1 = false, ok2 = false;
        		for(int j = 0; j < arr.length; j++) {
        			if(arr[j] == inp.charAt(i))
        				ok1 = true;
        			if(arr[j] == inp.charAt(n - 1 - i))
        				ok2 = true;
        		}
        		
        		char l = inp.charAt(i);
        		char r = inp.charAt(n - 1 - i);
        		if((l == 'p' && r == 'q') || (l == 'q' && r == 'p'))
        			ok1 = ok2 = true;
        		if((l == 'b' && r == 'd') || (l == 'd' && r == 'b'))
        			ok1 = ok2 = true;
        		
        		if( (ok1 == false || ok2 == false) ) {
        			out.println("NIE");
        	        out.close();

        			System.exit(0);
        		}
        	}
        }
        
        out.println("TAK");
        
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
