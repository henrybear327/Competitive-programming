import java.io.*;
import java.util.*;
import java.util.Map.Entry;
import java.math.BigInteger;

public class Main_isProbablyPrime
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        long n = sc.nextLong();
        
        HashMap<Long, Integer> cnt = new HashMap<Long, Integer>();    
        
        for(long i = 2; i * i <= n; i++) {
        	BigInteger test = BigInteger.valueOf(i);
        	if(test.isProbablePrime(5) == false)
        		continue;
        	while(n % i == 0) {
        		int tmp = cnt.get(i) != null ? cnt.get(i) + 1 : 1;
        		cnt.put(i, tmp);
        		n /= i;
        	}
        }
        
        if(n != 1)
        	cnt.put(n, 1);
        
        long ans = 1;
        for(Entry<Long, Integer> tmp : cnt.entrySet()) {
        	ans *= tmp.getKey();
        }
        
        out.println(ans);                    // print via PrintWriter

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
