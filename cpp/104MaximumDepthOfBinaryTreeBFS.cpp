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
    int maxDepth(TreeNode* root) {
        int level = 0;
        if (root == NULL) return level;

        deque<TreeNode*> deque;
        deque.push_back(root);

        while (!deque.empty()) {
            int size = deque.size();

            for (int i = 0; i < size; i++) {
                TreeNode *node = deque.front();
                deque.pop_front();
                
                if (node->left != NULL) deque.push_back(node->left);
                if (node->right != NULL) deque.push_back(node->right);
            }

            level++;
        }

        return level;
    }
};
