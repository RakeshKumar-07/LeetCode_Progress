class Solution {
public:
    long long dp[51][51][51];
    long long M = 1000000007;

    int solve(int i, int j, int m, int n, int movesLeft){
        if(i == -1 || i == m || j == -1 || j == n) return 1;
        if(dp[i][j][movesLeft] != -1) return dp[i][j][movesLeft];
        long long t = 0;
        if(movesLeft > 0){
            t += solve(i+1, j, m, n, movesLeft-1);
            t += solve(i-1, j, m, n, movesLeft-1);
            t += solve(i, j+1, m, n, movesLeft-1);
            t += solve(i, j-1, m, n, movesLeft-1);
        }
        return dp[i][j][movesLeft] = t%M;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        return solve(startRow, startColumn, m, n, maxMove)%M;
    }
};