class Solution {
public:
    int maxDifference(string s) {
        vector<int> f(26,0);
        int odd = 0, even = 101;
        for(int i=0;i<s.size();i++) f[s[i]-'a']++;
        for(int i=0;i<s.size();i++){
            if(f[s[i]-'a']%2==1) odd = max(odd, f[s[i]-'a']);
            else even = min(even, f[s[i]-'a']);
        }
        return odd - even;
    }
};