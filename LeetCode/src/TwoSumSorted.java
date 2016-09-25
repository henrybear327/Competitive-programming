import java.util.Arrays;

public class TwoSumSorted {
	/**
	 * Binary search for key. 
	 * @param numbers array of integers
	 * @param key Integer to search
	 * @return Integer -1 if key not found, otherwise index of the key
	 */
	public int binarySearch(int[] numbers, int key) {		
		int l = -1, r = numbers.length; //(l, r)
		while(r - l > 1) {
			int mid = (l + r) / 2;
			if(numbers[mid] == key)
				return mid;
			else if(numbers[mid] > key)
				r = mid;
			else
				l = mid;
		}
		
		return -1;
	}
	
	public int[] twoSum(int[] numbers, int target) {
		// binary search
		/*
		for (int i = 0; i < numbers.length; i++) {
			// int idx = Arrays.binarySearch(numbers, target - numbers[i]);
			int idx = binarySearch(numbers, target - numbers[i]);
			if (idx < 0)
				continue;
			else if (idx != i)
				return new int[] { Math.min(i + 1, idx + 1), Math.max(i + 1, idx + 1)};
		}
		
		return null;
		*/
		
		// two pointer
		/*
		 * Observation 
		 * a < b < c < d < e < ....
		 * if the left pointer moves right, sum will increase
		 * if the right pointer moves left, sum will decrease
		 */
		
		int l = 0, r = numbers.length - 1;
		// assume there are more than 1 number
		int sum = numbers[l] + numbers[r];
		while(sum != target) {
			if(sum > target) 
				r--;
			else
				l++;
			sum = numbers[l] + numbers[r];
		}
		
		if(sum == target)
			return new int[] { l + 1, r + 1};
		else
			return null;
	}

	public static void main(String[] args) {
		int nums[] = { 2, 7, 11, 15 };
		int target = 9;

		TwoSumSorted s = new TwoSumSorted();
		int[] ans = s.twoSum(nums, target);
		System.out.println(ans[0] + " " + ans[1]);
	}
}