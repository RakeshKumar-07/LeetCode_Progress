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
    int ans = 0;

    void traverse(TreeNode* root, int h, int l){
        if(root == NULL){
            ans = max(ans, h - l);
            return;
        }
        if(root->val >= h) h = root->val;
        if(root->val <= l) l = root->val;
        traverse(root->left, h, l);
        traverse(root->right, h, l);
    }

    int maxAncestorDiff(TreeNode* root) {
        traverse(root, -1, INT_MAX);
        return ans;
    }
};