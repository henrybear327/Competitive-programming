import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int ncase = sc.nextInt(), n = sc.nextInt(), target = sc.nextInt();
        int cnt_ans = 0;
        StringBuilder st = new StringBuilder();
        
        //for(long i = 32947/*((1L << (n - 1)) + 1)*/; i < 32950/*(1L << n)*/; i+=2L) {
        for(long i = ((1L << (n - 1)) + 1); i < (1L << n); i+=2L) {
        	//System.out.println("i: " + i);
        	boolean ok = true;
        	StringBuilder tmp = new StringBuilder();
        	tmp.append(Long.toBinaryString(i));
        	String binary_string = Long.toBinaryString(i);
        	//out.println("i: " + i + " " + binary_string);
        	for(int j = 2; j <= 10; j++) {
            	BigInteger cur = new BigInteger(binary_string, j);
        		//out.println("j: " + j + " " + cur);

            	if(cur.isProbablePrime(10) == false) {
            		//System.out.println(cur);
            		boolean in_loop = false;
        			for(long k = 2; k < 100000; k++) {
        				if(cur.mod(BigInteger.valueOf((int)k)) == BigInteger.ZERO) {
        					if(k >= 100000)
        						System.out.println(cur + " " + k);
            				in_loop = true;
	        				tmp.append(" ").append(k);
	            			// System.out.println(tmp);
	        				break;
        				}
        			}
        			
        			if(in_loop == false) {
        				ok = false;
        				break;
        			}
            	} else {
            		ok = false;
            		break;
            	}
        	}
        	if(ok == true) {
        		st.append(tmp).append("\n");
        		//out.println(tmp);
        		cnt_ans++;
        		if(cnt_ans >= target)
        			break;
        	}
        }
        
        out.println("Case #1:");
        out.print(st);
        
        
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
