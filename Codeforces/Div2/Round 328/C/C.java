import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C
{
	public static long gcd(long a, long b) {
		return a == 0 ? b : gcd(b % a, a);
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        long l = sc.nextLong(), a = sc.nextLong(), b = sc.nextLong();
        BigInteger ll = BigInteger.valueOf(l);
        BigInteger aa = BigInteger.valueOf(a);
        BigInteger bb = BigInteger.valueOf(b);
        
        //long lcm = a / gcd(a, b) * b;
        BigInteger lcm = aa.divide(aa.gcd(bb)).multiply(bb);
        //out.println(lcm);
        
        if(aa.equals(bb))
        	out.println("1/1");
        else {
        	BigInteger minn = aa.min(bb);
        	BigInteger ans = minn.subtract(BigInteger.ONE);
        	BigInteger cnt = ll.divide(lcm);
        	ans = ans.add((cnt.subtract(BigInteger.ONE)).multiply(minn));


        	if((lcm.multiply(cnt).add(minn)).compareTo(ll) <= 1) {
        		ans = ans.add(minn);
        	} else {
        		ans.add(ll.subtract(lcm.multiply(cnt))).add(BigInteger.ONE);
        	}
        	BigInteger gg = ans.gcd(ll);
        	out.println(ans.divide(gg) + "/" + ll.divide(gg));
        }
        	
        /*
        if(lcm <= 1) 
        	out.println("1/1");
        else {
        	long ans = Math.min(a, b) - 1;
        	
        	long cnt = l / lcm;
        	ans += (cnt - 1) * Math.min(a,  b);
        	
        	if(lcm * cnt + Math.min(a, b) <= l) {
        		ans += Math.min(a, b);
        	} else {
        		ans += (l - lcm * cnt + 1);
        	}
            out.println((ans / gcd(ans, l)) + "/" + (l / gcd(ans, l)));
        }
        */
                
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
