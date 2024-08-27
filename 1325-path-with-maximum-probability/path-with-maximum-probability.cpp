class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> v(10001);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back({edges[i][1],succProb[i]});
            v[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> dist(10001,0); 
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        dist[start] = 1;
        while(!pq.empty()){
            pair<double,int> t = pq.top();
            pq.pop();
            for(int i=0;i<v[t.second].size();i++){
                if(dist[v[t.second][i].first] < t.first*v[t.second][i].second){
                    dist[v[t.second][i].first] = t.first*v[t.second][i].second;
                    pq.push({dist[v[t.second][i].first], v[t.second][i].first});
                }
            }
        }
        return dist[end];
    }
};