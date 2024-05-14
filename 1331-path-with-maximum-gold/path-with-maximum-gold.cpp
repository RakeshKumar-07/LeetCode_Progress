class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<bool>> &f, vector<vector<int>>& grid){
        int t = 0;
        if(i+1 < m && !f[i+1][j] && grid[i+1][j]){
            f[i+1][j] = true;
            t = max(t, grid[i+1][j] + solve(i+1, j, m, n, f, grid));
            f[i+1][j] = false;
        }
        if(i-1 >= 0 && !f[i-1][j] && grid[i-1][j]){
            f[i-1][j] = true;
            t = max(t, grid[i-1][j] + solve(i-1, j, m, n, f, grid));
            f[i-1][j] = false;
        }
        if(j+1 < n && !f[i][j+1] && grid[i][j+1]){
            f[i][j+1] = true;
            t = max(t, grid[i][j+1] + solve(i, j+1, m, n, f, grid));
            f[i][j+1] = false;
        }
        if(j-1 >= 0 && !f[i][j-1] && grid[i][j-1]){
            f[i][j-1] = true;
            t = max(t, grid[i][j-1] + solve(i, j-1, m, n, f, grid));
            f[i][j-1] = false;
        }
        return t;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<bool>> f(grid.size(), vector<bool>(grid[0].size(), false));
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]){
                    f[i][j] = true;
                    ans = max(ans, grid[i][j] + solve(i, j, grid.size(), grid[i].size(), f, grid));
                    f[i][j] = false;
                }
            }
        }
        return ans;
    }
};