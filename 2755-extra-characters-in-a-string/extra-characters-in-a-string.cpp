class Solution {
public:
    int dp[51];

    int solve(int i, int n, string s, vector<string>& dictionary){
        if(i==n){
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int yes = INT_MAX, no = INT_MAX;
        for(int k=0;k<dictionary.size();k++){
            if(dictionary[k].size() <= (n-i) && dictionary[k] == s.substr(i, dictionary[k].size())){
                yes = min(solve(i + dictionary[k].size(), n, s, dictionary), yes);
            }
        }
        no = 1 + solve(i+1, n, s, dictionary);
        
        return dp[i] = min(yes,no);
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, s.size(), s, dictionary);
        return ans;
    }
};