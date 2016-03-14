import java.io.*;
import java.util.*;

public class Main {
	public static long gcd(long a, long b) {
		return b == 0 ? a : gcd(b, a % b);
	}

	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		// while (true) {
		/*
		 * // WA // long a = sc.nextInt(), b = sc.nextInt(); long a = (long)
		 * (Math.random() * 100) % 10 + 1, b = (long) (Math.random() * 100) % 10
		 * + 1;
		 * 
		 * long i = 1, x = 2 * a, y = 3 * b; while (6 * i <= Math.min(x, y))
		 * i++; i--;
		 * 
		 * while (i > 0) { boolean xi; if (x > y) { xi = false; y += 3; } else {
		 * xi = true; x += 2; }
		 * 
		 * if (x == y) // 6 3 will get you wrong // changing to x += 2 --> 10, 9
		 * will get you wrong, because you don'y know if // the multiple of 6 is
		 * used or not if (xi == true) x += 2; else y += 3;
		 * 
		 * i--; // out.printf("%d %d\n", x, y); }
		 * 
		 * out.println(Math.max(x, y));
		 * 
		 * // end WA 5
		 */

		// linear search for answer
		/*
		 * int n = sc.nextInt(), m = sc.nextInt();
		 * 
		 * int i = 1; while(!(n <= i / 2 && m <= i / 3 && n + m <= i / 2 + i / 3
		 * - i / 6)) i++; out.println(i);
		 */

		// Binary search for answer
		int n = sc.nextInt(), m = sc.nextInt();
		// int n = (int) a, m = (int) b;

		int left = 1, right = 6 * Math.max(n, m);
		while (right - left > 1) {
			int mid = (left + right) / 2;

			if (n <= mid / 2 && m <= mid / 3 && n + m <= mid / 2 + mid / 3 - mid / 6)
				right = mid;
			else
				left = mid;
		}

		out.println(right);
		// left is WA and right is AC because left only holds the ELSE case

		/*
		 * if (Math.max(x, y) != right) { out.println("Error: " + a + ' ' + b);
		 * break; } else out.println("Ok: " + a + ' ' + b);
		 */
		// }
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
