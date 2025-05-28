class Solution {
public:
    int bfs(int node, int n, int k, vector<vector<int>>& m){
        vector<bool> vis(n, false);
        int ans = 0;
        queue<int> q;
        q.push(node);
        vis[node] = true;
        while(q.size() > 0 && k >= 0){
            int s = q.size();
            ans += s;
            while(s--){
                int t = q.front();
                q.pop();
                for(int i=0;i<m[t].size();i++){
                    if(!vis[m[t][i]]){
                        q.push(m[t][i]);
                        vis[m[t][i]] = true;
                    }
                }
            }
            k--;
        }
        return ans;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size()+1, n2 = edges2.size()+1;
        vector<vector<int>> m1(n1), m2(n2);
        for(int i=0;i<edges1.size();i++){
            m1[edges1[i][0]].push_back(edges1[i][1]);
            m1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i=0;i<edges2.size();i++){
            m2[edges2[i][0]].push_back(edges2[i][1]);
            m2[edges2[i][1]].push_back(edges2[i][0]);
        }
        int add = 0;
        for(int i=0;i<n2;i++) add = max(add, bfs(i, n2, k-1, m2));
        vector<int> ans;
        for(int i=0;i<n1;i++) ans.push_back(add + bfs(i, n1, k, m1));
        return ans;
    }
};