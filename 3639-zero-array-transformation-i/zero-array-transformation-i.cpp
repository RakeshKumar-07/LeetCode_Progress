class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> v(nums.size()+1, 0);
        for(int i=0;i<queries.size();i++){
            v[queries[i][0]]--;
            v[queries[i][1]+1]++;
        }
        int currSum = 0;
        for(int i=0;i<nums.size();i++){
            currSum += v[i];
            if(currSum + nums[i] > 0) return false;
        }
        return true;
    }
};