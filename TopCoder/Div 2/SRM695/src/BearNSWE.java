import java.io.*;
import java.util.*;

public class BearNSWE {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = sc.nextInt();

		String dir = sc.nextLine();
		dir = sc.nextLine();
		
		System.out.println(totalDistance(a, dir));
	}

	public static double totalDistance(int[] a, String dir) {
		String direction = "NSWE";
		int[] dx = { 0, 0, -1, 1 };
		int[] dy = { 1, -1, 0, 0 };

		double res = 0.0;

		int x = 0, y = 0;
		for (int i = 0; i < a.length; i++) {
			for (int j = 0; j < 4; j++) {
				if (dir.charAt(i) == direction.charAt(j)) {
					int xx = dx[j] * a[i];
					int yy = dy[j] * a[i];

					x += xx;
					y += yy;

					//System.out.println(x + " " + y);
					//System.out.println(xx + " " + yy);

					res += (Math.abs(xx) + Math.abs(yy));

					break;
				}
			}
		}

		res += Math.sqrt(x * x + y * y);

		return res;
	}
}
