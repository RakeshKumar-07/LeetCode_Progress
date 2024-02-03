class Solution {
public:
    long long dp[501];

    long long solve(int i, int n, vector<int>& arr, int k){
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        long long t = 0, maxi = 0;
        for(int j=i;j<min(i+k, n);j++){
            maxi = max(maxi, (long long)arr[j]);
            t = max(maxi*(j-i+1) + solve(j+1, n, arr, k), t);
        }
        return dp[i] = t;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(0, arr.size(), arr, k);
    }
};