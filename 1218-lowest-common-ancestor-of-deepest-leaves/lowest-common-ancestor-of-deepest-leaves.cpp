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
    TreeNode* ans = NULL;
    int subTree = 0, dp = INT_MIN;

    int dfs(TreeNode* root, int depth){
        if(root == NULL) return 0;
        int l = 0, r = 0;
        if(root->left) l = dfs(root->left, depth + 1);
        if(root->right) r = dfs(root->right, depth + 1);

        if(l == r && subTree < l+r+1 && depth + max(l,r) == dp){
            ans = root;
            subTree = l+r+1;
        }

        dp = max(dp, depth);
        return 1 + max(l, r);
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        dfs(root, 0);
        // cout<<dp<<endl;
        subTree = 0;
        dfs(root, 0);
        return ans;
    }
};