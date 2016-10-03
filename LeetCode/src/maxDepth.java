import java.util.*;

public class maxDepth {
	public static int depth;
	public void dfs(TreeNode root, int level) {
		if(root == null)
			return;
		depth = Math.max(depth, level);
		dfs(root.left, level + 1);
		dfs(root.right, level + 1);
	}
	
	public int maxDepth(TreeNode root) {
        depth = 0;
        dfs(root, 1);
        return depth;
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
		maxDepth s = new maxDepth();
	}
}