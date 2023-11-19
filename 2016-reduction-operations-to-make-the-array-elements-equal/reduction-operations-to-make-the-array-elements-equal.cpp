class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, cnt = 0;
        for(int i=nums.size()-1;i>0;i--){
            cnt++;
            if(nums[i] != nums[i-1]){
                ans += cnt;
            }
        }
        return ans;
    }
};