import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class Main {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		int n = sc.nextInt();

		HashMap<Integer, Integer> s1 = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> s2 = new HashMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			int a, b;
			a = sc.nextInt();
			b = sc.nextInt();
			
			s1.put(b - a, s1.getOrDefault(b - a, 0) + 1);
			s2.put(b + a, s2.getOrDefault(b + a, 0) + 1);
			
			/*
			int c1 = s1.containsKey(b - a) ? s1.get(b - a) : 0;
			s1.put(b - a, c1 + 1);
			int c2 = s2.containsKey(b + a) ? s2.get(b + a) : 0;
			s2.put(b + a, c2 + 1);
			*/
		}

		long ans = 0;
		
		for(Entry<Integer, Integer> temp : s1.entrySet()) {
			ans += temp.getValue() * (temp.getValue() - 1) / 2;
		}
		
		for(Entry<Integer, Integer> temp : s2.entrySet()) {
			ans += temp.getValue() * (temp.getValue() - 1) / 2;
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
