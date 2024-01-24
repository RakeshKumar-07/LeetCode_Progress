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

    void solve(TreeNode* root, vector<int> &f){
        f[root->val]++;
        if(root->left == NULL && root->right == NULL){
            int odd = 0;
            for(int i=0;i<10;i++) if(f[i]%2 != 0) odd++;
            if(odd < 2) ans++;
            f[root->val]--;
            return;
        }
        if(root->left != NULL) solve(root->left, f);
        if(root->right != NULL) solve(root->right, f);
        f[root->val]--;
        return;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> f(10, 0);
        solve(root, f);
        return ans;
    }
};