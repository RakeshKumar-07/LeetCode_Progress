class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<pair<int,int>> col, row;
        for(int i=0;i<grid.size();i++){
            int ones = 0, zeros = 0;
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 0) zeros++;
                else ones++;
            }
            row.push_back({zeros, ones});
        }
        for(int i=0;i<grid[0].size();i++){
            int ones = 0, zeros = 0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i] == 0) zeros++;
                else ones++;
            }
            col.push_back({zeros, ones});
        }
        vector<vector<int>> ans;
        for(int i=0;i<row.size();i++){
            vector<int> t;
            for(int j=0;j<col.size();j++){
                t.push_back(col[j].second + row[i].second - col[j].first - row[i].first);
            }
            ans.push_back(t);
        }
        return ans;
    }
};