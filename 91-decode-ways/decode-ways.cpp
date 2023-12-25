class Solution {
public:
    int dp[101];

    int solve(int i, int n, string s){
        if(i==n) return 1;
        if(dp[i] != -1) return dp[i];
        int t = 0;
        if(s[i] != '0') t += solve(i+1, n, s);
        if(i<n-1 && stoi(s.substr(i,2)) <= 26 && stoi(s.substr(i,2)) >= 10) t+= solve(i+2, n, s);
        return dp[i] = t;
    }

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, s.size(), s);
        return ans;
    }
};