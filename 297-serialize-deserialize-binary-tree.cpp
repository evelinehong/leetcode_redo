/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // remember to use pointer here;
    queue <TreeNode*> tree;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "";
        tree.push(root);
        string res;
        while (!tree.empty()) {
            int siz = tree.size();
            for (int i = 0; i < siz; i++){
                TreeNode *n = tree.front();
                tree.pop();
                if (n == nullptr) {res += "null;"; continue;}
                res += to_string(n->val) + ";";
                tree.push(n->left);
                tree.push(n->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (!data.size()) return nullptr;
        vector<string> nodes;
        string node = "";
        for (auto &c: data){
            if (c == ';') {nodes.push_back(node); node = "";}
            else node += c;
        }
        TreeNode* root = new TreeNode(std::stoi(nodes[0]));
        tree.push(root);
        int cnt = 1;
        while (!tree.empty()) {
            int siz = tree.size();
            for (int i = 0; i < siz; i++){
                TreeNode *n = tree.front();
                tree.pop();
                if (cnt < nodes.size()) {
                    if (nodes[cnt] == "null") {n->left = nullptr;}
                    else{
                        n->left = new TreeNode(std::stoi(nodes[cnt]));
                        tree.push(n->left);
                    }
                    cnt++;
                    
                }
                if (cnt < data.size()) {
                    if (nodes[cnt] == "null") {n->right = nullptr;}
                    else {
                        n->right = new TreeNode(std::stoi(nodes[cnt]));
                        tree.push(n->right);
                    }
                    cnt++;
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));