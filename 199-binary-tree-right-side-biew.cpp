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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>{};
        queue<TreeNode*> tree;
        vector<int> res;
        TreeNode *cur = root;
        tree.push(root);
        
        while (!tree.empty()) {
            int siz = tree.size();
            cur = tree.front();
            res.push_back(cur->val);
            for (int i = 0; i < siz; i++){
                cur = tree.front();
                if (cur->right) tree.push(cur->right);
                if (cur->left) tree.push(cur->left);
                tree.pop();
            }
        }
        return res;
    }
};