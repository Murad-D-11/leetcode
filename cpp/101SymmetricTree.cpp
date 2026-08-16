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
    void readLHalf(TreeNode* root, std::vector<int>& vecLHalf) {
        if (!root) {
            vecLHalf.push_back(1000);
            return;
        }

        vecLHalf.push_back(root->val);

        readLHalf(root->left, vecLHalf);
        readLHalf(root->right, vecLHalf);
    }

    void readRHalf(TreeNode* root, std::vector<int>& vecRHalf) {
        if (!root) {
            vecRHalf.push_back(1000);
            return;
        }

        vecRHalf.push_back(root->val);

        readRHalf(root->right, vecRHalf);
        readRHalf(root->left, vecRHalf);
    }

    bool isSymmetric(TreeNode* root) {
        std::vector<int> vecLHalf, vecRHalf;
        TreeNode* rootLHalf = root->left;
        TreeNode* rootRHalf = root->right;

        readLHalf(rootLHalf, vecLHalf);
        readRHalf(rootRHalf, vecRHalf);

        if (vecLHalf == vecRHalf) return true;
        return false;
    }
};
