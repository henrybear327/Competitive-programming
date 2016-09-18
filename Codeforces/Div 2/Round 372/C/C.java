import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt();
        
        StringBuilder sb = new StringBuilder();
        
        BigInteger num = new BigInteger("2");
        BigInteger square = new BigInteger("2");
        BigInteger gap = new BigInteger("4");
        for(long i = 2; i <= n + 1; i++) {
        	//System.out.println("i = " + i);
        	
    		BigInteger ans = square.multiply(square).subtract(num).divide(BigInteger.valueOf(i - 1));
    		sb.append(ans).append("\n");
    		
    		num = square;
    		square = square.add(gap);
    		gap = gap.add(BigInteger.valueOf(2));
    		
    		/*
    		if(rhs.mod(BigInteger.valueOf(i - 1)).equals(BigInteger.ZERO)) {
    			sb.append("Square = ").append(num.add(BigInteger.valueOf(i - 1).multiply(rhs.divide(BigInteger.valueOf(i - 1))))).append("\n");
    			sb.append(rhs.divide(BigInteger.valueOf(i - 1))).append("\n");
    			num = BigInteger.valueOf(i).multiply(BigInteger.valueOf(j));
    			break;
    		}
    		*/
        }
        out.println(sb);
        
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
