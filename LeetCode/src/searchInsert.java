import java.util.*;

public class searchInsert {
	public int searchInsert(int[] nums, int target) { // upper bound
		int l = -1, r = nums.length;
		while(r - l > 1) {
			// 0 0 0 0 1 1 1 1 1
			int mid = (l + r) / 2;
			if(nums[mid] == target) 
				return mid;
			else if(nums[mid] > target)
				r = mid;
			else 
				l = mid;
		}
		return r;
	}

	public static void main(String argc[]) {
		searchInsert s = new searchInsert();
		System.err.println(s.searchInsert(new int[] {1, 3, 5, 6}, 0));
	}
}