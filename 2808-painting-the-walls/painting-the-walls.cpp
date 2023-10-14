class Solution {
public:
    long long dp[501][501];

    long long solve(int i, int n, int m, vector<int>& cost, vector<int>& time){
        if(m<=0){
            return 0;
        }
        if(i==n){
            return INT_MAX;
        }
        if(dp[i][m] != -1) return dp[i][m];
        return dp[i][m] = min(cost[i] + solve(i+1, n, m-time[i]-1, cost, time), solve(i+1, n, m, cost, time));
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp, -1, sizeof(dp));
        long long ans = solve(0, cost.size(), cost.size(), cost, time);
        return ans;    
    }
};