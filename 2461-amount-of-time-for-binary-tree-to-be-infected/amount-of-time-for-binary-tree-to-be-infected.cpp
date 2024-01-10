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
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> m;
        int ans = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() != 0){
            int size = q.size();
            while(size--){
                TreeNode* t = q.front();
                q.pop();
                if(t->left != NULL){
                    m[t->val].push_back(t->left->val);
                    m[t->left->val].push_back(t->val);
                    q.push(t->left);
                }
                if(t->right != NULL){
                    m[t->val].push_back(t->right->val);
                    m[t->right->val].push_back(t->val);
                    q.push(t->right);
                }
            }
        }
        vector<bool> vis(100001, false);
        queue<pair<int, int>> p;
        p.push({start, 0});
        while(p.size() != 0){
            int size = p.size();
            while(size--){
                pair<int, int> t = p.front();
                vis[t.first] = true;
                ans = max(ans, t.second);
                p.pop();
                for(int i = 0;i<m[t.first].size();i++){
                    if(!vis[m[t.first][i]]){
                        p.push({m[t.first][i], t.second+1});
                    }
                }
            }
        }
        return ans;
    }
};