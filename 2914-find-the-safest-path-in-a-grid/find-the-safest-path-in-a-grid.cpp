class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        if(grid[0][0] == 1 || grid[grid.size()-1][grid[0].size()-1] == 1) return 0;
        vector<pair<int,int>> ones;
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
        for(int i=0;i<grid.size();i++) for(int j=0;j<grid[i].size();j++) if(grid[i][j] == 1) ones.push_back({i, j});
        int temp = INT_MAX, ans = 0;

        for(int i=0;i<ones.size();i++) temp = min(abs(ones[i].first) + abs(ones[i].second), temp);

        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({temp, {0,0}});
        vis[0][0] = true;
        while(pq.size() > 0){
            int s = pq.size();
            int res = INT_MAX;
            while(s--){
                pair<int,int> t = pq.top().second;
                int dist = pq.top().first;
                pq.pop();
                if(t.first == grid.size()-1 && t.second == grid[0].size()-1) ans = max(dist, ans);
                
                if(t.first + 1 < grid.size() && !vis[t.first + 1][t.second] && grid[t.first + 1][t.second] == 0){
                    int minDist = INT_MAX;
                    for(int i=0;i<ones.size();i++) minDist = min(abs(ones[i].first - t.first - 1) + abs(ones[i].second - t.second), minDist);
                    pq.push({min(minDist, dist), {t.first + 1, t.second}});
                    vis[t.first + 1][t.second] = true;
                }

                if(t.first - 1 >= 0 && !vis[t.first - 1][t.second] && grid[t.first - 1][t.second] == 0){
                    int minDist = INT_MAX;
                    for(int i=0;i<ones.size();i++) minDist = min(abs(ones[i].first - t.first + 1) + abs(ones[i].second - t.second), minDist);
                    pq.push({min(minDist, dist), {t.first - 1, t.second}});
                    vis[t.first - 1][t.second] = true;
                }

                if(t.second + 1 < grid[0].size() && !vis[t.first][t.second + 1] && grid[t.first][t.second + 1] == 0){
                    int minDist = INT_MAX;
                    for(int i=0;i<ones.size();i++) minDist = min(abs(ones[i].first - t.first) + abs(ones[i].second - t.second - 1), minDist);
                    pq.push({min(minDist, dist), {t.first, t.second + 1}});
                    vis[t.first][t.second + 1] = true;
                }

                if(t.second - 1 >= 0 && !vis[t.first][t.second - 1] && grid[t.first][t.second - 1] == 0){
                    int minDist = INT_MAX;
                    for(int i=0;i<ones.size();i++) minDist = min(abs(ones[i].first - t.first) + abs(ones[i].second - t.second + 1), minDist);
                    pq.push({min(minDist, dist), {t.first, t.second - 1}});
                    vis[t.first][t.second - 1] = true;
                }
            }
        }
        return ans;
    }
};