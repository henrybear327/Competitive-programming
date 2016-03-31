import java.io.*;
import java.util.*;

public class E
{
	public static class UFDS
	{
		public int[] par = new int[100100];
		public UFDS() {
			Arrays.fill(par, -1);
		}
		public int root(int x) {
			return par[x] < 0 ? x : (par[x] = root(par[x]));
		}
		
		public void merge(int x, int y) {
			int rx = root(x);
			int ry = root(y);
			
			if(rx != ry) {
				if(par[rx] > par[ry]) {
					int tmp = rx;
					rx = ry;
					ry = tmp;
				}
				
				par[rx] += par[ry];
				par[ry] = rx;
			}
		}
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt(), m = sc.nextInt();
        
        UFDS s = new UFDS();
        for(int i = 0; i < m; i++) {
        	int a = sc.nextInt(), b = sc.nextInt();
        	s.merge(a, b);
        }
        
        for(int i = 1; i <= n; i++) {
        	s.root(i);
        }
        
        for(int i = 1; i <= n; i++) {
        	out.println(i + " -> " + s.par[i]);
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
