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
    int c=0;
    vector<vector<int>> dp;
    void calculatesum(TreeNode* root, int sum, vector<int> &d){
        if(sum-root->val==0 && !root->left && !root->right){
            d.push_back(root->val);
            dp.push_back(d);
            d.pop_back();
        }
        if(root!=NULL){
            d.push_back(root->val);
            if(root->left) calculatesum(root->left, sum-root->val, d);
            d.pop_back();
            d.push_back(root->val);
            if(root->right) calculatesum(root->right, sum-root->val, d);
            d.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> d;
        if(root!=NULL) calculatesum(root,targetSum,d);
        cout<<c<<"\n";
        return dp;
    }
};