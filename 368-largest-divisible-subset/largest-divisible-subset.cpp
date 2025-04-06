class Solution {
public:

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 0);
        vector<vector<int>> l(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            int maxDiv = 0, k = -1;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]%nums[i] == 0 && maxDiv <= dp[j]){
                    maxDiv = dp[j];
                    k = j;
                }
            }
            dp[i] = 1 + maxDiv;
            if(k != -1){
                for(int j=0;j<l[k].size();j++) l[i].push_back(l[k][j]);
            }
            l[i].push_back(nums[i]);
            // cout<<nums[i]<<" => "<<dp[i]<<" "<<l[i].size()<<"\n";
            // for(int j=0;j<l[i].size();j++) cout<<l[i][j]<<" ";
            // cout<<endl;
        }
        for(int i=0;i<nums.size();i++) if(ans.size() < l[i].size()) ans = l[i];
        reverse(ans.begin(), ans.end());
        return ans;
    }
};