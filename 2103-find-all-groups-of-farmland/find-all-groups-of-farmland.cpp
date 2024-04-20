class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        // cout<<land.size()<<" "<<land[0].size();
        vector<vector<int>> ans;
        vector<vector<bool>> vis(land.size(), vector<bool>(land[0].size(), false));
        for(int i=0;i<land.size();i++){
            for(int j=0;j<land[i].size();j++){
                vector<int> t;
                if(land[i][j] == 1 && !vis[i][j]){
                    t.push_back(i);
                    t.push_back(j);
                    int r = INT_MIN, c = INT_MIN;
                    stack<pair<int,int>> s;
                    s.push({i,j});
                    vis[i][j] = true;
                    while(s.size() > 0){
                        pair<int,int> p = s.top();
                        s.pop();
                        r = max(p.first, r);
                        c = max(p.second, c);
                        if(p.first + 1 < land.size() && land[p.first + 1][p.second] == 1 && !vis[p.first + 1][p.second]){
                            s.push({p.first + 1, p.second});
                            vis[p.first + 1][p.second] = true;
                        }
                        if(p.second + 1 < land[0].size() && land[p.first][p.second + 1] == 1 && !vis[p.first][p.second + 1]){
                            s.push({p.first, p.second + 1});
                            vis[p.first][p.second + 1] = true;
                        }
                    }
                    t.push_back(r);
                    t.push_back(c);
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};