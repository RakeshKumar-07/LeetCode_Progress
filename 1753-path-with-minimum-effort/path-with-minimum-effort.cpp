class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        int dist[10001];
        for(int i=0;i<10001;i++) dist[i] = INT_MAX;
        int n = heights.size(), m = heights[0].size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,0,0});
        dist[0] = 0;
        while(!pq.empty()){
            vector<int> t = pq.top();
            pq.pop();
            if(t[1] + 1 < n && dist[(t[1] + 1)*m + t[2]] > max(dist[(t[1])*m + t[2]], abs(heights[t[1]][t[2]] - heights[t[1]+1][t[2]]))){
                dist[(t[1] + 1)*m + t[2]] = max(dist[(t[1])*m + t[2]], abs(heights[t[1]][t[2]] - heights[t[1]+1][t[2]]));
                pq.push({dist[(t[1] + 1)*m + t[2]], t[1] + 1, t[2]});
            }
            if(t[1] - 1 >= 0 && dist[(t[1] - 1)*m + t[2]] > max(dist[(t[1])*m + t[2]], abs(heights[t[1]][t[2]] - heights[t[1]-1][t[2]]))){
                dist[(t[1] - 1)*m + t[2]] = max(dist[(t[1])*m + t[2]], abs(heights[t[1]][t[2]] - heights[t[1]-1][t[2]]));
                pq.push({dist[(t[1] - 1)*m + t[2]], t[1] - 1, t[2]});
            }
            if(t[2] + 1 < m && dist[(t[1])*m + (t[2]+1)] > max(dist[(t[1])*m + t[2]] , abs(heights[t[1]][t[2]] - heights[t[1]][t[2]+1]))){
                dist[(t[1])*m + (t[2] + 1)] = max(dist[(t[1])*m + t[2]] , abs(heights[t[1]][t[2]] - heights[t[1]][t[2]+1]));
                pq.push({dist[(t[1])*m + (t[2] + 1)], t[1], t[2]+1});
            }
            if(t[2] - 1 >= 0 && dist[(t[1])*m + (t[2]-1)] > max(dist[(t[1])*m + t[2]], abs(heights[t[1]][t[2]] - heights[t[1]][t[2]-1]))){
                dist[(t[1])*m + (t[2] - 1)] = max(dist[(t[1])*m + t[2]], abs(heights[t[1]][t[2]] - heights[t[1]][t[2]-1]));
                pq.push({dist[(t[1])*m + (t[2] - 1)], t[1], t[2]-1});
            }
        }
        return dist[n*m - 1];
    }
};