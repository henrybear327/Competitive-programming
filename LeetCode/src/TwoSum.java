import java.util.Arrays;
import java.util.HashMap;

public class TwoSum {
	public int[] twoSum(int[] nums, int target) {
		// brute force
		/*
		for (int i = 0; i < nums.length; i++) {
			for(int j = 0; j < nums.length; j++) {
				if(i != j) {
					if(nums[i] + nums[j] == target) {
						int[] res = {i, j};
						return res;
					}
				}
			}
		}
		*/
		
		//hash table
		HashMap<Integer, Integer> table = new HashMap<Integer, Integer>();
		
		for(int i = 0; i < nums.length; i++)
			table.put(nums[i], i);
		for(int i = 0; i < nums.length; i++) {
			int idx = table.getOrDefault(target - nums[i], -1);
			if(idx != -1 && idx != i) {
				return new int[] {i, table.get(target - nums[i])}; // nice and neat, one line
			}
		}

		return null;
	}

	public static void main(String[] args) {
		int nums[] = { 3, 2, 4 };
		int target = 6;

		Solution s = new Solution();
		int[] ans = s.twoSum(nums, target);
		System.out.println(ans[0] + " " + ans[1]);
	}
}