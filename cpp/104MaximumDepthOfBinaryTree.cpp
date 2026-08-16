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
    void findAllPaths(TreeNode* root, std::vector<int>& currentPath, std::vector<std::vector<int>>& allPaths) {
        if (root == nullptr) return;

        // add node's value to the path vector
        currentPath.push_back(root->val);

        // check if the next node is not a leaf node
        if (root->left == nullptr && root->right == nullptr) { // <--- leaf
            allPaths.push_back(currentPath); // saves the node path
        } else {
            findAllPaths(root->left, currentPath, allPaths);
            findAllPaths(root->right, currentPath, allPaths);
        }

        // backtracks and removes the node from the currentPath before switching to a different path
        currentPath.pop_back();
    }

    int maxDepth(TreeNode* root) {
        std::vector<int> path;
        std::vector<std::vector<int>> allPaths;
        int maxDepth = 0;

        findAllPaths(root, path, allPaths);

        // find the path with the largest amount of elements
        for (int i = 0; i < allPaths.size(); i++) {
            if (maxDepth < allPaths[i].size()) maxDepth = allPaths[i].size(); 
        }

        return maxDepth;
    }
};
