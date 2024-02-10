class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;

        for(int i=0;i<s.size();i++){
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }
        }

        for(int i=1;i<s.size();i++){
            int l = i-1, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                ans++;
                l--;
                r++;
            }
        }

        return ans;
    }
};