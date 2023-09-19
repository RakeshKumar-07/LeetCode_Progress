class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int vis[100002];
        for(int i=0;i<100002;i++) vis[i] = 0;
        for(int i=0;i<nums.size();i++){
            if(vis[nums[i]] == 1) return nums[i];
            vis[nums[i]] = 1;
        }
        return -1;
    }
};