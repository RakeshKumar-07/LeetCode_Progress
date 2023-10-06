class Solution {
public:
    int dp[59];

    int solve(int n){
        if(n == 0){
            return 1;
        }
        if(dp[n] != -1) return dp[n];
        int t = INT_MIN;
        for(int i=1;i<=n;i++) t = max(t, i*solve(n-i));
        return dp[n] = t;
    }

    int integerBreak(int n) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(n);
        if(n==2 || n==3) return n-1;
        return ans;
    }
};