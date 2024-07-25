class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> count(1000001, 0);
        for(int i=0;i<nums.size();i++) count[50000 + nums[i]]++;
        nums.clear();
        for(int i=0;i<1000001;i++) while(count[i]--) nums.push_back(i-50000);
        return nums;
    }
};