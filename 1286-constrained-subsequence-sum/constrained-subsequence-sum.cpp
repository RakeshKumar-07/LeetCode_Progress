class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans = INT_MIN;
        int dp[nums.size()];
        dp[nums.size()-1] = nums[nums.size()-1];
        priority_queue<pair<int,int>> pq;
        pq.push({nums[nums.size()-1], nums.size()-1});
        for(int i=nums.size()-2;i>=0;i--){
            while(pq.top().second - i > k) pq.pop();
            dp[i] = max(nums[i] + pq.top().first, nums[i]);
            pq.push({dp[i], i});
        }
        for(int i=0;i<nums.size();i++) ans = max(ans,dp[i]);
        return ans;
    }
};