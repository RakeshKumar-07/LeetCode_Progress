class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> f1(26, 0), f2(26, 0);
        int ans = 0;
        for(int i=0;i<s.size();i++) f1[s[i]-'a']++;
        for(int i=0;i<t.size();i++) f2[t[i]-'a']++;
        for(int i=0;i<26;i++) ans += abs(f1[i] - f2[i]);
        return ans/2;
    }
};