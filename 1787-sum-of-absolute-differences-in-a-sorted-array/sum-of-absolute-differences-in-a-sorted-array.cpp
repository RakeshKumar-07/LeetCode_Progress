class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum, ans;
        sum.push_back(nums[0]);
        for(int i=1;i<n;i++) sum.push_back(sum[i-1] + nums[i]);
        for(int i=0;i<n;i++) ans.push_back((nums[i]*(i+1) - sum[i]) + ((sum[n-1] - sum[i]) - nums[i]*(n-i-1)));
        return ans;
    }
};