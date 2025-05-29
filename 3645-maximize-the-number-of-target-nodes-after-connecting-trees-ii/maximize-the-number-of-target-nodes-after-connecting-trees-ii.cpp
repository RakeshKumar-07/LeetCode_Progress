class Solution {
public:
    pair<int, vector<bool>> bfs(int node, int n, vector<vector<int>>& m){
        vector<bool> vis(n, false), evenNodes(n, false);
        int even = 0;
        bool en = true;
        queue<int> q;
        q.push(node);
        vis[node] = true;
        while(q.size() > 0){
            int s = q.size();
            if(en) even += s;
            while(s--){
                int t = q.front();
                q.pop();
                if(en) evenNodes[t] = true;
                for(int i=0;i<m[t].size();i++){
                    if(!vis[m[t][i]]){
                        q.push(m[t][i]);
                        vis[m[t][i]] = true;
                    }
                }
            }
            en = !en;
        }
        return {even, evenNodes};
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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
        vector<int> ans;
        pair<int, vector<bool>> p;
        p = bfs(0, n2, m2);
        add = max(p.first, n2 - p.first);
        p = bfs(0, n1, m1);
        for(int i=0;i<n1;i++){
            if(p.second[i]) ans.push_back(p.first + add);
            else ans.push_back(n1-p.first + add);
        }
        return ans;
    }
};