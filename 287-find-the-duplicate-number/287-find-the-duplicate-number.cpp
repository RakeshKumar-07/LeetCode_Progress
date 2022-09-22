class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(1);
        }
        int ans;
        for(auto i:mp){
            if(i.second.size() >= 2){
                ans = i.first;
            }
        }
        return ans;
    }
};