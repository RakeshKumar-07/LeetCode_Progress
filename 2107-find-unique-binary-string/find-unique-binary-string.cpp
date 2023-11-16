class Solution {
public:

    string solve(int i, int n, vector<string>& nums, string s, int prev){
        if(i==n){
            return s;
        }
        string t = s + '1';
        int count = 0;
        for(int j=0;j<n;j++){
            if(nums[i].substr(0,i+1) == t) count++;
        }
        if(count <= prev/2) return solve(i+1, n, nums, s + '1', prev);
        return solve(i+1, n, nums, s + '0', prev);
    }            

    string findDifferentBinaryString(vector<string>& nums) {
        string ans = solve(0, nums.size(), nums, "", nums.size());
        return ans;
    }
};