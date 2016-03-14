import java.io.*;
import java.util.*;

public class Main_stuck {
	public static void init_is_prime(boolean[] is_prime) {
		for(int i = 0; i < is_prime.length; i++) {
			out.println(i);
			is_prime[i] = true;
		}
		
		
		is_prime[1] = false;
		for (int i = 2; i < 1000010; i++) {
			if (is_prime[i] == true) {
				int j = 2;
				while (i * j < 1000010) {
					is_prime[i * j] = false;
					j++;
				}
			}
		}
		out.println("End!");
	}

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		long n = sc.nextLong();

		HashMap<Long, Integer> cnt = new HashMap<Long, Integer>();

		boolean[] is_prime = new boolean[1000010];
		init_is_prime(is_prime);

		for (long i = 2; i * i <= n; i++) {
			if (is_prime[(int) i] == false)
				continue;
			while (n % i == 0) {
				int tmp = cnt.get(i) != null ? cnt.get(i) + 1 : 1;
				cnt.put(i, tmp);
				n /= i;
			}
		}

		if (n != 1)
			cnt.put(n, 1);

		long ans = 1;
		for (Long tmp : cnt.keySet()) {
			ans *= tmp;
		}

		out.println(ans); // print via PrintWriter

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
