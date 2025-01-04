class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>> freq(s.size(), vector<int>(26, 0));
        vector<pair<int,int>> v(26, {INT_MAX, INT_MIN});
        for(int i=0;i<s.size();i++){
            v[s[i] - 'a'].first = min(i, v[s[i] - 'a'].first);
        }
        for(int i=s.size()-1;i>=0;i--){
            v[s[i] - 'a'].second = max(i, v[s[i] - 'a'].second);
        }
        for(int i=1;i<s.size();i++){
            freq[i] = freq[i-1];
            freq[i][s[i-1]-'a']++;
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(v[i].first != INT_MAX && v[i].first != v[i].second){
                int t = 0, s = v[i].first + 1, e = v[i].second;
                for(int j=0;j<26;j++){
                    if(freq[e][j] - freq[s][j] > 0) t++;
                }
                ans += t;
            }
        }
        return ans;
    }
};