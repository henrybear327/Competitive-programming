import java.io.*;
import java.util.*;

public class Main {
	/*
	public static class Pair implements Comparable<Pair> {
		// private int first, second;
		int first, second;

		// constructor
		public Pair(int a, int b) {
			this.first = a;
			this.second = b;
		}

		public int compareTo(Pair compare_against) {
			if (this.first == compare_against.first)
				return compare_against.second - this.second;
			return this.first - compare_against.first;
		}
		
		// getter
		public int getFirst() {
			return first;
		}

		public int getSecond() {
			return second;
		}
	}*/
	
	public static class Pair {
		int first, second;

		// constructor
		public Pair(int a, int b) {
			this.first = a;
			this.second = b;
		}
	}

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		int n = sc.nextInt(), k = sc.nextInt();

		Pair[] inp = new Pair[n * 2];
		for (int i = 0; i < n; i++) {
			int a = sc.nextInt(), b = sc.nextInt();
			inp[i * 2] = new Pair(a, 1);
			inp[i * 2 + 1] = new Pair(b, -1);
		}
		
		Arrays.sort(inp, (a, b) -> (a.first == b.first ? 
				b.second - a.second : a.first - b.first));
		
		/*
		for (int i = 0; i < n * 2; i++) {
			out.println(inp[i].getFirst() + " " + inp[i].getSecond());
		}
		*/
		
		int[][] ans = new int[n][2];
		int idx = 0;
		
		int cnt = 0, left = 0;
		for(int i = 0; i < n * 2; i++) {
			if(inp[i].second == 1) {
				cnt++;
				if(cnt == k)
					left = inp[i].first;
			} else {
				if(cnt == k) {
					ans[idx][0] = left;
					ans[idx++][1] = inp[i].first;
				} 
				cnt--;
			}
		}
		
		out.println(idx);
		for(int i = 0; i < idx; i++)
			out.println(ans[i][0] + " " + ans[i][1]);
		
		// Start writing your solution here.

		/*
		 * int n = sc.nextInt(); // read input as integer long k =
		 * sc.nextLong(); // read input as long double d = sc.nextDouble(); //
		 * read input as double String str = sc.next(); // read input as String
		 * String s = sc.nextLine(); // read whole line as String
		 * 
		 * while(sc.hasNext()) { ... }
		 * 
		 * int result = 3*n; out.println(result); // print via PrintWriter
		 */

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
