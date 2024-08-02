class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        for(int i=0;i<n;i++) nums.push_back(nums[i]);
        int ans = INT_MIN, currSum = 0;
        for(int i=0;i<sum;i++) if(nums[i] == 1) currSum++;
        for(int i=sum;i<2*n;i++){
            if(nums[i] == 1) currSum++;
            if(nums[i-sum] == 1) currSum--;
            ans = max(currSum, ans);
        }
        return sum-ans;
    }
};