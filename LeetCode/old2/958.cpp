/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        // Approach 2: let's count total number of nodes, and label the nodes by
        // their position if the last node's label != total number of nodes -> we
        // are missing shits
        if (root == NULL)
            return true;
        int total = 0;
        int mx = -1;

        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 1));
        while (q.size() > 0) {
            auto cur = q.front();
            q.pop();

            total++;
            mx = max(mx, cur.second);

            if (cur.first->left != NULL)
                q.push(make_pair(cur.first->left, cur.second * 2));

            if (cur.first->right != NULL)
                q.push(make_pair(cur.first->right, cur.second * 2 + 1));
        }

        return total == mx;

        //         // approach 1: for each level, we check if it is complete
        // there are several cases to watch out for though
        //         if(root == NULL)
        //             return true;

        //         queue<TreeNode*> q;
        //         q.push(root);
        //         int levelSize = 1;
        //         while(q.size() > 0) {
        //             // cout << q.size() << endl;
        //             // check current level
        //             int tmp = levelSize;
        //             int sz = q.size();
        //             queue<TreeNode*> cur;
        //             bool flag = false;
        //             while(sz--) {
        //                 if(q.front() == NULL) {
        //                     flag = true;
        //                 } else if(q.front() != NULL && flag == true) {
        //                     return false;
        //                 }

        //                 cur.push(q.front());
        //                 q.pop();
        //             }

        //             // push in next level
        //             int cnt = 0;
        //             int nextNotNULL = 0;
        //             while(cur.size() > 0) {
        //                 if(cur.front() == NULL) {
        //                     cnt += 2;
        //                     q.push(NULL);
        //                     q.push(NULL);
        //                 } else {
        //                     q.push(cur.front()->left);
        //                     if(q.back() == NULL)
        //                         cnt++;
        //                     else
        //                         nextNotNULL++;
        //                     q.push(cur.front()->right);
        //                     if(q.back() == NULL)
        //                         cnt++;
        //                     else
        //                         nextNotNULL++;
        //                 }
        //                 cur.pop();
        //             }

        //             if(flag == true && nextNotNULL > 0)
        //                 return false;

        //             if(cnt == levelSize * 2)
        //                 break;

        //             levelSize *= 2;
        //         }

        //         return true;
    }
};
