import java.io.*;
import java.util.*;

public class C
{
	public static ArrayList<ArrayList<Integer>> g;
	
	public static boolean dfs(int u, int[] seen, int color) 
	{		
		color = color == 1 ? 2 : 1;
		
		ArrayList<Integer> next = new ArrayList<Integer>();
		for(Integer v : g.get(u)) {
			if(seen[v] == 0) {
				seen[v] = color;
				next.add(v);
			} else {
				if(seen[v] == color)
					continue;
				else
					return false;
			}
		}
		
		boolean res = true;
		for(Integer v : next) {
			res = dfs(v, seen, color);
			if(res == false)
				return res;
		}
		
		return res;
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));

        int n = sc.nextInt(), m = sc.nextInt();
        
        g = new ArrayList<ArrayList<Integer>>();
        for(int i = 0; i <= n; i++)
        	g.add(new ArrayList<Integer>());
        
        for(int i = 0; i < m; i++) {
        	int u = sc.nextInt(), v = sc.nextInt();
        	g.get(u).add(v);
        	g.get(v).add(u);
        }		
        
        int[] seen = new int[n + 1];
        Arrays.fill(seen, 0);
        boolean ans = true;
        for(int i = 1; i <= n; i++) {
        	if(seen[i] == 0) {
        		int color = 1;
        		seen[i] = color;
        		if(dfs(i, seen, color) == false) {
        			ans = false;
        			break;
        		}
        	}
        }
        
        if(ans == false)
        	out.println("-1");
        else {
        	ArrayList<Integer> ans1 = new ArrayList<Integer>();
        	for(int i = 1; i <= n; i++) {
        		if(seen[i] == 1)
        			ans1.add(i);
        	}
        	ArrayList<Integer> ans2 = new ArrayList<Integer>();
        	for(int i = 1; i <= n; i++) {
        		if(seen[i] == 2)
        			ans2.add(i);
        	}
        	
        	out.println(ans1.size());
        	StringBuilder sb = new StringBuilder();
        	for(Integer i : ans1)
        		sb.append(i).append(" ");
        	out.println(sb);
        	sb = new StringBuilder();
        	out.println(ans2.size());
        	for(Integer i : ans2)
        		sb.append(i).append(" ");
        	out.println(sb);
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
