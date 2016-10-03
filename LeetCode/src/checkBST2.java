import java.util.*;

public class checkBST2 {
	public boolean checkBST(TreeNode root, Integer left, Integer right) { // (left, right)
		if(root == null)
			return true;
		
		if( (left == null || (left != null && left < root.val)) 
				&& (right == null || (right != null && root.val < right)) ) {
			boolean okLeft = checkBST(root.left, left, root.val);
			boolean okRight = checkBST(root.right, root.val, right);
			
			return okLeft && okRight;
		}
		return false;
	}

	public boolean isValidBST(TreeNode root) {
		if (root == null)
			return true;

		// Do own checking function
		return checkBST(root, null, null);
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
		checkBST2 s = new checkBST2();
	}
}