/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func dfs(root *TreeNode, depth int, mx *int) {
    if(root == nil) {
        return
    }
    
    if depth > *mx {
        *mx = depth
    }
    dfs(root.Left, depth + 1, mx);
    dfs(root.Right, depth + 1, mx);
}

func maxDepth(root *TreeNode) int {
    ans := 0
    dfs(root, 1, &ans)
    
    return ans
}
