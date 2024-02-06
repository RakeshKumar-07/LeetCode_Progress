class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> t = nums;
        sort(t.rbegin(), t.rend());
        if(nums == t) {
            sort(nums.begin(), nums.end());
            return;
        }
        int l = -1, r = -1;
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i] > nums[i-1]){
                l = i-1;
                break;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i] > nums[l]){
                r = i;
                break;
            }
        }
        swap(nums[l], nums[r]);
        reverse(nums.begin()+l+1, nums.end());
    }
};