import java.util.*;

// 1AC, nice! Finally... you got one 1AC...
public class sortedArrayToBST {
	public TreeNode buildBST(int[] nums, int left, int right) {
		System.err.println(left + " " + right);
		
		if(right < left)
			return null;
		
		// [left, right]		
		int mid = (left + right) / 2;
		TreeNode root = new TreeNode(nums[mid]);
		root.left = buildBST(nums, left, mid - 1);
		root.right = buildBST(nums, mid + 1, right);
		
		return root;
	}
	
	public TreeNode sortedArrayToBST(int[] nums) {
		return buildBST(nums, 0, nums.length - 1);
	}

	public static class TreeNode {
		int val;
		TreeNode left;
		TreeNode right;

		TreeNode(int x) {
			val = x;
		}
	}

	public static void main(String argc[]) {
		sortedArrayToBST s = new sortedArrayToBST();
		s.sortedArrayToBST(new int[] {1, 2, 3, 4, 5});
	}
}