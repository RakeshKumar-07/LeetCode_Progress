class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> exists(101, false);
        for(int i=nums.size()-1;i>=0;i--){
            if(exists[nums[i]]) return (i+1)/3 + ((i+1)%3 > 0);
            exists[nums[i]] = true;
        }
        return 0;
    }
};