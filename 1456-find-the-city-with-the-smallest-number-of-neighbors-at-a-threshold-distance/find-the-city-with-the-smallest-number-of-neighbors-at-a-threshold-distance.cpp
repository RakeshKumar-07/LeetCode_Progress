class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> dist(n, vector<long long>(n, INT_MAX));
        for(int i=0;i<n;i++) dist[i][i] = 0;
        for(int i=0;i<edges.size();i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    dist[j][k] = min(dist[i][j] + dist[i][k], dist[j][k]);
                    dist[k][j] = dist[j][k];
                }
            }
        }
        int ans = -1, maxCnt = INT_MAX;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++) if(dist[i][j] <= distanceThreshold) cnt++;
            if(cnt <= maxCnt){
                ans = i;
                maxCnt = cnt;
            }
        }
        return ans;
    }
};