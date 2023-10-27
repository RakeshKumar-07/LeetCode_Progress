class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        for(int i=0;i<s.size();i++){
            int p = i-1, q = i+1;
            string t = "";
            t += s[i];
            while(p>=0 && q<s.size() && s[p] == s[q]){
                t = s[p] + t + s[q];
                p--;
                q++;
            }
            if(ans.size() < t.size()) ans = t;
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i] == s[i+1]){
                int p = i-1, q = i+2;
                string t = "";
                t += s[i];
                t += s[i+1];
                while(p>=0 && q<s.size() && s[p] == s[q]){
                    t = s[p] + t + s[q];
                    p--;
                    q++;
                }
                if(ans.size() < t.size()) ans = t;
            }
        }
        return ans;
    }
};