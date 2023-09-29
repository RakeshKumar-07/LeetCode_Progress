class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> v = nums;
        sort(nums.begin(), nums.end());
        if(nums == v) return true;
        sort(nums.begin(), nums.end(), greater<int>());
        if(nums == v) return true;
        return false;
    }
};