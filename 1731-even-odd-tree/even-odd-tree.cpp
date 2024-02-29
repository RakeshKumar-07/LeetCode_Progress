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
    bool isEvenOddTree(TreeNode* root) {
        int it = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            it++;
            int size = q.size();
            int prev = it&1 ? -1 : 1000001;
            while(size--){
                TreeNode* t = q.front();
                q.pop();
                // cout<<it<<" -> "<<prev<<" => "<<t->val<<endl;
                if(it%2 != t->val%2 || (t->val%2==1 && prev >= t->val) || (t->val%2==0 && prev <= t->val)) return false;
                prev = t->val;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return true;
    }
};