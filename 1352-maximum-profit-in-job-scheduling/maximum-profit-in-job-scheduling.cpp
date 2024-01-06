class Solution {
public:
    int dp[50001];
    
    int maxProfit(vector<vector<int>>& Job, int i, vector<int>& startTime){
        if(i == Job.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int index = lower_bound(startTime.begin(),startTime.end(),Job[i][1])-startTime.begin();
        return dp[i] = max(maxProfit(Job, index, startTime) + Job[i][2] , maxProfit(Job, i+1, startTime));
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> Job;
        int n = startTime.size();
        for(int i=0;i<n;i++){
            Job.push_back({startTime[i], endTime[i], profit[i]});
        }
        cout<<Job.size()<<endl;
        sort(Job.begin(), Job.end());
        sort(startTime.begin(), startTime.end());
        return maxProfit(Job, 0, startTime);
         
    }
};