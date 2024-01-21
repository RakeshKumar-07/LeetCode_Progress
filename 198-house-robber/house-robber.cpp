class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        nums[n-3] += nums[n-1];
        for(int i=n-4;i>=0;i--) nums[i] += max(nums[i+2], nums[i+3]);
        return max(nums[0],nums[1]);
    }
};