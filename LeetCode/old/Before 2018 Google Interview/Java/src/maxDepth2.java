import java.util.*;

public class maxDepth2 {
	public int maxDepth(TreeNode root) {
        if(root == null)
        	return 0;
        return Math.max(maxDepth(root.left), maxDepth(root.right)) + 1;
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
		maxDepth2 s = new maxDepth2();
	}
}