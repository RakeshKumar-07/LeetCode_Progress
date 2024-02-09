class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            for(int j=i;j>=0;j--){
                if(nums[i]%nums[j] == 0 && ans[j].size() >= ans[i].size()){
                    vector<int> t = ans[j];
                    t.push_back(nums[i]);
                    ans[i] = t;
                }
            }
        }
        vector<int> res;
        for(int i=0;i<ans.size();i++) if(res.size() < ans[i].size()) res = ans[i];
        return res;
    }
};