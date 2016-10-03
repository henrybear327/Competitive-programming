import java.util.*;

public class minDepth {
	public static int depth;
	
	public void dfs(TreeNode root, int level) {
    	if(root == null) {
    		return;
    	}
		
		dfs(root.left, level + 1);
		dfs(root.right, level + 1);
		
		if(root.left == null && root.right == null)
		    depth = Math.min(depth, level);
	}
	
	public int minDepth(TreeNode root) {
	    if(root == null)
	        return 0;
		depth = Integer.MAX_VALUE;
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
		minDepth s = new minDepth();
	}
}