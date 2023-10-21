class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int ans = nums[nums.size()-1];
        priority_queue<pair<int,int>> pq;
        pq.push({nums[nums.size()-1], nums.size()-1});
        for(int i=nums.size()-2;i>=0;i--){
            while(pq.top().second - i > k) pq.pop();
            nums[i] = max(nums[i] + pq.top().first, nums[i]);
            pq.push({nums[i], i});
            ans = max(ans,nums[i]);
        }
        return ans;
    }
};