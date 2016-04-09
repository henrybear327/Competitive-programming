import java.io.*;
import java.util.*;

public class A
{
    public static int gcd(int a, int b)
    {
        return a == 0 ? b : gcd(b % a, a);
    }

    public static ArrayList<Integer> prime = new ArrayList<Integer>();
    public static void mp()
    {
    	boolean[] isprime = new boolean[50000];
        Arrays.fill(isprime, true);
        isprime[0] = isprime[1] = false;
        for(int i = 2; i < 50000; i++) {
            if(isprime[i] == true) {
                for(int j = 2; i * j < 50000; j++)
                    isprime[i * j] = false;
            }
        }

        for(int i = 2; i < 50000; i++)
            if(isprime[i] == true)
                prime.add(i);
    }

    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        mp();
        
        int n = sc.nextInt();
        // bitch... simply add 1 between a and b will make the pairs in (a, 1, b) co-prime....

        int[] ans = new int[2 * n];
        int ptr = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            int cur = sc.nextInt();

            if(i == 0) {
                ans[ptr++] = cur;
            } else {
                if(gcd(ans[ptr - 1], cur) == 1) {
                    ans[ptr++] = cur;
                } else {
                    for(int j = 0; j < prime.size(); j++)
                        if(gcd(prime.get(j), cur) == 1 && gcd(prime.get(j), ans[ptr - 1]) == 1) {
                        	cnt++;
                            ans[ptr++] = prime.get(j);
                            ans[ptr++] = cur;
                            break;
                        }
                }
            }
        }
        
        out.println(cnt);
        for(int i = 0; i < ptr; i++)
            out.printf("%d ", ans[i]);

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
