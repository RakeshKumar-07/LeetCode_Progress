class Solution {
public:
    int dp[10001];

    int solve(int n){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int t = INT_MAX;
        for(int i=sqrt(n);i>0;i--) t = min(1 + solve(n-i*i), t);
        return dp[n] = t;
    }

    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};