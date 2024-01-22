class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> f(nums.size()+1, 0);
        vector<int> ans(2);
        for(int i=0;i<nums.size();i++) f[nums[i]]++;
        for(int i=0;i<f.size();i++){
            if(f[i] == 2) ans[0] = i;
            if(f[i] == 0) ans[1] = i;
        }
        return ans;
    }
};