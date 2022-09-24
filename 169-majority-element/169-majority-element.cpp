class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(1);
        }
        for(auto i:mp){
            if(i.second.size()>nums.size()/2){
                return i.first;
            }
        }
        return 0;
    }
};