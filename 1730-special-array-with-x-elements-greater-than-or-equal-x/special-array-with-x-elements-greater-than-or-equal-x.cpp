class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<=1000;i++){
            for(int j=0;j<nums.size();j++){
                if(nums[j] >= i){
                    if(nums.size() - j == i) return i;
                    break;
                }
            }
        }
        return -1;
    }
};