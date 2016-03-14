import java.io.*;
import java.util.*;

public class Main {
	static int n, b, p, ans = 0, ansp;
	/*
	public static int cal(int n)
	{
		int cnt = 0;
		
		while(n > 1) {
			cnt += b * n; //player
			cnt += n / 2; // coach
			n /= 2;
		}
		
		return cnt;
	}
	*/
	
	public static void main(String[] args) {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		n = sc.nextInt();
		b = sc.nextInt();
		p = sc.nextInt();
		ansp = p * n;
		
		/*
		while(n > 0) { 
			int nearest = 1;
			while((nearest << 1) <= n)
				nearest <<= 1;
			ans += cal(nearest);
			n -= nearest;
			if(n == 0)
				break;
			else
				n++;
		}
		*/
		
		// 1 wins, n - 1 loses, and it takes n - 1 contests to eliminate them
		ans = (2 * b + 1) * (n - 1);
		
		out.println(ans + " " + ansp);

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
