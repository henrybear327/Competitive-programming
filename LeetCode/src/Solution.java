import java.util.*;

public class Solution {
public int findMin(int[] nums) {
        if(nums.length == 1)
        	return nums[0];
        if(nums[0] < nums[nums.length - 1])
        	return nums[0];
        
        int l = 0, r = nums.length;
        while(r - l > 1) {
        	int mid = (l + r) / 2;
        	if(nums[mid] > nums[l])
        		l = mid;
        	else if(nums[mid] < nums[l])
        		r = mid;
        	else 
				l++;
        }
        return nums[r];
    }

	public static void main(String argc[]) {
		Solution s = new Solution();
		System.err.println(s.findMin(new int[] {5, 1, 1, 2, 2, 3, 4}));
	}
}