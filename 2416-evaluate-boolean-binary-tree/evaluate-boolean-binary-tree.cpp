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
    bool solve(TreeNode* root){
        if(root->left == NULL && root->right == NULL) return root->val == 1 ? true : false;
        bool t1 = solve(root->left);
        bool t2 = solve(root->right);
        if(root->val == 2) return t1|t2;
        return t1&t2;
    }

    bool evaluateTree(TreeNode* root) {
       return solve(root); 
    }
};