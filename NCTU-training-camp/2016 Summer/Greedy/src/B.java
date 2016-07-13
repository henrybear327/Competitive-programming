import java.io.*;
import java.util.*;

public class B
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt(), v = sc.nextInt();
        
        int[] inp = new int[3010];
        for(int i = 0; i < n; i++) {
        	int a = sc.nextInt(), b = sc.nextInt();
        	inp[a] += b;
        }
        
        int ans = 0;
        for(int i = 1; i <= 3001; i++) {
        	int ok = v;
        	ans += inp[i - 1] > v ? v : inp[i - 1];
        	ok -= inp[i - 1] > v ? v : inp[i - 1];
        	
        	if(ok > 0) {
        		ans += inp[i] <= ok ? inp[i] : ok;
        		inp[i] = inp[i] <= ok ? 0 : inp[i] - ok;
        	}
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
