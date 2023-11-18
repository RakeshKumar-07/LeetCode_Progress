class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long ans = INT_MIN, window = 0, size = 0;
        for(int i=0;i<nums.size();i++){
            window += nums[i];
            size++;
            while(nums[i]*size - window > k){
                window -= nums[i-size+1];
                size--;
            }
            ans = max(size, ans);
        }
        return ans;
    }
};