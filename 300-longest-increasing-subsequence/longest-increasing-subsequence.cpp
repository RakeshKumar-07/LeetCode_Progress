class Solution {
public:
    int dp[2501];

    int solve(int i, int n, vector<int>& nums, int prev){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
        int t = 0;
        for(int j=i;j<n;j++) if(nums[j] > prev) t = max(t, 1 + solve(j+1,n,nums,nums[j]));
        return dp[i] = t;
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums.size(), nums, -10001);
    }
};