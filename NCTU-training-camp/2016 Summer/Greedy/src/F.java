import java.io.*;
import java.util.*;

public class F {
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		String a = sc.nextLine(), s = sc.nextLine();

		char[] aa = a.toCharArray();
		char[] ss = s.toCharArray();

		Character[] sss = new Character[ss.length];
		for (int i = 0; i < ss.length; i++)
			sss[i] = ss[i];

		Arrays.sort(sss, new Comparator<Character>() {
			public int compare(Character o1, Character o2) {
				return o2 - o1;
			}
		});

		int idx = 0;
		for (int i = 0; i < aa.length; i++) {
			if (Character.getNumericValue(aa[i]) < Character.getNumericValue(sss[idx])) {
				aa[i] = sss[idx++];
			}
			if (idx >= sss.length)
				break;
		}

		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < aa.length; i++) {
			sb.append(aa[i]);
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
