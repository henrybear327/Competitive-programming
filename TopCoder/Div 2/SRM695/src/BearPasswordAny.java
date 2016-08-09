import java.io.*;
import java.util.*;

public class BearPasswordAny {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();

		int[] x = new int[n];
		for (int i = 0; i < n; i++)
			x[i] = sc.nextInt();

		System.out.println(findPassword(x));
	}

	public static String findPassword(int[] x) {
		String res = "";
		char next = 'a';
		boolean hasNonZero = true;
		while (hasNonZero == true) {
			hasNonZero = false;

			for (int i = x.length - 1; i >= 0; i--) {
				if (x[i] != 0) {
					hasNonZero = true;

					if (res.length() + i + 1 > x.length)
						return "";
					for (int j = 0; j < i + 1; j++)
						res += next;
					next = next == 'a' ? 'b' : 'a';

					int minus = 1;
					for (int j = i; j >= 0; j--) {
						if (x[j] < minus)
							return "";
						x[j] -= minus;
						minus++;
					}
				}
			}
			
			//System.out.println(res);
		}
		
		while(res.length() < x.length) {
			return "";
		}

		return res;
	}
}
