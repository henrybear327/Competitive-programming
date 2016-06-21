import java.io.*;
import java.util.*;

public class C
{
	public static long[] dp;
	public static ArrayList<ArrayList<Edge>> g;
	public static int cnt = 0;
	public static void dfs(int u, int par, long minSoFar, long sumSoFar, boolean fail)
	{
		if(dp[u] < (sumSoFar - minSoFar) || fail == true) {
			fail = true;
			cnt++;
			//out.println(u);
		}
		
		for(Edge i : g.get(u)) {
			int v = i.v;
			long w = i.w;
			//out.println(u + " " + v + " " + w);
			if(v == par)
				continue;
			
			dfs(v, u, Math.min(minSoFar,  sumSoFar + w), sumSoFar + w, fail);
		}
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n;
        n = sc.nextInt();
        dp = new long[n + 1];
        
        for(int i = 1; i <= n; i++) {
        	dp[i] = sc.nextInt();
        }
        
        g = new ArrayList<ArrayList<Edge>>();
        for(int i = 0; i <= n; i++)
        	g.add(new ArrayList<Edge>());
        
        for(int i = 2; i <= n; i++) {
        	int v = sc.nextInt(), w = sc.nextInt();
        	g.get(i).add(new Edge(v, w));
        	g.get(v).add(new Edge(i, w));
        }
        
        dfs(1, -1, 0, 0, false);
        out.println(cnt);
        out.close();
    }
    
    public static class Edge {
    	public int v;
    	long w;
    	public Edge(int v, long w) {
    		this.v = v;
    		this.w = w;
    	}
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
