class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int> exist(101, false);
        for(int i=0;i<nums.size();i++) exist[nums[i]] = true;
        int ans = 0;
        for(int i=0;i<101;i++){
            if(i<k && exist[i]) return -1;
            else if(i>k && exist[i]) ans++;
        }
        return ans;
    }
};