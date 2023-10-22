class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int> left(nums.size()), right(nums.size());
        stack<pair<int,int>> l, r;
        for(int i=0;i<nums.size();i++){
            if(l.size() == 0){
                left[i] = i;
                l.push({nums[i], i});
            }
            else{
                int ans = i;
                while(l.size() > 0 && l.top().first >= nums[i]){
                    ans = left[l.top().second];
                    l.pop();
                }
                l.push({nums[i], i});
                left[i] = ans;
            }
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(r.size() == 0){
                right[i] = i;
                r.push({nums[i], i});
            }
            else{
                int ans = i;
                while(r.size() > 0 && r.top().first >= nums[i]){
                    ans = right[r.top().second];
                    r.pop();
                }
                r.push({nums[i], i});
                right[i] = ans;
            }
        }
        int res = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(left[i] <= k && k<=right[i]) res = max(nums[i]*(right[i]-left[i]+1), res);
        }
        return res;
    }
};