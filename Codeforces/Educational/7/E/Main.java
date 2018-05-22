import java.io.*;
import java.util.*;

public class Main {
	public static int n, cnt;
	public static int[] leaf_depth = new int[500010];

	public static void dfs(int u, int parent, int depth, int[][] g) {
		if(g[u].length == 1) {
			leaf_depth[cnt++] = depth;
			return;
		}
		
		for(int v : g[u]) {
			if(v != parent) {
				dfs(v, u, depth + 1, g);
			}
		}
	}
	
	public static int[][] construct_graph(int n, int[] from, int[] to) {
		/*
		 * Thanks to uwi's Java AC code, making Java almost as fast as c++
		 * http://codeforces.com/contest/622/submission/15935019
		 * */
		int[][] g = new int[n + 1][];
		
		int[] cnt = new int[n + 1];
		for(int u : from)
			cnt[u]++;
		for(int v : to)
			cnt[v]++;
		
		for(int i = 0; i <= n; i++)
			g[i] = new int[cnt[i]];
		
		for(int i = 0; i < n - 1; i++) {
			g[from[i]][--cnt[from[i]]] = to[i];
			g[to[i]][--cnt[to[i]]] = from[i];
		}
		
		return g;
	}
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		n = sc.nextInt();

		int[] from = new int[n - 1];
		int[] to = new int[n - 1]; 
		
		for (int i = 0; i < n - 1; i++) {
			from[i] = sc.nextInt();
			to[i] = sc.nextInt();
		}
		
		int[][] g = construct_graph(n, from, to);
		
		/*
		// print the adj. list out
		int cnt1 = 0;
		for (ArrayList<Integer> u : g) {
			out.printf("%d: ", cnt1++);
			for (int v : u)
				out.printf("%d ", v);
			out.printf("\n");
		}
		*/
		
		int ans = Integer.MIN_VALUE;
		for(int v : g[1]) {
			cnt = 0;
			dfs(v, 1, 1, g);
						
			Arrays.sort(leaf_depth, 0, cnt);
			/*
			for(int i = 0; i < cnt; i++)
				out.printf("%d ", leaf_depth[i]);
			out.printf("\n");
			*/
			
			int[] a = new int[cnt + 1];
			a[0] = 0;
			for(int i = 1; i <= cnt; i++) {
				a[i] = Math.max(leaf_depth[i - 1], a[i - 1] + 1);
				ans = Math.max(ans, a[i]);
			}
		}
		
		out.println(ans);

		// Stop writing your solution here.
		out.close();
	}

	// PrintWriter for faster output
	public static PrintWriter out;

	// MyScanner class for faster input
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		boolean hasNext() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					return false;
				}
			}
			return true;
		}

		String next() {
			if (hasNext())
				return st.nextToken();
			return null;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
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
