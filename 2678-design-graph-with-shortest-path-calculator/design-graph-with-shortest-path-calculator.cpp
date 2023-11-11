class Graph {
public:
    vector<vector<pair<int,int>>> graph;
    Graph(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        graph[edge[0]].push_back({edge[1], edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<long long> dist(101, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, node1});
        dist[node1] = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            for(int i=0;i<graph[u].size(); i++){
                int v = graph[u][i].first;
                int w = graph[u][i].second;
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[node2] == INT_MAX ? -1 : dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */