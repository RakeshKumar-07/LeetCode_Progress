class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> vis(leftChild.size(), false);
        int initialNode = -1;
        for(int i=0;i<leftChild.size();i++){
            if(leftChild[i] != -1) vis[leftChild[i]] = true;
            if(rightChild[i] != -1) vis[rightChild[i]] = true;
        }
        for(int i=0;i<vis.size();i++){
            if(!vis[i]){
                initialNode = i;
                break;
            }
        }
        if(initialNode == -1) return false;
        for(int i=0;i<vis.size();i++) vis[i] = false;
        queue<int> q;
        q.push(initialNode);
        vis[initialNode] = true;
        while(q.size()>0){
            int size = q.size();
            while(size--){
                int t = q.front();
                q.pop();
                if((leftChild[t] != -1 && vis[leftChild[t]]) || (rightChild[t] != -1 && vis[rightChild[t]])) return false;
                if(leftChild[t] != -1){
                    vis[leftChild[t]] = true;
                    q.push(leftChild[t]);
                }
                if(rightChild[t] != -1){
                    vis[rightChild[t]] = true;
                    q.push(rightChild[t]);
                }
            }
        }

        for(int i=0;i<vis.size();i++) if(!vis[i]) return false;

        return true;
    }
};