class Solution {
public:
    int m, dist[30001];
    bool vis[30001];
    int initialDist(int node, map<int, vector<int>> &graph, int len){
        vis[node] = true;
        int l = 0;
        for(auto i:graph[node])
        if(!vis[i]){
            l += initialDist(i, graph, len+1);
        }
        return len + l;
    }

    int nodesBelowEachNode(int node, map<int,vector<int>> &graph){
        vis[node] = true;
        int l = 0;
        for(auto i:graph[node])
        if(!vis[i]){
            l += nodesBelowEachNode(i, graph);
        }
        return dist[node] =  l+1;
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        m = edges.size();
        memset(dist, 0 ,sizeof(dist));
        memset(vis, false ,sizeof(vis));
        map<int, vector<int>> graph;
        for(int i=0;i<m;i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        // finding answer for node 0
        int curr_dist = initialDist(0, graph, 0);
        
        // dist array filling
        memset(vis, false ,sizeof(vis));
        nodesBelowEachNode(0, graph);

        memset(vis, false ,sizeof(vis));
        vector<int> ans(n,0);
        queue<pair<int,int>> q;
        q.push({0, curr_dist});
        vis[0] = true;
        ans[0] = curr_dist;
        while(!q.empty()){
            int k = q.size();
            while(k!=0){
                pair<int,int> p = q.front();
                q.pop();
                for(auto i : graph[p.first]){
                    if(!vis[i]){
                        vis[i] = true;
                        ans[i] = p.second + n - 2*dist[i];
                        q.push({i, ans[i]});
                    }
                }
                k--;
            }
        }
        return ans;
    }
};