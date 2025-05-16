class Solution {
public:
    int dp[1001];
    int child[1001];

    bool diffOne(string &a, string &b){
        int t = 0;
        if(a.size() != b.size()) return false;
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i]) t++;
        }
        return t == 1 ? true : false;
    }

    int solve(int i, int n, vector<string>& words, vector<int>& groups){
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int res = 0;
        for(int j=i+1;j<n;j++){
            if(diffOne(words[i], words[j]) && groups[i] != groups[j]){
                int t = solve(j, n, words, groups);
                if(t > res){
                    res = t;
                    child[i] = j;
                }
            }
        }
        return dp[i] = res + 1;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        memset(dp, -1, sizeof(dp));
        memset(child, -1, sizeof(child));
        for(int i=0;i<words.size();i++) solve(i, words.size(), words, groups);
        int maxi = INT_MIN, j = -1;
        for(int i=0;i<words.size();i++){
            if(maxi < dp[i]){
                maxi  = dp[i];
                j = i;
            }
        }
        vector<string> ans;
        ans.push_back(words[j]);
        while(child[j] != -1){
            ans.push_back(words[child[j]]);
            j = child[j];
        }
        return ans;
    }
};