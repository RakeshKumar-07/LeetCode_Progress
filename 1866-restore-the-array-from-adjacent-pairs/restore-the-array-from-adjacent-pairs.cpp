class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> m;
        int start;
        for(int i=0;i<adjacentPairs.size();i++){
            m[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            m[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        for(auto i:m) if(i.second.size() == 1) start = i.first;
        vector<bool> vis(200001, false);
        vector<int> ans;

        while(!vis[start + 100000]){
            ans.push_back(start);
            vis[start + 100000] = true;
            for(int i=0;i<m[start].size();i++){
                if(!vis[m[start][i] + 100000]){
                    start = m[start][i];
                    break;
                }
            }
        }        
        return ans;
    }
};