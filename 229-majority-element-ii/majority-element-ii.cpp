class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(1);
        }
        for(auto i:mp){
            if(i.second.size()>nums.size()/3){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};