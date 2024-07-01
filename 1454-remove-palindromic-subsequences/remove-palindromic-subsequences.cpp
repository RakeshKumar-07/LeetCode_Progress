class Solution {
public:
    int removePalindromeSub(string s) {
        bool ans = true;
        for(int i=0;i<s.size()/2;i++) if(s[i] != s[s.size()-1-i]) ans &= false;
        return ans ? 1 : 2;
    }
};