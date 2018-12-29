import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class C {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		int n = sc.nextInt(), m = sc.nextInt();
		
		ArrayList<ArrayList<Integer>> g = new ArrayList<ArrayList<Integer>>();
		for(int i = 0; i <= n; i++)
			g.add(new ArrayList<Integer>());
		
		int[] inp = new int[n];
		
		for(int i = 0; i < n; i++) {
			inp[i] = sc.nextInt();
			if(inp[i] <= m)
				g.get(inp[i]).add(i);
			else
				g.get(0).add(i);
		}
		
		// 7 4
		// 1 2 3 4 1 2 3
		
		// 3 0
		// 1 2 3 4 1 2 3
		
		// take (valid num > n / m) for adjustment
		// if not done, take (others > n / m) for adjustment
		ArrayDeque<Integer> q = new ArrayDeque<Integer>();
		for(int i = 1; i <= m; i++) {
			if(g.get(i).size() < n / m) {
				q.add(i);
			}
		}
		
		int useStrategy = 1, ans = 0;
		while(q.isEmpty() == false) {
			int cur = q.getFirst();
			
			while(g.get(cur).size() < n / m) {
				System.err.println(cur);
				boolean hasAdustment = false;
				for(int i = 1; i <= n && useStrategy == 1 && g.get(cur).size() < n / m; i++) {
					if(g.get(i).size() > n / m) {
						hasAdustment = true;
						inp[g.get(i).get(g.get(i).size() - 1)] = cur;
						g.get(cur).add(g.get(i).get(g.get(i).size() - 1));
						g.get(i).remove(g.get(i).size() - 1);
						ans++;
						break;
					}
				}
				
				if(hasAdustment == false && g.get(cur).size() < n / m) {
					useStrategy = 2;
					
					inp[g.get(0).get(g.get(0).size() - 1)] = cur;
					g.get(cur).add(g.get(0).get(g.get(0).size() - 1));
					g.get(0).remove(g.get(0).size() - 1);
					ans++;
				}
			}
			
			q.removeFirst();
		}
		
		out.println((n / m) + " " + ans);
		for(Integer i : inp)
			out.print(i + " ");

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
