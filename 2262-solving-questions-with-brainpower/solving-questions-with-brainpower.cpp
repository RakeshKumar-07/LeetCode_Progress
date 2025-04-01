class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> dp(questions.size(), -1);
        long long ans = 0;
        for(int i=questions.size()-1;i>=0;i--){
            if(i + questions[i][1] + 1 >= questions.size()) dp[i] = max(ans, (long long)questions[i][0]);
            else dp[i] = max(ans, questions[i][0] + dp[i+questions[i][1]+1]);
            ans = max(dp[i], ans);
        }
        // for(int i=0;i<dp.size();i++) cout<<dp[i]<<" ";
        return ans;
    }
};