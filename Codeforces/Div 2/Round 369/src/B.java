import java.io.*;
import java.util.*;

public class B
{
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        int n = sc.nextInt();
        if(n == 1)
        	out.println("1");
        else {	
        	long[][] inp = new long[n][n];
        	int zx = -1, zy = -1;
        	for(int i = 0; i < n; i++)
        		for(int j = 0; j < n; j++) {
        			inp[i][j] = sc.nextInt();
        			if(inp[i][j] == 0) {
        				zx = i;
        				zy = j;
        			}
        		}
        	
        	/*
        	 * 1 15 5
        	 * 11 7 3
        	 * 9 0 13
        	 */
        	TreeMap<Long, Integer> s = new TreeMap<Long, Integer>(); // need to keep the count
        	for(int i = 0; i < n; i++) {
        		long sum = 0;
        		for(int j = 0; j < n; j++) {
        			sum += inp[i][j];
        		}
        		int tmp = s.getOrDefault(sum, 0);
        		tmp++;
        		s.put(sum, tmp);
        	}
        	
        	for(int j = 0; j < n; j++) {
        		long sum = 0;
        		for(int i = 0; i < n; i++) {
        			sum += inp[i][j];
        		}
        		int tmp = s.getOrDefault(sum, 0);
        		tmp++;
        		s.put(sum, tmp);
        	}
        	
        	long sum = 0, sum1 = 0;
        	for(int i = 0; i < n; i++) {
        		sum += inp[i][i];
        		sum1 += inp[i][n - 1 - i];
        	}
        	int tmp = s.getOrDefault(sum, 0);
    		tmp++;
    		s.put(sum, tmp);
    		
    		tmp = s.getOrDefault(sum1, 0);
    		tmp++;
    		s.put(sum1, tmp);
        	
        	if(s.size() != 2 || s.lastEntry().getValue() < s.firstEntry().getValue()) {
        		out.println("-1");
        	} else { 
        		// original input may be wrong! WTF
        		/*
        		 * 1 2 1 1 1
        		 * 1 1 2 1 1
        		 * 2 1 1 0 1
        		 * 1 1 1 1 2
        		 * 1 1 1 2 1
        		 */
        		if((zx == zy || zx + zy == n - 1) && s.firstEntry().getValue() == ((n % 2 == 1 && zx == zy && zx == n / 2) ? 4 : 3)) // only n == odd and 0 right at middle will need to have 4
        			out.println(s.lastKey() - s.firstKey());
        		else if(s.firstEntry().getValue() == 2)
        			out.println(s.lastKey() - s.firstKey());
        		else
        			out.println("-1");
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
