class Solution {
public:
    int dp[71][71][71];

    int solve(int l, int j1, int j2, int row, int col, vector<vector<int>>& grid){
        if(l == row) return 0;
        if(dp[l][j1][j2] != -1) return dp[l][j1][j2];
        int t = 0;
        for(int i=-1;i<2;i++)
            if(j1 + i < col && j1 + i >= 0)
                for(int j=-1;j<2;j++)
                    if(j2 + j < col && j2 + j >= 0 && j1+i != j2 + j)
                        t = max(grid[l][j1] + grid[l][j2] + solve(l+1, j1+i, j2+j, row, col, grid), t);
        return dp[l][j1][j2] = t;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, grid[0].size()-1, grid.size(), grid[0].size(), grid);
    }
};