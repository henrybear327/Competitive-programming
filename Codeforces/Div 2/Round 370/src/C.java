import java.io.*;
import java.util.*;

public class C
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int a = sc.nextInt(), b = sc.nextInt();
        
        ArrayList<Integer> inp = new ArrayList<Integer>();
        
        inp.add(b);
        inp.add(b);
        inp.add(b);
        
        Collections.sort(inp);
        
        int ans = 0;
        while(true) {
        	//System.out.printf("%d %d %d %d\n", inp.get(0), inp.get(1), inp.get(2), a);
        	if( inp.get(0).intValue() == inp.get(1).intValue() && inp.get(1).intValue() == inp.get(2).intValue()
        			&&  inp.get(0).intValue() == a )
        		break;
        	ans++;
        	
        	inp.remove(0);
        	
        	inp.add(Math.min(inp.get(0) + inp.get(1) - 1, a));
        	
        	Collections.sort(inp);
        }
        
        out.println(ans);
        
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
