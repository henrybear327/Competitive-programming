import java.io.*;
import java.util.*;

public class D
{
	public static int n, m, k, accum, error, idx;
	public static int[] dx, dy;
	public static char[][] map;
	public static boolean checkBound(int x, int y) 
	{
		return (0 <= x && x < n) && (0 <= y && y < m);
	}
	
	public static void dfs(int x, int y, int[][] seen) {
		// System.err.println("dfs:" + x + " " + y + " " + error);
		if(seen[x][y] != -1)
			return;
		seen[x][y] = idx;
		accum++;
		
		for(int i = 0; i < 4; i++) {
			int xx = x + dx[i], yy = y + dy[i];
			// System.err.println("xx yy:" + xx + " " + yy + " " + checkBound(xx, yy) + " " + error);

			if(checkBound(xx, yy) == true) {
				if(map[xx][yy] == '.')
					dfs(xx, yy, seen);
			} else {
				// System.err.println("error xx yy:" + xx + " " + yy);

				error = 1;
			}
		}
	}
	
    public static void main(String[] args)
    {
        MyScanner sc = new MyScanner();
        out = new PrintWriter(new BufferedOutputStream(System.out));
        
        n = sc.nextInt(); m = sc.nextInt(); k = sc.nextInt();
        
        dx = new int[] {1, -1, 0, 0};
        dy = new int[] {0, 0, 1, -1};
        
        map = new char[n][];
        for(int i = 0; i < n; i++) {
        	String row = sc.nextLine();
        	map[i] = row.toCharArray();
        }
        
        TreeMap<Integer, ArrayList<Integer>> size = new TreeMap<Integer, ArrayList<Integer>>(); // size, idx
        int[][] seen = new int[n][m];
        for(int i = 0; i < n; i++)
        	Arrays.fill(seen[i], -1);
        
        idx = 0;
        int haveLake = 0;
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
        		if(map[i][j] == '.' && seen[i][j] == -1) {
        			accum = 0;
        			error = 0;
        			idx++;
        			
        			// System.err.println(i + " " + j);
        			dfs(i, j, seen);
        			
        			if(error == 1) 
        				continue;
        			
        			if(size.containsKey(accum) == false)
        				size.put(accum, new ArrayList<Integer>());
        			size.get(accum).add(idx);
            		//System.out.println("id1x: " + idx);

        			haveLake++;
        		}
        	}
        }
        
        int ans = 0;
        while(haveLake > k) {
        	ans += size.firstKey();
        	
        	int idx = size.firstEntry().getValue().get(0);
    		//System.out.println("idx: " + idx);

        	for(int i = 0; i < n; i++) {
            	for(int j = 0; j < m; j++) {
            		if(seen[i][j] == idx) {
            			map[i][j] = '*';
            		}
            	}
        	}
			haveLake--;

        	
        	if(size.firstEntry().getValue().size() == 1)
        		size.remove(size.firstKey());
        	else
        		size.firstEntry().getValue().remove(0);
        }
        
        out.println(ans);
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < n; i++) {
        	for(int j = 0; j < m; j++) {
        		sb.append(map[i][j]);
        	}
        	sb.append("\n");
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
