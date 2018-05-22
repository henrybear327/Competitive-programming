import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		int n = sc.nextInt();

		long[] inp = new long[n]; // using type int will cause problem! (map is
									// of type long)
		HashMap<Long, Integer> cnt = new HashMap<Long, Integer>();
		for (int i = 0; i < n; i++) {
			inp[i] = sc.nextInt();
			int tmp = cnt.getOrDefault(inp[i], 0);
			// out.println(tmp);
			tmp++;
			cnt.put(inp[i], tmp);
		}

		long ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 33; j++) {
				long diff = (1L << j) - inp[i];

				if (cnt.containsKey(diff) == true) {
					// out.println(diff + " " + inp[i] + " " + cnt.get(diff));
					ans += (diff == inp[i] ? cnt.get(diff) - 1 : cnt.get(diff));
				}
			}
		}

		out.println(ans / 2);

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