class Solution {
public:
    int dp[301][11];

    long long solve(int i, int n, vector<int>& jobDifficulty, int d){
        if(i==n && d==0) return 0;
        if((i!=n && d==0) || (i==n && d!=0)) return INT_MAX;
        if(dp[i][d] != -1) return dp[i][d];
        long long ans = INT_MAX, m = INT_MIN;
        for(int j=i;j<n;j++){
            m = max((long long)jobDifficulty[j], m);
            ans = min(m + solve(j+1, n, jobDifficulty, d-1), ans);
        }
        return dp[i][d] = ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(d > jobDifficulty.size()) return -1;
        memset(dp, -1, sizeof(dp));
        return solve(0, jobDifficulty.size(), jobDifficulty, d);
    }
};