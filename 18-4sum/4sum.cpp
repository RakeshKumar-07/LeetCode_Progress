class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int p = j+1, q = nums.size()-1;
                while(p<q){
                    if((long long)nums[i]+nums[j]+nums[p]+nums[q] > target) q--;
                    else if((long long)nums[i]+nums[j]+nums[p]+nums[q] < target) p++;
                    else{
                        s.insert({nums[i],nums[j],nums[p],nums[q]});
                        p++;
                    }
                }
            }
        }
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};