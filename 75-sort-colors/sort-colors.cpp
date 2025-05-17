class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r=0,w=0,b=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) r++;
            if(nums[i]==1) w++;
            if(nums[i]==2) b++;
        }
        int numsi = 0;
        for(int i=0;i<r;i++) nums[numsi++] = 0;
        for(int i=0;i<w;i++) nums[numsi++] = 1;
        for(int i=0;i<b;i++) nums[numsi++] = 2;
    }
};