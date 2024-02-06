class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN, maxi = 0;
        for(int i=0;i<nums.size();i++){
            maxi += nums[i];
            ans = max(ans, maxi);
            if(maxi < 0) maxi = 0;
        }
        return ans;
    }
};