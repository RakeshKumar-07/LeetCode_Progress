class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1, mini = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(mini > nums[i]){
                mini = nums[i];
                continue;
            }
            if(nums[i] != mini) ans = max(ans, nums[i]-mini);
        }
        return ans;
    }
};