/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum = 0;

    void dfs(TreeNode* node, int num) {
        if (node == NULL) return;

        num = (num * 10) + node->val;
        if (node->left == NULL && node->right == NULL) {
            sum += num;
            return;
        }
        
        /**
        * 123:
        * num = 0;
        * 0 + 1
        * (10 * 1) + 2
        * num = 12;
        * (12 * 10) + 3
        * num = 123???????
        */

        dfs(node->left, num);
        dfs(node->right, num);
    }

    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return sum;
    }
};
