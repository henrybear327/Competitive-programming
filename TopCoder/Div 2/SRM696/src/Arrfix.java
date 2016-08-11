import java.io.*;
import java.util.*;

public class Arrfix {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int[] A = new int[n];
		int[] B = new int[n];
		int m = sc.nextInt();
		int[] F = new int[m];

		for (int i = 0; i < n; i++)
			A[i] = sc.nextInt();
		for (int i = 0; i < n; i++)
			B[i] = sc.nextInt();
		for (int i = 0; i < m; i++)
			F[i] = sc.nextInt();

		System.out.println(mindiff(A, B, F));
	}

	public static int mindiff(int[] A, int[] B, int[] F) {
		boolean[] used = new boolean[A.length];
		Arrays.fill(used, false);

		for (int i = 0; i < A.length; i++) {
			if (A[i] != B[i]) {
				for (int j = 0; j < F.length; j++) {
					if (B[i] == F[j]) {
						A[i] = F[j];
						F[j] = -1;
						used[i] = true;
						break;
					}
				}
			}
		}

		int cnt = 0;
		for (int i = 0; i < F.length; i++)
			if (F[i] != -1)
				cnt++;

		if (cnt > 0) {
			// same to same, this costed me an AC
			for (int i = 0; i < A.length && cnt > 0; i++) {
				for (int j = 0; j < F.length; j++) {
					if (F[j] != -1 && F[j] == A[i] && used[i] == false) {
						F[j] = -1;
						used[i] = true;
						cnt--;
						break;
					}
				}
			}

			// change orig diff
			for (int i = 0; i < A.length && cnt > 0; i++) {
				if (A[i] != B[i] && used[i] == false) {
					for (int j = 0; j < F.length; j++) {
						if (F[j] != -1) {
							A[i] = F[j];
							F[j] = -1;
							used[i] = true;
							cnt--;
							break;
						}
					}
				}
			}

			if (cnt > 0) {
				// change orig same
				for (int i = 0; i < A.length; i++) {
					if (used[i] == false) {
						for (int j = 0; j < F.length; j++) {
							if (F[j] != -1) {
								A[i] = F[j];
								F[j] = -1;
								break;
							}
						}
					}
				}
			}
		}

		int res = 0;
		for (int i = 0; i < A.length; i++)
			if (A[i] != B[i])
				res++;
		return res;
	}
}
