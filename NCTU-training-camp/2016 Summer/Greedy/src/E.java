import java.io.*;
import java.util.*;

public class E {
	public static void shuffle(int[] inp) {
		Random rnd = new Random();
		for (int i = 0; i < inp.length; i++) {
			int nxt = Math.abs(rnd.nextInt()) % inp.length;

			int tmp = inp[i];
			inp[i] = inp[nxt];
			inp[nxt] = tmp;
		}
	}

	public static void fail() {
		out.println("-1");
		out.close();
		System.exit(0);
	}

	public static boolean onlyZero(int[] cnt) {
		for (int i = 1; i < 10; i++)
			if (cnt[i] > 0)
				return false;
		return true;
	}

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		int n = sc.nextInt();
		
		// Huge output can simply cause TL

		int[] inp = new int[n];
		int[] cnt = new int[10];
		int sum = 0;
		for (int i = 0; i < n; i++) {
			inp[i] = sc.nextInt();
			cnt[inp[i]]++;
			sum += inp[i];
		}

		shuffle(inp);
		Arrays.sort(inp);

		if (cnt[0] == 0) {
			fail();
		}
		
		StringBuilder sb = new StringBuilder();
		if (sum % 3 == 0) {
			if (onlyZero(cnt))
				sb.append("0");
			else
				for (int i = inp.length - 1; i >= 0; i--)
					sb.append(inp[i]);
		} else if (sum % 3 == 1) {
			boolean ok = false;
			for (int i = 1; i < 10; i += 3) {
				if (cnt[i] > 0) {
					cnt[i]--;
					ok = true;
					break;
				}
			}

			if (ok == false) {
				int tmp = 0;
				for (int i = 2; i < 10 && ok == false; i += 3) {
					if (cnt[i] > 0) {
						tmp += cnt[i] > 1 ? 2 : 1;
						cnt[i] -= cnt[i] == 1 ? 1 : 2;
						ok = tmp == 2;
					}
				}
			}

			if (ok == false)
				fail();
			else if (onlyZero(cnt))
				sb.append("0");
			else {
				for (int i = 9; i >= 0; i--) {
					for (int j = 0; j < cnt[i]; j++)
						sb.append(i);
				}
			}
		} else {
			boolean ok = false;
			for (int i = 2; i < 10; i += 3) {
				if (cnt[i] > 0) {
					cnt[i]--;
					ok = true;
					break;
				}
			}

			if (ok == false) {
				int tmp = 0;
				for (int i = 1; i < 10 && ok == false; i += 3) {
					if (cnt[i] > 0) {
						tmp += cnt[i] > 1 ? 2 : 1;
						cnt[i] -= cnt[i] == 1 ? 1 : 2;
						ok = tmp == 2;
					}
				}
			}

			if (ok == false)
				fail();
			else if (onlyZero(cnt))
				sb.append("0");
			else {
				for (int i = 9; i >= 0; i--) {
					for (int j = 0; j < cnt[i]; j++)
						sb.append(i);
				}
			}
		}
		out.println(sb);
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
