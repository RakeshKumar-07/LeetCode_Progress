class Solution {
public:
    int dp[1001];
    
    long long solve(int i, int n, string s, vector<int> &f){
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        long long t = INT_MAX;
        
        for(int j=i;j<n;j++){
            
            f[s[j]-'a']++;
            
            int freq = f[s[j]-'a'];
            
            bool y = true;
            
            for(int k=0;k<26;k++) if(f[k] != 0 && f[k] != freq) y &= false; 
            
            if(y){
                vector<int> fTemp(26, 0);
                t = min(1 + solve(j+1, n, s, fTemp), t);
            }
        }
        
        return dp[i] = t;
    }
    
    int minimumSubstringsInPartition(string s) {
        vector<int> f(26, 0);
        memset(dp, -1, sizeof(dp));
        int ans = solve(0, s.size(), s, f);
        return ans;
    }
};