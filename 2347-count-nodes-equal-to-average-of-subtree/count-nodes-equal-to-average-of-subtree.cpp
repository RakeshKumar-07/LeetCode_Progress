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

    pair<int,int> solve(TreeNode* root){
        pair<int,int> t = {}, temp = {};
        if(root->left != NULL) temp = solve(root->left);
        t.first += temp.first;
        t.second += temp.second;
        temp = {};
        if(root->right != NULL) temp = solve(root->right);
        t.first += temp.first;
        t.second += temp.second;
        // cout<<root->val<<" -> "<<t.first + root->val<<" -> "<<t.second + 1<<endl;
        if(root->left == NULL && root->right == NULL){
            ans++;
            return {root->val, 1};
        }
        if((t.first + root->val)/(t.second + 1) == root->val) ans++;
        return {t.first + root->val, t.second + 1};
    }

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};