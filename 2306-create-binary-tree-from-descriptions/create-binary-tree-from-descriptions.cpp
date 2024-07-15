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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, pair<TreeNode*, bool>> m;
        for(int i=0;i<descriptions.size();i++){
            if(m[descriptions[i][0]].first == NULL){
                TreeNode* t = new TreeNode(descriptions[i][0]);
                m[descriptions[i][0]].first = t;
                m[descriptions[i][0]].second = false;
            }
            if(m[descriptions[i][1]].first == NULL) {
                TreeNode* t = new TreeNode(descriptions[i][1]);
                m[descriptions[i][1]].first = t;
                m[descriptions[i][1]].second = false;
            }
            if(descriptions[i][2] == 1){
                m[descriptions[i][0]].first->left = m[descriptions[i][1]].first;
                m[descriptions[i][1]].second = true;
            }
            else{
                m[descriptions[i][0]].first->right = m[descriptions[i][1]].first;
                m[descriptions[i][1]].second = true;
            }
        }
        TreeNode* ans = NULL;
        for(auto i:m) if(i.second.second == false) ans = i.second.first;
        return ans;
    }
};