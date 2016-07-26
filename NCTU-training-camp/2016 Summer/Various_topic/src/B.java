import java.io.*;
import java.math.BigInteger;
import java.util.*;
import java.util.Map.Entry;

public class B
{
    public static void main(String[] args)
    {
    	MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        String inp = sc.next();
        HashMap<Character, Integer> cnt = new HashMap<Character, Integer>();
        for(int i = 0; i < inp.length(); i++) {
        	int tmp = cnt.getOrDefault(inp.charAt(i), 0);
        	tmp++;
        	cnt.put(inp.charAt(i), tmp);
        }
        
        int turn = 1;
        while(inp.length() > 0) {
        	int even = 0;
        	Character c = null;
        	for(Entry<Character, Integer> i : cnt.entrySet()) {
        		if(i.getValue() % 2 == 0) {
        			even++;
        		} else {
        			c = i.getKey();
        		}
        	}
        	if(even >= cnt.size() - 1) {
        		out.println(turn == 1 ? "First" : "Second");
        		break;
        	} else {
        		turn = turn == 1 ? 2 : 1;
        		int tmp = cnt.get(c);
        		cnt.put(c, tmp - 1);
        	}
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
