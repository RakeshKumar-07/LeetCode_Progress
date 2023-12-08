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
    string tree2str(TreeNode* root) {
        if(root == NULL) return "";
        string t = to_string(root->val), left = "(", right = "(";
        if(root->left) left += tree2str(root->left);
        left += ")";
        if(root->right) right += tree2str(root->right);
        right += ")";
        if(right.size() > 2) t += left + right;
        else if(left.size() > 2) t += left;
        return t;
    }
};