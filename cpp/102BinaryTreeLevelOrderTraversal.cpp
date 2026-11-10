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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        if (root == NULL) return levels;
        
        deque<TreeNode*> dq;
        dq.push_back(root);
        levels.push_back({root->val});

        while (!dq.empty()) {
            int size = dq.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = dq.front();
                dq.pop_front();

                if (node->left != NULL) {
                    dq.push_back(node->left);
                    level.push_back(node->left->val);
                }
                
                if (node->right != NULL) {
                    dq.push_back(node->right);
                    level.push_back(node->right->val);
                }
            }

            if (!level.empty()) levels.push_back(level);
        }

        return levels;
    }
};
