class Solution {
public:
    long long ans = 0;
    void solve(int i, int n, vector<int>& nums, int x){
        if(i == n){
            ans += x;
            return;
        }
        solve(i+1, n, nums, x^nums[i]);
        solve(i+1, n, nums, x);
    }
    int subsetXORSum(vector<int>& nums) {
        solve(0, nums.size(), nums, 0);
        return ans;
    }
};