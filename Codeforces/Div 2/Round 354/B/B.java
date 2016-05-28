import java.io.*;
import java.util.*;

public class B {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		final double EPS = 1e-9;

		int n = sc.nextInt(), t = sc.nextInt();
		double[][] state = new double[n][];
		for (int i = 0; i < n; i++) {
			state[i] = new double[i + 1];
		}

		int ans = 0;
		if (t < 1) {
			ans = 0;
		} else {
			state[0][0] = t;
			for (int i = 0; i < n - 1; i++) {
				for (int j = 0; j < state[i].length; j++) {
					// fill the current cup
					double left = state[i][j] - 1;
					if (left >= -EPS) {
						state[i][j] = 1;
						ans++;
					} else {
						continue;
					}

					// push down
					state[i + 1][j] += left / 2;
					if (j + 1 < state[i + 1].length)
						state[i + 1][j + 1] += left / 2;
				}
			}

			for (int i = 0; i < state[n - 1].length; i++)
				if (state[n - 1][i] - 1 > -EPS) // more than one will be fine
					ans++;
		}

		out.println(ans);

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
