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

    void dfs(TreeNode* node, bool parentEven, bool grandparentEven) {
        if (node == NULL) return;

        if (grandparentEven) {
            sum += node->val;
        }

        bool currentEven = (node->val % 2 == 0);

        dfs(node->left, currentEven, parentEven);
        dfs(node->right, currentEven, parentEven);
    }

    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, false, false);
        return sum;
    }
};
