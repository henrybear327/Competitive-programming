import java.util.*;

public class minDepthBFS {	
	public int minDepth(TreeNode root) {
		if(root == null)
			return 0;
		
	    // bfs
		HashMap<TreeNode, Integer> level = new HashMap<TreeNode, Integer>();
		Deque<TreeNode> q = new ArrayDeque<TreeNode>();
		q.push(root);
		level.put(root, 1);
		while(q.isEmpty() == false) {
			TreeNode cur = q.pollFirst();
			System.err.println(cur.val);
			
			if(cur.left == null && cur.right == null)
				return level.get(cur);
			
			if(cur.left != null) {
				q.addLast(cur.left);
				level.put(cur.left, level.get(cur) + 1);
			}
			if(cur.right != null) {
				q.addLast(cur.right);
				level.put(cur.right, level.get(cur) + 1);
			}
		}
		
		return 0;
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
		TreeNode root = new TreeNode(9);
		root.left = new TreeNode(3);
		root.right = new TreeNode(20);
		root.right.left = new TreeNode(15);
		root.right.right = new TreeNode(7);
		
		minDepthBFS s = new minDepthBFS();
		s.minDepth(root);
	}
}