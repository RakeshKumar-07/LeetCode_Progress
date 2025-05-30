class Solution {
public:
    int dist1[100001], dist2[100001];
    bool vis[100001];

    void dfs1(int node, int sum, vector<int>& edges){
        vis[node] = true;
        dist1[node] = sum + 1;
        if(edges[node] == -1) return;
        if(!vis[edges[node]])
            dfs1(edges[node], sum +1, edges);
    }
    void dfs2(int node, int sum, vector<int>& edges){
        vis[node] = true;
        dist2[node] = sum + 1;
        if(edges[node] == -1) return;
        if(!vis[edges[node]])
            dfs2(edges[node], sum +1, edges);
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        for(int i=0;i<100001;i++){
            dist1[i] = INT_MAX;
            dist2[i] = INT_MAX;
        }
        memset(vis, false, sizeof(vis));
        dfs1(node1, -1, edges);
        memset(vis, false, sizeof(vis));
        dfs2(node2, -1, edges);
        int ans = -1, t = INT_MAX;
        for(int i=0;i<n ;i++){
            if(t > max(dist1[i], dist2[i])){
                t = max(dist1[i], dist2[i]);
                ans = i;
            }
        }
        return ans;
    }
};