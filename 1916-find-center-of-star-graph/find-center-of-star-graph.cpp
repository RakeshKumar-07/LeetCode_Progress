class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> connections(edges.size()+1, 0);
        int ans;
        for(int i=0;i<edges.size();i++){
            connections[edges[i][0]-1]++;
            connections[edges[i][1]-1]++;
            if(connections[edges[i][0]-1] == edges.size()) ans = edges[i][0];
            if(connections[edges[i][1]-1] == edges.size()) ans = edges[i][1];
        }
        return ans;
    }
};