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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if(root != NULL) q.push(root);
        while(q.size() > 0){
            int size = q.size();
            int temp = INT_MIN;
            while(size--){
                TreeNode* t = q.front();
                q.pop();
                temp = max(t->val, temp);
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};