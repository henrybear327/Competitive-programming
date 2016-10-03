import java.util.*;

public class checkBST {
	public boolean checkBST(TreeNode root, long left, long right) { // (left, right)
		if(root == null) 
			return true;
				
		if(left < root.val && root.val < right) {
			boolean okLeft = checkBST(root.left, left, root.val);
			boolean okRight = checkBST(root.right, root.val, right);
			
			return okLeft && okRight;
		}
		return false;
	}

	public boolean isValidBST(TreeNode root) {
		// Do own checking function
		return checkBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
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
		checkBST s = new checkBST();
	}
}