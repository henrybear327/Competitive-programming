import java.io.*;
import java.math.BigInteger;
import java.util.*;

/*
The first observation — we don't care about the actual strings, 
all information we need — number of pairs {0,0}, {0,1}, {1,0}, {1,1}. 

Count that and then just follow the greedy algorithm:
for the first player: try to get a index with {1,1} if there are some, than {1,0}, than {0,1} and than {0,0}.
For the second player similar strategy: first {1,1}, than {0,1}, than {1,0}, than {0,0}.

After that just compare who has more 1.
*/
public class F
{
    public static void main(String[] args)
    {
    	MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt();
        
        String str1 = sc.nextLine();
        String str2 = sc.nextLine();
        
        int bothOne = 0, bothZero = 0;
        int one1 = 0, one2 = 0;
        for(int i = 0; i < 2 * n; i++) {
        	if(str1.charAt(i) == str2.charAt(i)) {
        		if(str1.charAt(i) == '1')
        			bothOne++;
        		else
        			bothZero++;
        	} else {
        		if(str1.charAt(i) == '1')
        			one1++;
        		else
        			one2++;
        	}
        }
        
        one1 += bothOne / 2 + bothOne % 2;
        one2 += bothOne / 2;
        
        /* Special case:
        4
        11100000
        10011110
        */
        // when min(first, second) used up all of their 1s, they will try to reduce the opponent's chance
        // of getting 1s by selecting the (1, 0) pair of their side.
        int mn = Math.min(one1, one2);
        
        int r1 = one1 - mn;
        int r2 = one2 - mn;
        
        r1 = (r1 + 1) / 2;
        r2 /= 2;
        
        one1 = mn + r1;
        one2 = mn + r2;

        if(one1 == one2)
        	out.println("Draw");
        else if(one1 > one2)
        	out.println("First");
        else
        	out.println("Second");
        
        
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
