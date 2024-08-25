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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        stack<TreeNode*> s;
        s.push(root);
        map<TreeNode*, bool> m;
        m[NULL] = true;

        vector<int> ans;

        while(s.size() > 0){
            TreeNode* t = s.top();

            if(t->right != NULL && !m[t->right]) s.push(t->right);
            if(t->left != NULL && !m[t->left]) s.push(t->left);
            
            if(m[t->left] && m[t->right]){
                ans.push_back(t->val);
                m[t] = true;
                s.pop();
            }
        }
        return ans;
    }
};