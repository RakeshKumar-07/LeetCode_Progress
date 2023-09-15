class Solution {
public:

    int find(int a, vector<int> &parent){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a], parent);
    }

    void _Union(int a, int b, vector<int> &parent){
        int pa = find(a, parent);
        int pb = find(b, parent);
        parent[pb] = pa;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        // cout<<points.size()<<endl;
        vector<int> parent(1001);
        for(int i=0;i<1001;i++) parent[i] = i;
        map<pair<int,int>,int> m;
        for(int i=0;i<points.size();i++){
            m[{points[i][0], points[i][1]}] = i;
        }
        vector<vector<int>> edges;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                edges.push_back({abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]), m[{points[i][0], points[i][1]}], m[{points[j][0], points[j][1]}]});
            }
        }
        sort(edges.begin(),edges.end());
        int ans = 0;
        for(int i=0;i<edges.size();i++){
            if(find(edges[i][1], parent) != find(edges[i][2], parent)){
                ans += edges[i][0];
                _Union(edges[i][1], edges[i][2], parent);
            }
        }
        return ans;
    }
};