class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p = 1, l = 0;
        long long ans = 0;
        for(int i=0;i<nums.size();i++){
            p *= nums[i];
            l++;
            while(p >= k && l > 0){
                p /= nums[i-l+1];
                l--;
            }
            cout<<i<<" => "<<l<<endl;
            ans += l;
        }
        return ans;
    }
};