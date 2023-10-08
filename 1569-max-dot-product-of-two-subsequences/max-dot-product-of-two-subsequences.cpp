class Solution {
public:
    int dp[501][501];

    int solve(int i, int j, int n, int m, vector<int>& nums1, vector<int>& nums2){
        if(i == n || j == m){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int t = INT_MIN;
        for(int k=j;k<m;k++){
            t = max({t, solve(i+1, j, n, m, nums1, nums2), nums1[i]*nums2[k] + solve(i+1, k+1, n, m, nums1, nums2)});
        }
        return dp[i][j] = t;
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, 0, nums1.size(), nums2.size(), nums1, nums2);
        if(ans == 0){
            int maxi = INT_MIN;
            for(int i=0;i<nums1.size();i++){
                for(int j=0;j<nums2.size();j++){
                    maxi = max(maxi, nums1[i]*nums2[j]);
                }
            }
            return maxi;
        }
        return ans;
    }
};