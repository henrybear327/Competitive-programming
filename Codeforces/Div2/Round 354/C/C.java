import java.io.*;
import java.util.*;

public class C
{
	public static int count(char c, int n, int k, String inp) 
	{
		// binary search for the range and check works, too.
		
		int res = 0;
		int swap = 0, left = 0;
		
		//case k = 0!!
		for(int i = 0; i < n; i++) {
			if(inp.charAt(i) == c && swap < k) {
				swap++;
			} else if(inp.charAt(i) == c && swap >= k){
				res = Math.max(res, i - left);
				while(left != i && inp.charAt(left) != c) {
					left++;
				}
				if(left != i || k == 0)
					left++;
			}
			res = Math.max(res, i + 1 - left);
		}
		
		res = Math.max(res, n - left);
		
		return res;
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt(), k = sc.nextInt();;
        String inp = sc.nextLine();
        
        out.println(Math.max(count('a', n, k, inp), count('b', n, k, inp)));
        
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
