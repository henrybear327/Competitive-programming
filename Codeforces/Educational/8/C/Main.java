import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		int n = sc.nextInt(), d = sc.nextInt();
		char[] inp = sc.nextLine().toCharArray();

		char[] ans = new char[n];
				
		for (int i = 0; i < n; i++) {
			int diffz = inp[i] + d <= 'z' ? d : 'z' - inp[i];
			int diffa = inp[i] - d >= 'a' ? d : inp[i] - 'a';

			if (d == 0) {
				ans[i] = inp[i];
			} else if (diffz > diffa) {
				d -= diffz;
				ans[i] = (char) (inp[i] + diffz);
			} else {
				d -= diffa;
				ans[i] = (char) (inp[i] - diffa);
			}
		}

		if (d != 0)
			out.println("-1");
		else {
			/*
			 * for (int i = 0; i < n; i++) out.printf("%c", ans[i]);
			 */
			
			/*
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < n; i++)
				sb.append(ans[i]);
			sb.append('\n');
			out.println(sb);
			*/
			out.println(new String(ans));
		}

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
