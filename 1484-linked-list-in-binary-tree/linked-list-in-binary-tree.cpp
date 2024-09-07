/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        queue<int> list;
        while(head != NULL){
            list.push(head->val);
            head = head->next;
        }
        queue<pair<TreeNode*, queue<int>>> q;
        queue<int> currList;
        currList.push(root->val);
        q.push({root, currList});
        while(q.size() > 0){
            int size = q.size();
            while(size--){
                pair<TreeNode*, queue<int>> t = q.front();
                q.pop();
                if(list == t.second) return true;
                if(t.first->left != NULL){
                    queue<int> newList = t.second;
                    if(newList.size() == list.size()) newList.pop();
                    newList.push(t.first->left->val);
                    q.push({t.first->left, newList});
                }
                if(t.first->right != NULL){
                    queue<int> newList = t.second;
                    if(newList.size() == list.size()) newList.pop();
                    newList.push(t.first->right->val);
                    q.push({t.first->right, newList});
                }
            }
        }
        return false;
    }
};