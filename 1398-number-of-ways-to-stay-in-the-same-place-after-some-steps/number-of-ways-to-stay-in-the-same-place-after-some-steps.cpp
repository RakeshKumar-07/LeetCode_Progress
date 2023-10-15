class Solution {
public:
    long long dp[501][501];
    long long M = 1000000007;

    long long solve(int i, int steps, int idx, int arrLen){
        if(i==steps){
            if(idx == 0) return 1;
            return 0;
        }
        if(dp[i][idx] != -1) return dp[i][idx];
        long long t = 0;
        if(idx + 1 < arrLen) t += solve(i+1, steps, idx+1, arrLen);
        t %= M;
        if(idx - 1 >= 0) t += solve(i+1, steps, idx-1, arrLen);
        t %= M;
        t += solve(i+1, steps, idx, arrLen);
        t %= M;

        return dp[i][idx] = t%M;
    }

    int numWays(int steps, int arrLen) {
        memset(dp, -1, sizeof(dp));
        long long ans = solve(0, steps, 0, arrLen);
        return ans;
    }
};