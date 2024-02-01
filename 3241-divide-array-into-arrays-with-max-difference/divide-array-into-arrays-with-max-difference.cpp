class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size()/3, i = 0;
        while(i<n){
            if(abs(nums[i*3+1] - nums[i*3]) <= k && abs(nums[i*3+2] - nums[i*3]) <= k && abs(nums[i*3+1] - nums[i*3+2]) <= k) ans.push_back({nums[i*3], nums[i*3+1], nums[i*3+2]});
            else break;
            i++;
        }
        if(ans.size() != n) return {};
        return ans;
    }
};