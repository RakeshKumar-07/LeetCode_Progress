class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<long long> diff;
        long long lMax = nums[0], rMax = nums[nums.size()-1];
        for(int i=1;i<nums.size()-1;i++){
            diff.push_back(lMax - nums[i]);
            lMax = max(lMax, (long long)nums[i]);
        }
        long long ans = 0;
        for(int i=nums.size()-2;i>0;i--){
            ans = max(ans, diff[i-1]*rMax);
            rMax = max(rMax, (long long)nums[i]);
        }
        return ans;
    }
};