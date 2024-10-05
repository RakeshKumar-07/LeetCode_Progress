class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> m(26,0), t(26,0);
        for(int i=0;i<s1.length();i++) m[s1[i] - 'a']++;
        for(int i=0;i<s1.length();i++) t[s2[i] - 'a']++;
        if(t == m) return true;
        for(int i=s1.length();i<s2.length();i++){
            t[s2[i-s1.length()] - 'a']--;
            t[s2[i] - 'a']++;
            if(t == m) return true;
        }
        return false;
    }
};