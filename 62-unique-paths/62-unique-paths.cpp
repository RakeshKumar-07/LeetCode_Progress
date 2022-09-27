class Solution {
public:
    int dp[101][101];
    
    int findPath(int m, int n){
        if(m==0 && n==0){
            return 1;
        }
        if(dp[m][n] != -1)
            return dp[m][n];
        int totalWays = 0;
        if(m!=0) totalWays += findPath(m-1,n);
        if(n!=0) totalWays += findPath(m,n-1);
        return dp[m][n] = totalWays;
    }
    
    int uniquePaths(int m, int n){
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
                dp[i][j] = -1;
        return findPath(m-1,n-1);
    }
};