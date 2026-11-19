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
    vector<vector<int>> allPaths;

    void dfs(TreeNode* node, int currentSum, vector<int> currentPath, int targetSum) {
        if (node == NULL) return;
        currentPath.push_back(node->val);
        currentSum += node->val;

        if (node->left == NULL && node->right == NULL) {
            if (currentSum == targetSum) {
                allPaths.push_back(currentPath);
            }
        }

        dfs(node->left, currentSum, currentPath, targetSum);
        dfs(node->right, currentSum, currentPath, targetSum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, 0, {}, targetSum);
        return allPaths;
    }
};
