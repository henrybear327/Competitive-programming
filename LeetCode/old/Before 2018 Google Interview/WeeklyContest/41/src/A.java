import java.math.*;
import java.util.*;

public class A {
	public double findMaxAverage(int[] nums, int k) {
		double res = 0;
		if (nums.length < k) {
			for (int i = 0; i < nums.length; i++)
				res += nums[i];
			return res / nums.length;
		}

		int sum = 0;
		for (int i = 0; i < k; i++)
			sum += nums[i];

		double mx = (double) sum / k; // GG
		for (int i = 0; i + k <= nums.length; i++) {
			mx = Math.max(mx, (double) sum / k);
			// System.out.println((double)sum / k);

			if (i + k < nums.length) {
				sum += nums[i + k];
				sum -= nums[i];
			}
		}

		return mx;
	}

	public static void main(String args[]) {
//		int[] data = new int[] { 1, 12, -5, -6, 50, 3 };
		int[] data = new int[] { -1 };
		System.out.println(new A().findMaxAverage(data, 1));
	}
}
