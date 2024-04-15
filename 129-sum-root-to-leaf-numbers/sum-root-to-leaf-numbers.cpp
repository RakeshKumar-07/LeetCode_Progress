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
    void dfs(TreeNode* root, vector<int> t, vector<vector<int>> &ans){
        if(root == NULL) return;
        if(root->right == NULL && root->left == NULL){
            t.push_back(root->val);    
            ans.push_back(t);
            return;
        }
        t.push_back(root->val);
        dfs(root->left, t, ans);
        dfs(root->right, t, ans);
    }
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> t;
        dfs(root, t, ans);
        int result = 0;
        for(int i=0;i<ans.size();i++){
            int temp = 0;
            for(int j=0;j<ans[i].size();j++) temp += ans[i][j]*pow(10,ans[i].size() - j - 1);
            result += temp;
        }
        return result;
    }
};